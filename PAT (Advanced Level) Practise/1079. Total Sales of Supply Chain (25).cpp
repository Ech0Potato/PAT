/**
* ���������ı���+DFS������ǿǿ40����һ��AC�����Ƕ�DFS��̫����
*       Ҫ��ϸ������ݹ�����ͱ߽磬����˼·��������
*       ע��������Ͷ���double����int��������˵�����һ��ʱ��
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;

int n;
double p, r;
double np = p;
double sale = 0;

struct Node {
    int weight;
    int flag; //����Ƿ�Ϊ������
    vector<int> child;
} node[maxn];

void DFS(int index,  double np) {
    if(node[index].flag == 1) {
        sale += node[index].weight * np;
        np = np / (1.0 + r / 100);
        return;
    }
    if(node[index].flag == 0) {
        for(int i = 0; i < node[index].child.size(); i++)
            DFS(node[index].child[i], np + np * r / 100);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        int cnt, id, amount;
        scanf("%d", &cnt);
        if(cnt == 0) {
            scanf("%d", &amount);
            node[i].flag = 1;
            node[i].weight = amount;
        } else {
            node[i].flag = 0;
            for(int j = 0; j < cnt; j++) {
                scanf("%d", &id);
                node[i].child.push_back(id);
            }
        }
    }
    DFS(0, p);
    printf("%.1f", sale);
    return 0;
}
