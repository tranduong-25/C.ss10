#include <stdio.h>

int linearSearch(int arr[], int n, int key, int positions[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            positions[count] = i;  
            count++;
        }
    }
    return count;  
}

int main() {
    int n, key, count;
    
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[n], positions[n]; 

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap mot so nguyen de tim kiem: ");
    scanf("%d", &key);

    count = linearSearch(arr, n, key, positions);

    if (count > 0) {
        printf("Phan tu %d duoc tim thay tai vi tri: ", key);
        for (int i = 0; i < count; i++) {
            printf("%d ", positions[i]);
        }
        printf("\n");
    } else {
        printf("Phan tu %d khong co trong mang.\n", key);
    }

    return 0;
}
