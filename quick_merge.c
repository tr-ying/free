#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int emp_no;
    int emp_salary;
};

typedef struct Employee Employee;

void merge(Employee arr[], int l, int m, int r, int *swapCount) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].emp_no <= R[j].emp_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*swapCount)++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Employee arr[], int l, int r, int *swapCount) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, swapCount);
        mergeSort(arr, m + 1, r, swapCount);

        merge(arr, l, m, r, swapCount);
    }
}

int partition(Employee arr[], int low, int high, int *swapCount) {
    Employee pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].emp_no < pivot.emp_no) {
            i++;
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swapCount)++;
        }
    }
    Employee temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swapCount)++;
    return (i + 1);
}

void quickSort(Employee arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);

        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

void displayEmployees(Employee arr[], int n) {
    printf("Sorted Employees List:\n");
    printf("Emp No.\t\tName\t\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\n", arr[i].emp_no, arr[i].employee_name, arr[i].emp_salary);
    }
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    printf("Enter Employee details:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter Employee No.: ");
        scanf("%d", &employees[i].emp_no);

        printf("Enter Employee Name: ");
        scanf("%s", employees[i].employee_name);

        printf("Enter Employee Salary: ");
        scanf("%d", &employees[i].emp_salary);
    }

    int swapCountMerge = 0;
    Employee mergeSortEmployees[n];
    memcpy(mergeSortEmployees, employees, sizeof(employees));

    mergeSort(mergeSortEmployees, 0, n - 1, &swapCountMerge);
    printf("\nMerge Sort:\nNumber of swaps: %d\n", swapCountMerge);
    displayEmployees(mergeSortEmployees, n);

    int swapCountQuick = 0;
    Employee quickSortEmployees[n];
    memcpy(quickSortEmployees, employees, sizeof(employees));

    quickSort(quickSortEmployees, 0, n - 1, &swapCountQuick);
    printf("\nQuick Sort:\nNumber of swaps: %d\n", swapCountQuick);
    displayEmployees(quickSortEmployees, n);

    return 0;
}
