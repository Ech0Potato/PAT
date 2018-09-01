/**
* ������̫����̫���ˡ�����
*       ��Ҫ�����п���ȥ����ֱ�������·�����⵱��Dijkstra+DFS�⣬����������Ǵ�Dijkstra��
*       ģ����һ������Ҫ���������������߼�����Ҫ���������·����˼��ſ���
*       Ȼ����㷨����������·�������ߣ�ȥ�����Ŀ���ʵ������
*       ��ΪCB��֧��C++11�����stoi�����ã�ѧ���ֶ�ѭ��ʵ���ַ��������ֵ�ת��
**/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1020;
const int inf = 1000000000;

int n, m, k, ds;
int g[maxn][maxn];
int d[maxn];
bool vis[maxn];

int getnum(string s) {
    int ans = 0;
    if (s[0] == 'G') {
        for (int i = 1; i < s.length(); i++)
            ans = ans * 10 + s[i] - '0';
        ans += n;
    } else {
        for (int i = 0; i < s.length(); i++)
            ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

void Dijkstra(int s) {
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 1; i <= n + m; i++) {
        int u = -1, min = inf;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(vis[v] == false && g[u][v] != inf) {
                if(d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                }
            }
        }
    }
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string p1, p2;
    int a, b, dist;
    for(int i = 0; i < k; i++) {
        cin >> p1 >> p2 >> dist;
        a = getnum(p1);
        b = getnum(p2);
        g[a][b] = g[b][a] = dist;
    }
    int ansid = -1;
    double ansdis = -1, ansavg = inf;
    for(int i = n + 1; i <= n + m; i++) {
        double mindis = inf, avg = 0;
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {
            if(d[j] > ds) {
                mindis = -1;
                break;
            }
            if(d[j] < mindis) {
                mindis = d[j];
            }
            avg += 1.0 * d[j];
        }
        avg = avg / n;
        if(mindis == -1)
            continue;
        if(mindis > ansdis) {
            ansid = i;
            ansdis = mindis;
            ansavg = avg;
        } else if(mindis == ansdis && avg < ansavg) {
            ansid = i;
            ansavg = avg;
        } //��Ϊ�Ǵ�С��������������������жϸ�С��ID
    }
    if(ansid == -1)
        printf("No Solution");
    else {
        printf("G%d\n", ansid - n);
        printf("%.1f %.1f", ansdis, ansavg);
    }
    return 0;
}
