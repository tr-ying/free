#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float CPI;
};

void heapify(struct Student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].rollNo > arr[largest].rollNo)
        largest = left;

    if (right < n && arr[right].rollNo > arr[largest].rollNo)
        largest = right;

    if (largest != i) {
        struct Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(struct Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        struct Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("-----------------------------------------------------\n");
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("-----------------------------------------------------\n");
        printf("Enter the name of Student %d: ",i+1);
        fflush(stdin);
        fgets(students[i].name, 50, stdin);
        printf("Enter the Roll No of Student %d: ", i+1);
        scanf("%d",&students[i].rollNo);
        printf("Enter the CPI of Student %d: ", i+1);
        scanf("%f",&students[i].CPI);
    }

    heapSort(students, n);
    printf("-----------------------------------------------------\n");
    printf("Sorted data based on Roll Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("-----------------------------------------------------\n");
        printf("Name: %sRoll No: %d\nCPI: %.2f\n", students[i].name, students[i].rollNo, students[i].CPI);
    }
    printf("-----------------------------------------------------\n");

    return 0;
}
