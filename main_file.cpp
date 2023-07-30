int main() {
    CourseDependencySystem courseSystem;

    // Add courses and their prerequisites
    courseSystem.addPrerequisite("Data Structures", "Programming Basics");
    courseSystem.addPrerequisite("Algorithms", "Data Structures");
    courseSystem.addPrerequisite("Advanced Algorithms", "Algorithms");
    courseSystem.addPrerequisite("Databases", "Programming Basics");
    courseSystem.addPrerequisite("Web Development", "Programming Basics");

    // Perform topological sorting
    std::vector<Course*> sortedCourses = courseSystem.topologicalSort();

    // Display the sorted courses
    if (!sortedCourses.empty()) {
        std::cout << "Courses in topological order:" << std::endl;
        for (Course* course : sortedCourses) {
            std::cout << "- " << course->name << std::endl;
        }
    }

    return 0;
}
