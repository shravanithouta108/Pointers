#include <stdio.h>

int main() {
    int n, subjects;
    int i, j;

    /* Dynamic input */
    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    /* 1-D array for one subject marks */
    int marks[n];
    int *p = marks;   // pointer to 1-D array

    printf("\nEnter marks of students in Mathematics:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", (p + i));   // pointer arithmetic
    }

    /* Pointer expression and average calculation */
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += *(p + i);        // pointer expression
    }

    printf("\nAverage Mathematics Marks: %.2f\n", (float)sum / n);

    /* 2-D array for multiple subjects */
    int allMarks[n][subjects];
    int *ptr2D = &allMarks[0][0];  // pointer to 2-D array

    printf("\nEnter marks of %d students in %d subjects:\n", n, subjects);
    for (i = 0; i < n; i++) {
        for (j = 0; j < subjects; j++) {
            printf("Student %d Subject %d: ", i + 1, j + 1);
            scanf("%d", (ptr2D + i * subjects + j));
        }
    }

    /* Total marks per student using pointers */
    printf("\n----- Student Performance Report -----\n");
    for (i = 0; i < n; i++) {
        int total = 0;
        for (j = 0; j < subjects; j++) {
            total += *(ptr2D + i * subjects + j);
        }
        printf("Student %d Total Marks = %d\n", i + 1, total);
    }

    /* Finding topper using pointer logic */
    int maxTotal = 0, topper = 0;
    for (i = 0; i < n; i++) {
        int total = 0;
        for (j = 0; j < subjects; j++) {
            total += *(ptr2D + i * subjects + j);
        }
        if (total > maxTotal) {
            maxTotal = total;
            topper = i + 1;
        }
    }

    printf("\nTopper is Student %d with %d marks\n", topper, maxTotal);

    return 0;
}
