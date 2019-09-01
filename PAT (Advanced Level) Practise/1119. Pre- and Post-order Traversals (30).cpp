/**
* �����������������ں������������������и���������һ���㣬��������󣨰�������㣩Ϊ������������Ϊ������
*       ע����������������Ŀnumleftʱ����������ͬ��ֱ����ѭ��������
*       �ж��Ƿ�Ψһ�����ж����������Ŀ�Ƿ�Ϊ2������˵�ý���Ƿ�ֻ��1�����ӣ���ÿ����ǰ��������ȷ�����������Ŀ�����ж�
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int n;
int pre[maxn], post[maxn];
bool isonly = true;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int create(int prel, int prer, int postl, int postr) {
    if(prer - prel == 1 || postr - postl == 1) //  if(numleft==2||numright==2)  numleft=prer-prel+1  numright=postr-postl+1
        isonly = false;
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    int k, numleft = 0; //ע��������������������Ŀ
    for(k = postl; k < postr; k++) {
        numleft++;
        if(post[k] == pre[prel + 1])
            break;
    }
    //int numleft=k-postl+1;
    node[root].lchild = create(prel + 1, prel + numleft, postl, k);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, postr - 1);
    return root;
}

int num = 0;
void inOrder(int root) {
    if(root == -1)
        return;
    inOrder(node[root].lchild);
    printf("%d", node[root].data);
    num++;
    if(num != n)
        printf(" ");
    else
        printf("\n");
    inOrder(node[root].rchild);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    int root = create(0, n - 1, 0, n - 1);
    if(isonly)
        printf("Yes\n");
    else
        printf("No\n");
    inOrder(root);
    return 0;
}
