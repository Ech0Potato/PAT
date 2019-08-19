/**
* ������������������house�ľ�����Զ��station�������Ψһ�����ƽ��������С�ģ��������Ψһ��������С��
*       ������ô�жϣ���߶��Ǿ��룬�������ֻ����̾���û�еڶ���ߵ�����
*       ֻдDijkstra�̶�ģ�弴�ɣ���ÿһ�����ʹ��һ�Σ�Ȼ�����������бȽ��ж����
*       houseΪ1-n����station�����赽n+1-n+m�����鿪1020����
*       ����Ҫ��ϸ��һ��Ҫ�������⣡
*       gtmd��Ȼ�����������룬�������3.2�͸�����3.3��һ��Ҳ��A
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1020;
const int inf = 1000000000;

int n, m, k, s, st, ed;
int g[maxn][maxn];
int d[maxn];
bool vis[maxn];

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 1; i <= n + m; i++) {
        int u = -1, min = inf;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < min) {
                min = d[j];
                u = j;
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

int strToInt(string a) {
    int u = 0;
    if(a[0] == 'G') {
        if(a.size() == 2)
            u = a[1] - '0' + n;
        else
            u = n + m;
    } else {
        for(int j = 0; j < a.size(); j++)
            u = u * 10 + a[j] - '0';
    }
    return u;
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    cin >> n >> m >> k >> s;
    int dis;
    string a, b;
    for(int i = 0; i < k; i++) {
        int u = 0, v = 0;
        cin >> a >> b >> dis;
        u = strToInt(a);
        v = strToInt(b);
        g[u][v] = g[v][u] = dis;
    }
    int ans;
    double maxdist = 0, minaverage = inf; // �������house����Զ���� ƽ������
    for(int i = n + 1; i <= n + m; i++) {
        fill(vis, vis + maxn, false);
        double min = inf, average = 0;
        bool flag = true;
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {
            if(d[j] > s) { //�����house�ڷ���Χ��ֱ����һ��ѭ��
                flag = false;
                break;
            }
            average += d[j] * 1.0 / n;
            if(d[j] < min)
                min = d[j];
        }
        if(flag) {
            if(min > maxdist) {
                maxdist = min;
                minaverage = average;
                ans = i;
            } else if(min == maxdist && average < minaverage) {
                minaverage = average;
                ans = i;
            } //��С������� �������ж����
        }
    }
    if(maxdist != 0) {
        cout << "G" << ans - n << endl;
        printf("%.1f %.1f", maxdist, minaverage);
    } else {
        cout << "No Solution" << endl;
    }
    return 0;
}
