#include <stdio.h>

void identifyMisplacedElements(int arr[], int n) {
    int index1 = -1, index2 = -1;
    int misplacedElement1, misplacedElement2;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            if (index1 == -1) {
                index1 = i;
                misplacedElement1 = arr[i];
            } else {
                index2 = i + 1;
                misplacedElement2 = arr[i + 1];
                break;
            }
        }
    }

    printf("Misplaced elements: %d at index %d and %d at index %d\n", misplacedElement1, index1, misplacedElement2, index2);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");          // input: 6
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");            // input: 1 3 5 4 7 6
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    identifyMisplacedElements(arr, n);

    return 0;
}
