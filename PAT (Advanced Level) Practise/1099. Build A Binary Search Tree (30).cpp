/**
* ������BST������������������ʮ����һ��AC�ˣ�����30�֣�����
*       ���˽����ŵ��þ�̬ʵ����̤���д��
*       һ��Ҫʮ����ϤBST�����ʣ�����
**/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

int n, left, right, index = 0, cnt = 0;
int data[maxn];

struct Node {
    int data;
    int lchild, rchild;
} node[maxn];

void inOrder(int root) {
    if(root == -1)
        return;
    inOrder(node[root].lchild);
    node[root].data = data[index++];
    inOrder(node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int temp = q.front();
        cnt++;
        if(cnt < n)
            printf("%d ", node[temp].data);
        else
            printf("%d", node[temp].data);
        q.pop();
        if(node[temp].lchild != -1)
            q.push(node[temp].lchild);
        if(node[temp].rchild != -1)
            q.push(node[temp].rchild);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &left, &right);
        node[i].lchild = left;
        node[i].rchild = right;
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    sort(data, data + n);
    inOrder(0);
    BFS(0);
    return 0;
}
