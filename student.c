#include <stdio.h>
struct student
{
    char name[30];
    int age;
    char usn[10];
    float cgpa;
};
typedef struct student st;
int main()
{
    st s1[10];
    int n;
    printf("Enter Number of the students data you want to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Name: \n");
        scanf("%s",s1[i].name);
        printf("Enter the Age: \n");
        scanf("%d",&s1[i].age);
        printf("Enter the USN: \n");
        scanf("%s",s1[i].usn);
        printf("Enter the CGPA: \n");
        scanf("%f",&s1[i].cgpa);
        printf("----NEXT----\n");
    }
    
    for(int i=0;i<n;i++)
    {
        printf("--------STUDENT INFORMATION--------\n");
        printf("Student Name: %s\n",s1[i].name);
        printf("Student Age: %d\n",s1[i].age);
        printf("Student USN: %s\n",s1[i].usn);
        printf("Student CGPA: %f\n",s1[i].cgpa);
    }
}
