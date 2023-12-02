#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

typedef struct Student Student;

void merge(Student arr[], int l, int m, int r, int *swapCount) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Student L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
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

void mergeSort(Student arr[], int l, int r, int *swapCount) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, swapCount);
        mergeSort(arr, m + 1, r, swapCount);

        merge(arr, l, m, r, swapCount);
    }
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
        Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swapCount)++;
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(Student arr[], int n, int *swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    for (int i = n - 1; i > 0; i--) {
        Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swapCount)++;
        heapify(arr, i, 0, swapCount);
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

    int swapCountMerge = 0;
    Student mergeSortStudents[n];
    memcpy(mergeSortStudents, students, sizeof(students));

    mergeSort(mergeSortStudents, 0, n - 1, &swapCountMerge);
    printf("\nMerge Sort:\nNumber of swaps: %d\n", swapCountMerge);
    displayStudents(mergeSortStudents, n);

    int swapCountHeap = 0;
    Student heapSortStudents[n];
    memcpy(heapSortStudents, students, sizeof(students));

    heapSort(heapSortStudents, n, &swapCountHeap);
    printf("\nHeap Sort:\nNumber of swaps: %d\n", swapCountHeap);
    displayStudents(heapSortStudents, n);

    return 0;
}
