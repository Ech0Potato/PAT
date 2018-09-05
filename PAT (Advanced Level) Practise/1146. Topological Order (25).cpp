/**
* ����������������ʵ���ǿ�ģ�壬֪����������Ķ����ö���ȥ�жϼ���
*       �������޻�ͼ���ڱ�u->v����ô������uһ����vǰ��
**/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, m, k;
int g[maxn][maxn];
int inDegree[maxn];
vector<int> ans;

int main() {
    fill(g[0], g[0] + maxn * maxn, 0);
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = 1;
        inDegree[b]++;
    }
    int temp;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        queue<int> q;
        for(int j = 0; j < n; j++) {
            scanf("%d", &temp);
            q.push(temp);
        }
        int first = q.front();
        if(inDegree[first] != 0) {
            ans.push_back(i);
            continue;
        }
        while(!q.empty()) {
            int pre = q.front();
            q.pop();
            int next = q.front();
            if(g[next][pre] == 1) {
                ans.push_back(i);
                break;
            }
        }
    }
    for(int i = 0; i < ans.size() - 1; i++)
        printf("%d ", ans[i]);
    printf("%d", ans[ans.size() - 1]);
    return 0;
}
