/**
* ��������ת�����������в�α������������
*       ���˲������СʱAC����Ȼ�õĽ����ķ���
*       �������������������Ȼ��û�н���������δ��������Ҳ�࣬˵��һֱ�ý����ķ����ǿ��е�
*       �����ϰ����������߱����ٶȼ���
*       ˵һ������⣬��Ϊ��Ŀ�����ǽ���ţ������þ�̬ʵ�ֱȽϷ���
*       ��ת������������������ʱ�򽻻����������û�б�ָ����Ľ��
*       �����Ŀӵ����������ʱ��Ҫ���ջ��з���ע�����ϸ��ѧ���������
**/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 11;

int n, root, cnt1 = 0, cnt2 = 0;
char a, b;

struct Node {
    int lchild;
    int rchild;
    int flag; //��������ҳ�����㣬Ĭ��Ӧ����Ϊ0�������ֶ���ֵΪ0
} node[maxn];

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(temp != -1) {
            printf("%d", temp);
            cnt1++;
            if(cnt1 < n)
                printf(" ");
        }
        if(node[temp].lchild != -1)
            q.push(node[temp].lchild);
        if(node[temp].rchild != -1)
            q.push(node[temp].rchild);
    }
}

void inOrder(int root) {
    if(root == -1)
        return;
    inOrder(node[root].lchild);
    printf("%d", root);
    cnt2++;
    if(cnt2 < n)
        printf(" ");
    inOrder(node[root].rchild);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("\n%c %c", &a, &b);
        if(a == '-')
            node[i].rchild = -1;
        else {
            node[i].rchild = a - '0';
            node[node[i].rchild].flag = 1;
        }
        if(b == '-')
            node[i].lchild = -1;
        else {
            node[i].lchild = b - '0';
            node[node[i].lchild].flag = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(node[i].flag == 0) {
            root = i;
            break;
        }
    }
    BFS(root);
    printf("\n");
    inOrder(root);
    return 0;
}
