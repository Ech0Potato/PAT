/**
* ������N�ʺ����⣬��û����⣬ֻ���жϣ�easy
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int col[maxn]; //��i�е��������ڵ�����

int main() {
    int k, n;
    scanf("%d", &k);
    while(k--) { //��������ÿ���������ڵ�������������������
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &col[i]);
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(abs(j - i) == abs(col[j] - col[i]) || col[j] == col[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
