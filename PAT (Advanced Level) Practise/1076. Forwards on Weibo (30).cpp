/**
* 分析：图的关系应该按信息传递的方向指向，因此确定图的关系是user指向follower，其余没坑点，BFS即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, l, k, cnt;
int g[maxn][maxn] = {0};
int level[maxn];
bool inq[maxn] = {false};

void BFS(int u) {
    queue<int> q;
    q.push(u);
    level[u] = 0;
    inq[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(g[u][i] == 1) {
                if(inq[i] == false) {
                    level[i] = level[u] + 1;
                    if(level[i] <= l) {
                        q.push(i);
                        inq[i] = true;
                        cnt++;
                    }
                }
            }
        }
    }
}

int main() {
    int m, t, q;
    scanf("%d%d", &n, &l);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &t);
            g[t][i] = 1; //user->follower
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &q);
        cnt = 0;
        fill(inq, inq + maxn, false);
        BFS(q);
        printf("%d\n", cnt);
    }
    return 0;
}
