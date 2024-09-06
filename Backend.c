#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        printf("Enter employee details:\n");
        printf("ID: ");
        scanf("%d", &employees[employeeCount].id);
        printf("Name: ");
        scanf("%s", employees[employeeCount].name);
        printf("Salary: ");
        scanf("%f", &employees[employeeCount].salary);
        employeeCount++;
        printf("Employee added successfully!\n");
    } else {
        printf("Employee database is full.\n");
    }
}

void viewEmployees() {
    if (employeeCount > 0) {
        printf("Employee List:\n");
        printf("ID\tName\tSalary\n");
        for (int i = 0; i < employeeCount; i++) {
            printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
        }
    } else {
        printf("No employees found.\n");
    }
}

void searchEmployee() {
    if (employeeCount > 0) {
        int searchId;
        printf("Enter employee ID to search: ");
        scanf("%d", &searchId);

        int found = 0;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].id == searchId) {
                printf("Employee found:\n");
                printf("ID\tName\tSalary\n");
                printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Employee with ID %d not found.\n", searchId);
        }
    } else {
        printf("No employees found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
