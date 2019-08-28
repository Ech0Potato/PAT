/**
* ����������������������������������ֱ�Ӳ��뽨��
*       Ȼ���жϸ�����Ƿ�Ϊ��ɫ
*       �����ж�ÿ����ɫ����Ƿ��к��ӽ�㣬�еĻ��Ƿ�Ϊ��ɫ
*       ���һ��������ָ�ж�ÿ����㣬����������������Ҷ�ӽ���·���Ͼ����ĺ�ɫ�����Ŀ�Ƿ����
*       ǰ���������ף����һ������дһ���ݹ麯��getnum���ڻ�ȡ��ɫ�����Ŀ��Ȼ����DFS��BFS�����ж�ÿ����㼴��
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int k, n, d, root = -1;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int idx = 0;
void insert(int &root, int x) {
    if(root == -1) {
        node[idx].data = x;
        node[idx].lchild = node[idx].rchild = -1;
        root = idx++;
        return;
    }
    if(abs(x) < abs(node[root].data)) {
        insert(node[root].lchild, x);
    } else {
        insert(node[root].rchild, x);
    }
}

int getnum(int root) {
    if(root == -1)
        return 0;
    int lnum = getnum(node[root].lchild);
    int rnum = getnum(node[root].rchild);
    if(node[root].data > 0)
        return max(lnum, rnum) + 1;
    else
        return max(lnum, rnum);
}

bool flag;
void DFS(int root) {
    if(root == -1)
        return;
    int l = node[root].lchild, r = node[root].rchild;
    if(node[root].data < 0) { //�ж�2
        if(l != -1 && node[l].data < 0)
            flag = false;
        if(r != -1 && node[r].data < 0)
            flag = false;
    }
    //�ж�3
    int lnum = getnum(l), rnum = getnum(r);
    if(lnum != rnum)
        flag = false;
    DFS(l);
    DFS(r);
}

int main() {
    scanf("%d", &k);
    while(k--) {
        root = -1, idx = 0;
        flag = true;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &d);
            insert(root, d);
        }
        //�ж�1
        if(node[root].data < 0)
            flag = false;
        DFS(root); //DFS�����н����ж�2���ж�3
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
