#include <stdio.h>

int main() {
    int decimal, binary = 0, base = 1;
    printf("請輸入十進位數字: ");
    scanf("%d", &decimal);
    int decimal_val = decimal;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    printf("十進位數字 %d 的二進位表示為: 0x%d\n", decimal_val, binary);
    return 0;
}