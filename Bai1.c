#include <stdio.h>

void sapXepBubble(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tam = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tam;
            }
        }
    }
}

int timKiemNhiPhan(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sapXepBubble(arr, n);

    printf("Nhap phan tu can tim: ");
    scanf("%d", &target);

    int ketQua = timKiemNhiPhan(arr, n, target);
    if (ketQua != -1) {
        printf("Phan tu %d co vi tri tai mang: %d\n", target, ketQua);
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    }

    return 0;
}
