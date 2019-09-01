/**
* �����������̻�·�����ж�ŷ����·���ƣ�д��ʱ��ע���������ͼ�е����е㻹��·���ϵĵ�
*      �����ж��Ƿ�Ϊ�����̻�·��Ҫ�������㣺����յ���ͬ��ͼ��ͨ�����������Ƿ�ɴ������ͼ�����еĵ�
*      ���ж��Ƿ�Ϊ�򵥻�·����·���ϳ��������������⣬����ÿ������Ƿ�ֻ����һ��
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, m, q, k;
int path[maxn];
int g[maxn][maxn];
bool ists, issimple;
int h[maxn];

int main() {
    int a, b, t, dis;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &dis);
        g[a][b] = g[b][a] = dis;
    }
    int mindis = 1000000000, mini;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        dis = 0;
        ists = true, issimple = true;
        fill(h, h + maxn, 0);
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &path[j]);
            h[path[j]]++;
        }
        for(int j = 1; j < k; j++) {
            a = path[j], b = path[j - 1];
            if(g[a][b] != 0)
                dis += g[a][b];
            else {
                dis = -1; //ͳ�Ƴ���˳���ж��Ƿ���ͨ
                ists = false;
                break;
            }
        }
        for(int j = 1; j <= n; j++) { //�ж��Ƿ����ͼ�����е�
            if(h[j] == 0) {
                ists = false;
                break;
            }
        }
        if(path[0] != path[k - 1]) //�ж�����յ��Ƿ���ͬ
            ists = false;
        if(h[path[0]] != 2) //�ж�����Ƿ�ֻ��������
            issimple = false;
        for(int j = 1; j < k - 1; j++) { //�ж�·���ϵĵ��Ƿ�ֻ����һ��
            t = path[j];
            if(h[t] != 1) {
                issimple = false;
                break;
            }
        }
        if(dis != -1)
            printf("Path %d: %d ", i, dis);
        else
            printf("Path %d: NA ", i);
        if(ists) {
            if(issimple)
                printf("(TS simple cycle)\n");
            else
                printf("(TS cycle)\n");
        } else
            printf("(Not a TS cycle)\n");
        if(dis < mindis && dis != -1 && ists) {
            mindis = dis;
            mini = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", mini, mindis);
    return 0;
}
