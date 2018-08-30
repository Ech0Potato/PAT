/**
* 分析：最短路径模板题，Dijkstra算法的模板要理解并背熟
*       因为顶点数只有500因此选用连接矩阵
*       第二标尺是点权和最短路径数量，在处理最短路径的时候要同时处理这两项
*       注意输入边权之前要将图初始化
*       做题要仔细，赋值号和等号这种低级错误不要犯
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;

int n, m, st, ed;
int g[maxn][maxn], weight[maxn]; //边权、点权
int d[maxn], w[maxn], num[maxn]; //最短路径、最大点权、最短路径条数
bool vis[maxn];

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    fill(w, w + maxn, 0);
    fill(num, num + maxn, 0);
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && g[u][v] != inf) {
                if(d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                } else if(d[v] == d[u] + g[u][v]) {
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    fill(g[0], g[0] + maxn * maxn, inf); //初始化图g
    int c1, c2, l;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        g[c1][c2] = g[c2][c1] = l; //无向图
    }
    Dijkstra(st);
    printf("%d %d", num[ed], w[ed]);
    return 0;
}
