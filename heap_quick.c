#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

typedef struct Student Student;

void swapStudents(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Student arr[], int n, int i, int *swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    if (largest != i) {
        swapStudents(&arr[i], &arr[largest]);
        (*swapCount)++;
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(Student arr[], int n, int *swapCount) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    for (int i = n - 1; i > 0; i--) {
        swapStudents(&arr[0], &arr[i]);
        (*swapCount)++;
        heapify(arr, i, 0, swapCount);
    }
}

int partition(Student arr[], int low, int high, int *swapCount) {
    Student pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].student_roll_no < pivot.student_roll_no) {
            i++;
            swapStudents(&arr[i], &arr[j]);
            (*swapCount)++;
        }
    }
    swapStudents(&arr[i + 1], &arr[high]);
    (*swapCount)++;
    return (i + 1);
}

void quickSort(Student arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);

        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

void displayStudents(Student arr[], int n) {
    printf("Sorted Students List:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\n", arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    printf("Enter Student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter Student Roll No.: ");
        scanf("%d", &students[i].student_roll_no);

        printf("Enter Student Name: ");
        scanf("%s", students[i].student_name);

        printf("Enter Student Total Marks: ");
        scanf("%d", &students[i].total_marks);
    }

    int swapCountHeap = 0;
    Student heapSortStudents[n];
    memcpy(heapSortStudents, students, sizeof(students));

    heapSort(heapSortStudents, n, &swapCountHeap);
    printf("\nHeap Sort:\nNumber of swaps: %d\n", swapCountHeap);
    displayStudents(heapSortStudents, n);

    int swapCountQuick = 0;
    Student quickSortStudents[n];
    memcpy(quickSortStudents, students, sizeof(students));

    quickSort(quickSortStudents, 0, n - 1, &swapCountQuick);
    printf("\nQuick Sort:\nNumber of swaps: %d\n", swapCountQuick);
    displayStudents(quickSortStudents, n);

    return 0;
}
