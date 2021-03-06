/**
* 分析：这题有问题，答案输出是37.98，小数位四舍五入
*       晴神宝典的写法答案是37.97，且输出格式不太一致，但能通过
*       我的写法答案也是37.97，而且输出格式一致，但不能通过
*       可能题目是要求每输入一行数据就输出一个结果
*       此题知道用数组输出字符的结果的小技巧即可
**/

#include <cstdio>

int main() {
    char S[3] = { 'W', 'T', 'L' };
    double ans = 1.0, tmp, a;
    int idx; //记录每行最大数字的下标
    for (int i = 0; i < 3; i++) {
        tmp = 0.0;
        //寻找该行最大的数字存于tmp
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a);
            if (a > tmp) {
                tmp = a;
                idx = j;
            }
        }
        ans *= tmp;
        printf("%c ", S[idx]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}

/*
    int main() {
        char s[3] = {'W', 'T', 'L'};
        double p[3][3];
        double profit = 1.0, max = 0;
        int id = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                scanf("%lf", &p[i][j]);
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(p[i][j] > max) {
                    max = p[i][j];
                    id = j;
                }
            }
            profit *= max;
            printf("%c ", s[id]);
        }
        printf("%.2f", (profit * 0.65 - 1) * 2);
        return 0;
    }
*/
