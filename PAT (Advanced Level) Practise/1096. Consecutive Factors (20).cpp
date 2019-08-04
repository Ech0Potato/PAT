/**
* ����������ֽ������ӣ�ʵ�����������������
*       ����n���ܱ�����sqrt(n)����������������������ֻ�����2-sqrt(n)�����ߴ�����
*       �������⣬���Ҫ�����������󳤶ȣ������������Ľ��������
*       ������Ŀ�����Ͻ���2^31������Ҫ��long long����ֹ�˻����
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n;
    scanf("%lld", &n);
    LL sqr = (LL)sqrt(1.0 * n);
    LL ans, maxlen = 0;
    for(LL i = 2; i <= sqr; i++) {
        if(n % i == 0) {
            LL j = i, temp = 1, len = 0;
            while(j <= sqr) {
                temp *= j;
                if(n % temp == 0) {
                    len++;
                    j++;
                } else
                    break;
            }
            if(len > maxlen) {
                maxlen = len;
                ans = i;
            }
        }
    }
    if(maxlen == 0)
        printf("1\n%lld", n);
    else if(maxlen == 1)
        printf("1\n");
    else
        printf("%lld\n", maxlen);
    for(LL i = 0; i < maxlen; i++) {
        printf("%lld", ans);
        if(i != maxlen - 1)
            printf("*");
        ans++;
    }
    return 0;
}
