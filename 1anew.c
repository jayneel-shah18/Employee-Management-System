#include <stdio.h>

typedef struct emp
{
    char name[50];
    int id;
    int salary;
    char address[100];
} emp;

int main()
{
    emp employee[10], temp;
    while (1)
    {
        printf("\nWelcome to the system!\n");
        printf("What operation would you like to perform?");
        printf("\nPress 1 to add new details.");
        printf("\nPress 2 to remove details.");
        printf("\nPress 3 to sort the details.");
        printf("\nPress 4 to list details of all.");
        printf("\nPress 5 to exit.\n");
        int a;
        scanf("%d", &a);
        int n, i, id, index = -1, j;
        if (a == 1)
        {

            printf("How many entries would you like to enter?: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter the details of Employee %d\n", i + 1);
                printf("Name: ");
                scanf(" %[^\n]*c", employee[i].name);
                printf("ID: ");
                scanf("%d", &employee[i].id);
                printf("Salary: ");
                scanf("%d", &employee[i].salary);
                printf("Address: ");
                scanf(" %[^\n]*c", employee[i].address);
            }
            printf("\nEntries added successfully!\n");
        }
        else if (a == 2)
        {
            printf("Enter the ID to delete details: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++)
            {
                if (employee[i].id == id)
                {
                    index = i;
                    break;
                }
            }
            if (index != -1)
            {
                for (i = index; i < n - 1; i++)
                {
                    employee[i] = employee[i + 1];
                }
                n = n - 1;
                printf("\nDeleted Successfully!\n");
            }
            else
            {
                printf("\nThis ID doesnot exist!\n");
            }
        }
        else if (a == 3)
        {
            if (n != 0)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (employee[i].salary > employee[j].salary)
                        {
                            temp = employee[i];
                            employee[i] = employee[j];
                            employee[j] = temp;
                        }
                    }
                }
                printf("\nSuccessfully Sorted !\n"); //in ascending order of salaries
            }
            else
            {
                printf("\nNo Entries Exist\n");
            }
        }
        else if (a == 4)
        {
            if (n != 0)
            {
                printf("Details of the employees are: \n");
                for (i = 0; i < n; i++)
                {
                    printf("Details of Employee %d\n", i + 1);
                    printf("Name: %s\n", employee[i].name);
                    printf("ID: %d\n", employee[i].id);
                    printf("Salary: %d\n", employee[i].salary);
                    printf("Address: %s\n", employee[i].address);
                }
            }
            else
            {
                printf("\nNo entries exist!\n");
            }
        }
        else if (a == 5)
        {
            printf("Thank You for using the system!");
            break;
        }
        else
        {
            printf("\nEnter Correct Choice!\n");
        }
    }
}