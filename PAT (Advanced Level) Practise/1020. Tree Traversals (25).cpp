/**
* 分析：给出一棵二叉书的后序和中序遍历，写出它的层序遍历
*       思路很简单，根据后序确定根结点，根据中序确定左右子树，递归建树
*       最后用BFS进行层序遍历即可
*       考查二叉树操作的基本功，此题应熟练掌握
**/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 31;

int n;
int in[maxn], post[maxn]; //存放中序和后序的数据域
int num = 0; //已输出结点个数，用来控制末尾是否输出空格

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR])
            break;
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

void BFS(node* root) {
    queue<node*> q; //这里存地址哦！
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        printf("%d", temp->data);
        num++;
        if(num < n)
            printf(" ");
        q.pop();
        if(temp->lchild != NULL)
            q.push(temp->lchild);
        if(temp->rchild != NULL)
            q.push(temp->rchild);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    node* root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
