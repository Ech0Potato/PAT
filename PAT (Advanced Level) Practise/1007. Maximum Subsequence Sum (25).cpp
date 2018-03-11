#include <stdio.h>
#define MAXN 10010

int main() {
    int n;
    int a[MAXN];
    while (scanf("%d\n", &n) != EOF) {

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int ThisSum, MaxSum, start, end, cnt1, flag;
        ThisSum = MaxSum = start = cnt1 = flag = 0;
        for (int i = 0; i < n; i++) {
            ThisSum += a[i];
            cnt1++;
            if (a[i] >= 0)
                flag = 1; //存在0或正数则flag置为1
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
                end = i;
                start = i - cnt1 + 1;
            } else if (ThisSum < 0) {
                ThisSum = 0;
                cnt1 = 0;
            }
        }

        if (MaxSum == 0) {
            if (flag == 0)
                printf("0 %d %d\n", a[0], a[n - 1]); //全负数的情况
            else
                printf("0 0 0\n"); //负数和0的情况
        } else {
            printf("%d %d %d\n", MaxSum, a[start], a[end]);
        }
    }
    return 0;
}
