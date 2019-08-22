/**
* �������ؼ�������ؼ�·������
*       �������������ж��Ƿ�ΪDAG��Ȼ����DP��DAG�·
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int inf = 1000000000;

int n, m;
int g[maxn][maxn];
int order[maxn][maxn];

vector<int> adj[maxn]; //���ڽӱ���̽��
int indegree[maxn];
vector<int> topo; //��¼������
bool topoSort() {
    int num = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u); //������
        num++;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
        adj[u].clear();
    }
    if(num == n)
        return true;
    else
        return false;
}

int dp[maxn]; //dp[i]����i�Ŷ�������ܵ������󳤶�
vector<int> choice[maxn];
int DP(int i) {
    if(dp[i] > 0)
        return dp[i]; //���dp[i]�Ѿ�����õ���ֱ�ӷ���
    for(int j = 1; j <= n; j++) { //����i�����г���
        if(g[i][j] != inf) {
            int temp = dp[j] + g[i][j];
            if(temp > dp[i]) {
                dp[i] = temp;
                choice[i].clear();
                choice[i].push_back(j);
            } else if(temp == dp[i]) {
                choice[i].push_back(j);
            }
        }
    }
    return dp[i];
}

bool vis[maxn];
void DFS(int i) {
    vis[i] = true;
    for(auto j : choice[i]) {
        DFS(j);
    }
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    int u, v, w;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        order[u][v] = i;
        g[u][v] = w;
        adj[u].push_back(v);
        indegree[v]++;
    }
    if(topoSort()) {
        vector<int> st; //����·�����
        int max = -inf;
        for(auto it = topo.rbegin(); it != topo.rend(); it++) { //ע��Ҫ��������DP
            int i = *it;
            if(DP(i) > max) {
                max = DP(i);
                st.clear();
                st.push_back(i);
            } else if(DP(i) == max) {
                st.push_back(i);
            }
        }
        printf("%d\n", max);
        //����ĿҪ�����ÿ�ιؼ�·��
        for(auto nums : st) {
            DFS(nums);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i])
                continue;
            sort(choice[i].begin(), choice[i].end(), [&](int a, int b) { //�����ͬ ���������ʱ��˳���෴
                return order[i][a] > order[i][b];
            });
            for(auto j : choice[i]) {
                printf("%d->%d\n", i, j);
            }
        }
    } else {
        printf("0\n");
    }
    return 0;
}
