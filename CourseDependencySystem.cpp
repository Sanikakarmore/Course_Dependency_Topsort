class CourseDependencySystem {
private:
    std::unordered_map<std::string, Course*> courses;

public:
    Course* getOrCreateCourse(std::string courseName) {
        if (courses.find(courseName) == courses.end()) {
            Course* newCourse = new Course(courseName);
            courses[courseName] = newCourse;
        }
        return courses[courseName];
    }

    void addPrerequisite(std::string courseName, std::string prerequisiteName) {
        Course* course = getOrCreateCourse(courseName);
        Course* prerequisite = getOrCreateCourse(prerequisiteName);
        course->prerequisites.push_back(prerequisite);
    }

    std::vector<Course*> topologicalSort() {
        std::unordered_map<Course*, int> indegree;
        std::queue<Course*> q;
        std::vector<Course*> sortedCourses;

        // Calculate indegree of each course
        for (auto& entry : courses) {
            Course* course = entry.second;
            indegree[course] = 0;
        }

        for (auto& entry : courses) {
            Course* course = entry.second;
            for (Course* prerequisite : course->prerequisites) {
                indegree[prerequisite]++;
            }
        }

        // Enqueue courses with indegree 0
        for (auto& entry : courses) {
            Course* course = entry.second;
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            Course* course = q.front();
            q.pop();
            sortedCourses.push_back(course);

            for (Course* nextCourse : course->prerequisites) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Check for cyclic dependencies
        if (sortedCourses.size() != courses.size()) {
            std::cout << "Error: Cyclic dependency exists in the course structure." << std::endl;
            return std::vector<Course*>();
        }

        return sortedCourses;
    }
};
