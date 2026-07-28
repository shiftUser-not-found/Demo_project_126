#include <stdio.h>
#include <assert.h>
#include "gpa.h"
#include "courseResult.h"

void testCGPA()
{
    Course courses[] = {
        {"CSE101", "Structured Programming", 3.0, 1},
        {"CSE102", "Data Structures", 3.0, 1}
    };

    CourseResult results[] = {
        createCompletedCourseResult(&courses[0], 240),
        createCompletedCourseResult(&courses[1], 250)
    };

    double gpa = calculateGPA(results, 2);
    assert(gpa > 0.0);
    printf("testCGPA passed\n");
}

void testGradePoint()
{
    Course course = {"CSE101", "Structured Programming", 3.0, 1};
    CourseResult result = createCompletedCourseResult(&course, 240);

    double gp = calculateGradePoint(result);
    assert(gp >= 0.0 && gp <= 4.0);
    printf("testGradePoint passed\n");
}

void testLetterGrade()
{
    Course course = {"CSE101", "Structured Programming", 3.0, 1};
    CourseResult result = createCompletedCourseResult(&course, 105);

    char grade[3];
    getLetterGrade(result, grade);
    assert(grade[0] != '\0');
    printf("testLetterGrade passed\n");
}

int main()
{
    testCGPA();
    testGradePoint();
    testLetterGrade();

    return 0;
}