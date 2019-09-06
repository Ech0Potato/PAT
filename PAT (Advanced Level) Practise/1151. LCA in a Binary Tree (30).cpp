/**
* �������ݹ齨��+LCA�㷨��������ͬʱ���parent��level�ͽ����±�
*       ����Ҫע�⣬ֻ�ܵݹ齨��������ͨ�Ĳ��뽨����TLE
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int m, n, a, b, anc, root;
int pre[maxn], in[maxn];
unordered_set<int> st;
unordered_map<int, int> id;

struct Node {
    int data, lchild, rchild;
    int parent, level;
} node[maxn];

int create(int prel, int prer, int inl, int inr, int parent, int level) {
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    node[root].parent = parent;
    node[root].level = level;
    id[node[root].data] = root;
    int k;
    for(k = inl; k <= inr; k++) {
        if(in[k] == pre[prel])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1, root, level + 1);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr, root, level + 1);
    return root;
}

int LCA(int a, int b) {
    if(a == b)
        return a;
    if(node[a].level > node[b].level)
        LCA(node[a].parent, b);
    else
        LCA(a, node[b].parent);
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
    root = create(0, n - 1, 0, n - 1, -1, 0);
    while(m--) {
        scanf("%d%d", &a, &b);
        if(st.find(a) != st.end() && st.find(b) != st.end()) {
            int anc = node[LCA(id[a], id[b])].data;
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




























//**
//* �������õ�����ͨ�Ľ�����������ע�����±���Ǹ�&&�Ϳ�����
//*       DFS��ģ�µ�ͼ��·���������Ȼ�ȡ����㵽��������������·����Ȼ��������±������ҵ�һ�鲻��ȵĵ㣬���丸���Ϊ����
//*       ��������껹û�ҵ�����ô·���϶̵���һ�������һ�����Ϊ������ʵ���ǽϸߵ���һ������ȷ��
//*       ��˵������������һ���Ǽ�¼ÿ�����ĸ���㣬�ø������ƻ��·����Ȼ�����ͬ�ϣ�ע���±�Ϳɣ��������ڽ�����ʱ����Լ�¼������DFS
//*       ����BST������������ɸ������ʽ��⣬�����������LCA�㷨����Ҫ˼������ab�ڵ�ǰ�������࣬��ǰ���������Ϊ����
//*       ��ab�ڸ������࣬�����������ݹ飬��ab�ڸ�����Ҳ࣬�����������ݹ飬��ab�ڵ�ǰ�������࣬���ص�ǰ��������㼴��
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 10010;
//
//int m, n, a, b, anc, root;
//int pre[maxn], in[maxn];
//unordered_set<int> st;
//
//struct Node {
//	int data, lchild, rchild;
//} node[maxn];
//
//int create(int prel, int prer, int inl, int inr) {
//	if(prel > prer)
//		return -1;
//	int root = prel;
//	node[root].data = pre[prel];
//	int k;
//	for(k = inl; k <= inr; k++) {
//		if(in[k] == pre[prel])
//			break;
//	}
//	int numleft = k - inl;
//	node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1);
//	node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr);
//	return root;
//}
//
//vector<int> temppath,path, pa, pb;
//void DFS(int root, int x) {
//	if(root == -1)
//		return;
//	if(node[root].data == x) {
//		temppath.push_back(node[root].data);
//		path = temppath;
//		temppath.pop_back();
//		return;
//	}
//	temppath.push_back(node[root].data);
//	DFS(node[root].lchild, x);
//	DFS(node[root].rchild, x);
//	temppath.pop_back();
//}
//
//int main() {
//	scanf("%d%d", &m, &n);
//	for(int i = 0; i < n; i++) {
//		scanf("%d", &in[i]);
//		if(st.find(in[i]) == st.end())
//			st.insert(in[i]);
//	}
//	for(int i = 0; i < n; i++)
//		scanf("%d", &pre[i]);
//	root = create(0, n - 1, 0, n - 1);
//	while(m--) {
//		scanf("%d%d", &a, &b);
//		if(st.find(a) != st.end() && st.find(b) != st.end()) {
//			DFS(root, a);
//			pa=path;
//			DFS(root, b);
//			pb=path;
//			int i;
//			for(i = 0; i < pa.size() && i < pb.size(); i++) { //ע���������õ�&&����Ϊ�Ǵ������±���������1143���ִ���������
//				if(pa[i] != pb[i]) {
//					anc = pa[i - 1];
//					break;
//				}
//			}
//			if(i == pa.size())
//				anc = pa[pa.size() - 1];
//			if(i == pb.size())
//				anc = pb[pb.size() - 1];
//			if(anc != a && anc != b)
//				printf("LCA of %d and %d is %d.\n", a, b, anc);
//			else
//				printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
//		} else {
//			if(st.find(a) == st.end() && st.find(b) != st.end())
//				printf("ERROR: %d is not found.\n", a);
//			if(st.find(a) != st.end() && st.find(b) == st.end())
//				printf("ERROR: %d is not found.\n", b);
//			if(st.find(a) == st.end() && st.find(b) == st.end())
//				printf("ERROR: %d and %d are not found.\n", a, b);
//		}
//	}
//	return 0;
//}
