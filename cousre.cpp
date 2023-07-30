#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Course {
public:
    std::string name;
    std::vector<Course*> prerequisites;

    Course(std::string courseName) : name(courseName) {}
};
