#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, key, index;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];  // Mảng có kích thước nhập từ người dùng

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("\nMang sau khi sap xep theo thu tu tang dan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap mot so nguyen de tim kiem: ");
    scanf("%d", &key);

    index = binarySearch(arr, n, key);

    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d (index).\n", key, index);
    } else {
        printf("Phan tu %d khong co trong mang.\n", key);
    }

    return 0;
}
