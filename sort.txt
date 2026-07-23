#include <stdio.h>

// Declare global variables for reuse
int a[50], n, steps = 0;
int i, j, temp, low, high, p, l, r, large;

// ---------------- QUICK SORT ----------------
void quicksort(int a[], int low, int high) {
    if (low < high) {
        i = low;
        p = a[low];
        j = high;
        while (i < j) {
            while (p >= a[i] && i <= high) {
                i++;
                steps++;
            }
            while (p < a[j] && j > low) {
                j--;
                steps++;
            }
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                steps++;
            }
        }
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        steps++;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

// ---------------- MERGE SORT ----------------
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0, b[50];
    while (i <= mid && j <= high) {
        steps++;
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= high) b[k++] = a[j++];
    for (i = 0; i < k; i++) {
        a[low + i] = b[i];
        steps++;
    }
}

void mergesort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// ---------------- HEAP SORT ----------------
void heapify(int a[], int n, int i) {
    l = 2 * i + 1;
    r = 2 * i + 2;
    large = i;

    if (l < n && a[l] > a[large]) {
        large = l;
        steps++;
    }
    if (r < n && a[r] > a[large]) {
        large = r;
        steps++;
    }
    if (large != i) {
        temp = a[large];
        a[large] = a[i];
        a[i] = temp;
        steps++;
        heapify(a, n, large);
    }
}

void maxheap(int a[], int n) {
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void heapsort(int a[], int n) {
    maxheap(a, n);
    for (i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        steps++;
        heapify(a, i, 0);
    }
}

// ---------------- INSERTION SORT ----------------
void insertionsort(int a[], int n) {
    int t;
    for (i = 1; i <= n - 1; i++) {
        t = a[i];
        j = i - 1;
        while (t < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j--;
            steps++;
        }
        a[j + 1] = t;
        steps++;
    }
}

// ---------------- MAIN ----------------
int main() {
    int original[50], choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &original[i]);
    }

    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Heap Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        // Reset array and step count
        steps = 0;
        for (i = 0; i < n; i++) {
            a[i] = original[i];  // Copy original array into a[]
        }

        switch (choice) {
            case 1:
                mergesort(a, 0, n - 1);
                printf("Sorted array (Merge Sort): ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\nSteps: %d\n", steps);
                break;

            case 2:
                quicksort(a, 0, n - 1);
                printf("Sorted array (Quick Sort): ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\nSteps: %d\n", steps);
                break;

            case 3:
                heapsort(a, n);
                printf("Sorted array (Heap Sort): ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\nSteps: %d\n", steps);
                break;

            case 4:
                insertionsort(a, n);
                printf("Sorted array (Insertion Sort): ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\nSteps: %d\n", steps);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
