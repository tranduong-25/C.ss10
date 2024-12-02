#include <stdio.h>

void nhapMang(int arr[100][100], int *dong, int *cot) {
    printf("Nhap so dong va so cot cua mang: ");
    scanf("%d %d", dong, cot);
    for (int i = 0; i < *dong; i++) {
        for (int j = 0; j < *cot; j++) {
            printf("Nhap phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMaTran(int arr[100][100], int dong, int cot) {
    printf("Mang theo ma tran:\n");
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inLeVaTong(int arr[100][100], int dong, int cot) {
    int tong = 0;
    printf("Cac phan tu le: ");
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                tong += arr[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong);
}

void inDuongBienVaTich(int arr[100][100], int dong, int cot) {
    int tich = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int j = 0; j < cot; j++) {
        printf("%d ", arr[0][j]);
        tich *= arr[0][j];
    }
    for (int i = 1; i < dong; i++) {
        printf("%d ", arr[i][cot - 1]);
        tich *= arr[i][cot - 1];
    }
    for (int j = cot - 2; j >= 0; j--) {
        printf("%d ", arr[dong - 1][j]);
        tich *= arr[dong - 1][j];
    }
    for (int i = dong - 2; i > 0; i--) {
        printf("%d ", arr[i][0]);
        tich *= arr[i][0];
    }
    printf("\nTich cac phan tu duong bien: %d\n", tich);
}

void inDuongCheoChinh(int arr[100][100], int dong, int cot) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < dong && i < cot; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int arr[100][100], int dong, int cot) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < dong && i < cot; i++) {
        printf("%d ", arr[i][cot - i - 1]);
    }
    printf("\n");
}

void inDongMaxTong(int arr[100][100], int dong, int cot) {
    int maxTong = -1, dongMax = -1;
    for (int i = 0; i < dong; i++) {
        int tong = 0;
        for (int j = 0; j < cot; j++) {
            tong += arr[i][j];
        }
        if (tong > maxTong) {
            maxTong = tong;
            dongMax = i;
        }
    }
    printf("Dong co tong gia tri lon nhat: ");
    for (int j = 0; j < cot; j++) {
        printf("%d ", arr[dongMax][j]);
    }
    printf("\nTong: %d\n", maxTong);
}

int main() {
    int arr[100][100], dong, cot, luaChon;
    
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh\n");
        printf("6. In ra cac phan tu tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch(luaChon) {
            case 1:
                nhapMang(arr, &dong, &cot);
                break;
            case 2:
                inMaTran(arr, dong, cot);
                break;
            case 3:
                inLeVaTong(arr, dong, cot);
                break;
            case 4:
                inDuongBienVaTich(arr, dong, cot);
                break;
            case 5:
                inDuongCheoChinh(arr, dong, cot);
                break;
            case 6:
                inDuongCheoPhu(arr, dong, cot);
                break;
            case 7:
                inDongMaxTong(arr, dong, cot);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 8);

    return 0;
}
