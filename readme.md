# Course Dependency System using Topological Sorting - C++ Project

## Introduction
This C++ project aims to create a Course Dependency System using topological sorting to organize and manage courses effectively. The system ensures that all prerequisite courses are completed before enrolling in a particular course. This project provides a user-friendly command-line interface to add courses and their prerequisites and then performs topological sorting to determine the best course sequence.

## Features
1. Add courses with their respective prerequisites.
2. Perform topological sorting to obtain the best course sequence.
3. Handle cyclic dependencies and display appropriate error messages.
4. User-friendly command-line interface.

## Classes

1. `Course` class:
   - Represents a single course, including its name and a list of prerequisites.
   - Provides methods to construct the course and add prerequisites.

2. `CourseDependencySystem` class:
   - Manages the overall Course Dependency System.
   - Contains a container to store all courses and their dependencies.
   - Provides methods to add courses and prerequisites, and perform topological sorting.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/course-dependency-system.git
   cd course-dependency-system
