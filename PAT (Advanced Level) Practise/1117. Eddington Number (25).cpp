/**
* ������E�쳬��E������ڲ����㣬����Ǳ߽����1 1Ӧ��Ϊ0
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int h[maxn]; //h[i]������i���������

int main() {
    int n, d;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d);
        if(d <= n)
            h[d - 1]++;
        else
            h[n]++;
    }
    for(int i = n - 1; i >= 1; i--)
        h[i] += h[i + 1];
    for(int i = n; i >= 0; i--) {
        if(h[i] >= i) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
