#include <cstdio>

int main () {
    int T, tcase = 1;
    scanf("%d", &T);
    while(T--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long res = a + b; //res���a+b�Ľ��
        bool flag;
        if (a > 0 && b > 0 && res < 0)
            flag = true; //�����Ϊtrue
        else if(a < 0 && b < 0 && res >= 0)
            flag = false; //�����Ϊfalse
        else if(res > c)
            flag = true; //�����ʱ��A+B>cʱΪtrue
        else
            flag = false; //�����ʱ��A+B<=CʱΪfalse
        if(flag == true)
            printf("Case #%d: true\n", tcase++ );
        else
            printf("Case #%d: false\n", tcase++ );
    }
    return 0;
}
