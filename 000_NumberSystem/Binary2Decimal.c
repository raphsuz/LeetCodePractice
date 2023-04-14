#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, i = 0, remainder;
    printf("請輸入二進位數字: ");
    scanf("%lld", &binary);
    long long binary_val = binary;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }

    printf("二進位數字 %lld 的十進位表示為: %d\n", binary_val, decimal);
    return 0;
}