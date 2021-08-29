// Fig. 3.6: fig03_06.c
// Class average program with counter-controlled iteration.
#include <stdio.h>

int main(void)
{
    unsigned int students; // number of students
    unsigned int counter = 1; // number of grade to be enter next
    int grade = 0; // grade of one student
    int total = 0; // total number of grades

    printf("Enter number of students: ");
    scanf("%d", &students);
    printf("\n");

    // get and add the grades of all students
    while (counter <= students) {
        printf("Input grade: ");
        scanf("%d", &grade);
        total = total + grade;
        counter = counter + 1;
    }

    printf("\nTotal: %d\nStudents: %d\n", total, students);
    float average = (float) total / students;
    printf("Class Average: %.2f", average);
}