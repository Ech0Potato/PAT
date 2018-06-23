/**
* 下面为Dijkstra算法的解法
* 另外还有一种Dijkstra+DFS的解法 见晴神宝典P389
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510; //最大顶点数
const int INF = 1000000000; //无穷大

int n, m, st, ed; //顶点数、边数、起点、终点
int G[MAXV][MAXV], cost[MAXV][MAXV]; //距离矩阵、花费矩阵
int d[MAXV], c[MAXV], pre[MAXV]; //最短路径、最小花费、前驱
bool vis[MAXV] = { false }; //vis[i]==true表示顶点i已访问，初值均为false

//Dijkstra算法，s为起点
void Dijkstra(int s) {
    fill(d, d + MAXV, INF); //fill函数将整个d数组赋为INF（慎用memset）
    fill(c, c + MAXV, INF);
    for (int i = 0; i < n; i++)
        pre[i] = i;
    d[s] = 0; //起点s到达自身的距离为0
    c[s] = 0; //起点s到达自身的花费为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j < n; j++) {
            //未找到访问的顶点中d[]最小的
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return; //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        vis[u] = true; //标记u为已访问
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                //如果v未访问且u能达到v
                if (d[u] + G[u][v] < d[v]) {
                    //以u为中介点时能令d[v]更小
                    d[v] = d[u] + G[u][v]; //优化d[v]
                    c[v] = c[u] + cost[u][v]; //优化c[v]
                    pre[v] = u; //令v的前驱为u
                } else if (d[u] + G[u][v] == d[v]) {
                    //找到一条相同长度的路径
                    if (c[u] + cost[u][v] < c[v]) {
                        //以u为中介点时c[v]更小
                        c[v] = c[u] + cost[u][v]; //优化c[v]
                        pre[v] = u; //令v的前驱为u
                    }
                }
            }
        }
    }
}

//打印路径
void DFS(int v) {
    if (v == st) {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF); //初始化图G
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]); //最短路径、最短路径下的最小花费
    return 0;
}
