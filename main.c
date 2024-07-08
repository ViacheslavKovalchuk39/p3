#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
int countNumbers(int p) {
    if (p == 1) return 2; // "5", "9"
    if (p == 2) return 4; // "55", "59", "95", "99"
    int dp5[p+1];
    int dp9[p+1];
    dp5[1] = 1;
    dp9[1] = 1;
    dp5[2] = 2;
    dp9[2] = 2;
    for (int i = 3; i <= p; i++) {
        dp5[i] = dp5[i-1] + dp5[i-2];
        dp9[i] = dp9[i-1] + dp9[i-2];
    }

    return dp5[p] + dp9[p];
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p;
    printf("Введіть кількість розрядів: ");
    scanf("%d", &p);

    if (p > 30) {
        printf("Кількість розрядів повинна бути не більше 30.\n");
        return 1;
    }

    int result = countNumbers(p);
    printf("Кількість чисел із %d розрядів: %d\n", p, result);
    return 0;
}

