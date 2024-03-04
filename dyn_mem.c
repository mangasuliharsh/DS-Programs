#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float *marks;

    printf("Enter the number of marks: ");
    scanf("%d", &n);

    marks = (float *)malloc(n * sizeof(float));

    if (marks == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("Enter marks for %d students:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    printf("Entered marks for %d students:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: %f\n", i + 1, marks[i]);
    }
    char choice;
    printf("Do you want to enter marks for more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        int additionalStudents;
        printf("Enter the number of additional students: ");
        scanf("%d", &additionalStudents);
        marks = (float *)realloc(marks, (n + additionalStudents) * sizeof(float));

        if (marks == NULL)
        {
            printf("Memory reallocation failed. Exiting program.\n");
            return 1;
        }
        printf("Enter marks for additional %d students:\n", additionalStudents);
        for (int i = n; i < n + additionalStudents; i++)
        {
            printf("Student %d: ", i + 1);
            scanf("%f", &marks[i]);
        }

        printf("Entered marks for %d students:\n", n + additionalStudents);
        for (int i = 0; i < n + additionalStudents; i++)
        {
            printf("Student %d: %.2f\n", i + 1, marks[i]);
        }
    }
    free(marks);

    return 0;
}
