/**
* �������õ�����ͨ�Ľ���������������ȥ�������࣬��ʵ����DFSһģһ��ֱ�Ӹ��Ƶģ�ע�����±���Ǹ�&&�Ϳ�����
*       DFS��ģ�µ�ͼ��·���������Ȼ�ȡ����㵽��������������·����Ȼ��������±������ҵ�һ�鲻��ȵĵ㣬���丸���Ϊ����
*       ��������껹û�ҵ�����ô·���϶̵���һ�������һ�����Ϊ������ʵ���ǽϸߵ���һ������ȷ��
*       ��˵������������һ���Ǽ�¼ÿ�����ĸ���㣬�ø������ƻ��·����Ȼ�����ͬ�ϣ�ע���±�Ϳɣ��������ڽ�����ʱ����Լ�¼������DFS
*       ����BST������������ɸ������ʽ��⣬�����������LCA�㷨����Ҫ˼������ab�ڵ�ǰ�������࣬��ǰ���������Ϊ����
*       ��ab�ڸ������࣬�����������ݹ飬��ab�ڸ�����Ҳ࣬�����������ݹ飬��ab�ڵ�ǰ�������࣬���ص�ǰ��������㼴��
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int m, n, a, b, anc, root;
int pre[maxn], in[maxn];
unordered_set<int> st;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int create(int prel, int prer, int inl, int inr) {
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    int k;
    for(k = inl; k <= inr; k++) {
        if(in[k] == pre[prel])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr);
    return root;
}

vector<int> path, pa, pb;
void DFSA(int root, int a) {
    if(root == -1)
        return;
    if(node[root].data == a) {
        path.push_back(node[root].data);
        pa = path;
        path.pop_back();
        return;
    }
    path.push_back(node[root].data);
    DFSA(node[root].lchild, a);
    DFSA(node[root].rchild, a);
    path.pop_back();
}
void DFSB(int root, int b) {
    if(root == -1)
        return;
    if(node[root].data == b) {
        path.push_back(node[root].data);
        pb = path;
        path.pop_back();
        return;
    }
    path.push_back(node[root].data);
    DFSB(node[root].lchild, b);
    DFSB(node[root].rchild, b);
    path.pop_back();
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        if(st.find(in[i]) == st.end())
            st.insert(in[i]);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    root = create(0, n - 1, 0, n - 1);
    while(m--) {
        scanf("%d%d", &a, &b);
        if(st.find(a) != st.end() && st.find(b) != st.end()) {
            DFSA(root, a), DFSB(root, b);
            int i;
            for(i = 0; i < pa.size() && i < pb.size(); i++) { //ע���������õ�&&����Ϊ�Ǵ������±���������1143���ִ���������
                if(pa[i] != pb[i]) {
                    anc = pa[i - 1];
                    break;
                }
            }
            if(i == pa.size())
                anc = pa[pa.size() - 1];
            if(i == pb.size())
                anc = pb[pb.size() - 1];
            if(anc != a && anc != b)
                printf("LCA of %d and %d is %d.\n", a, b, anc);
            else
                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
        } else {
            if(st.find(a) == st.end() && st.find(b) != st.end())
                printf("ERROR: %d is not found.\n", a);
            if(st.find(a) != st.end() && st.find(b) == st.end())
                printf("ERROR: %d is not found.\n", b);
            if(st.find(a) == st.end() && st.find(b) == st.end())
                printf("ERROR: %d and %d are not found.\n", a, b);
        }
    }
    return 0;
}
