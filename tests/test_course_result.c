#include <stdio.h>
#include <assert.h>
#include "courseResult.h"

void testCompletedResult()
{
    Course course = {"CSE101", "Structured Programming", 3.0, 1};
    CourseResult result = createCompletedCourseResult(&course, 120);

    assert(result.is_completed == 1);
    printf("testCompletedResult passed\n");
}

void testCompletedMarks()
{
    Course course = {"CSE101", "Structured Programming", 3.0, 1};
    CourseResult result = createCompletedCourseResult(&course, 120);

    assert(result.marks == 120);
    printf("testCompletedMarks passed\n");
}

void testSortBySemester()
{
    Course courses[] = {
        {"CSE101", "Structured Programming", 3.0, 1},
        {"CSE102", "Data Structures", 3.0, 2}
    };

    CourseResult results[] = {
        createCompletedCourseResult(&courses[0], 210),
        createCompletedCourseResult(&courses[1], 240)
    };

    sortBySemester(results, 2);

    assert(results[0].course->semester == 1);
    assert(results[1].course->semester == 2);
    printf("testSortBySemester passed\n");
}

void testFilterBySemester()
{
    Course courses[] = {
        {"CSE101", "Structured Programming", 3.0, 1},
        {"CSE102", "Data Structures", 3.0, 2}
    };

    CourseResult results[] = {
        createCompletedCourseResult(&courses[0], 240),
        createCompletedCourseResult(&courses[1], 250)
    };

    CourseResult filtered[2];
    int count = 0;

    filterBySemester(results, 2, 1, filtered, &count);

    assert(count == 1);
    assert(filtered[0].course->semester == 1);
    printf("testFilterBySemester passed\n");
}

int main()
{
    testCompletedResult();
    testCompletedMarks();
    testSortBySemester();
    testFilterBySemester();

    return 0;
}