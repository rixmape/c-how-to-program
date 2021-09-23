// Fig. 6.22: fig06_22.c
// Two-dimensional array manipulations

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int set_of_grades[], size_t tests);
void print_array(const int grades[][EXAMS], size_t pupils, size_t tests);

// Function main begins program execution
int main(void) {
    // Initialize student grades for three students (rows)
    int student_grades[STUDENTS][EXAMS] = 
        { {77, 68, 86, 73},
          {96, 87, 89, 78},
          {70, 90, 86, 81} };

    // Output array student_grades
    puts("The array is:");
    print_array(student_grades, STUDENTS, EXAMS);

    // Determine smallest and largest grade values
    printf("\n\nLowest grade: %d\nHighest grade: %d\n",
            minimum(student_grades, STUDENTS, EXAMS),
            maximum(student_grades, STUDENTS, EXAMS));

    // Calculate average grade for each student
    for (size_t student = 0; student < STUDENTS; ++student) {
        printf("The average grade for student %u is %.2f\n",
                student, average(student_grades[student], EXAMS));
    }
}

// Find the minimum grade
int minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int low_grade = 100; // Initialize to highest possible grade

    // Loop through rows of grades
    for (size_t i = 0; i < pupils; ++i) {

        // Loop through columns of grades
        for (size_t j = 0; j < tests; ++j) {
            
            if (grades[i][j] < low_grade) {
                low_grade = grades[i][j];
            }
        }
    }

    return low_grade; // Return minimum grade
}

// Find the maximum grade
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int high_grade = 0; // Initialize to lowest possible grade

    // Loop through rows of grades
    for (size_t i = 0; i < pupils; ++i) {

        // Loop through columns of grades
        for (size_t j = 0; j < tests; ++j) {
            
            if (grades[i][j] > high_grade) {
                high_grade = grades[i][j];
            }
        }
    }

    return high_grade; // Return maximum grade
}

// Determine the average grade for a particular student
double average(const int set_of_grades[], size_t tests)
{
    int total = 0; // Sum of test grades

    // Total all grades for one student
    for (size_t i = 0; i < tests; ++i) {
        total += set_of_grades[i];
    }

    return (double) total / tests; // Average
}

// Print the array
void print_array(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    // Output column heads
    printf("%s", "                   [0] [1] [2] [3]");
    
    // Output grades in tabular format
    for (size_t i = 0; i < pupils; ++i) {

        // Output label for row
        printf("\nstudent_grades[%u]  ", i);

        // Output grades for one student
        for (size_t j = 0; j < tests; ++j) {
            printf("%-4d", grades[i][j]);
        }
    }
}