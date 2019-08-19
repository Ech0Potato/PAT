/**
* ������ת��ΪDPģ������½����� dp[i]=max(1,dp[j]+1)
*       ��������ǰ���Ŀ�����ĳ̶�����ת��Ϊ��С��ϵ����һ�����ȼ����飬����ô��ֻ��24�֣���һ��WA
*       ���¶��ⷢ���еĵ㲻��ѡ����״̬ת�Ʒ��̵��ж������϶��һ���жϼ���
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int a[maxn], dp[maxn], p[maxn]; // ���� ��a[i]��β����󳤶� ���ȼ�

int main() {
    fill(p, p + maxn, -1);
    int n, m, l, t, ans = -1;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        p[t] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < l; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(p[a[j]] <= p[a[i]] && dp[j] + 1 > dp[i] && p[a[j]] != -1) //��ѡ�ĵ㲻���Ǹ�������֮���
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
