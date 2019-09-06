/**
* ����������һ�ֽ������Կ϶�A�����������ǽ�����ʱ��ע������Ҫ�ݹ齨�������뽨���ᳬʱ
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;

int m, n, x, a, b, root = -1;
int pre[maxn], in[maxn];
unordered_map<int, int> id; //�洢����������е��±�
unordered_map<int, bool> mp; //��ǽ���Ƿ����

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

int LCA(int a, int b) { //����Ϊ����±�
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
        scanf("%d", &x);
        pre[i] = in[i] = x;
        mp[x] = true;
    }
    sort(in, in + n);
    root = create(0, n - 1, 0, n - 1, -1, 0);
    while(m--) {
        scanf("%d%d", &a, &b);
        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
            int anc = node[LCA(id[a], id[b])].data;
            if(anc != a && anc != b)
                printf("LCA of %d and %d is %d.\n", a, b, anc);
            else
                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
        } else {
            if(mp.find(a) == mp.end() && mp.find(b) == mp.end())
                printf("ERROR: %d and %d are not found.\n", a, b);
            if(mp.find(a) != mp.end() && mp.find(b) == mp.end())
                printf("ERROR: %d is not found.\n", b);
            if(mp.find(a) == mp.end() && mp.find(b) != mp.end())
                printf("ERROR: %d is not found.\n", a);
        }
    }
    return 0;
}




//**
//* ��������BST����LCA��һ��ʼ�������ʱ��ѡ�����жϴ�С������������������ֻ��19��
//*       debug����һ��ʼ��д����������Ϊ�ϴ��������Ϊ����㣬�Ǳ������Ǹ�ֻ�����ӵ��������ˣ����������ֻ���Һ��ӵ������ͻ����
//*       ����iӦ��>=a����<=b��������Ϊ20�֣�debug���ֽ�����˵�����д�������������29��
//*       ����dubug������������ͬʱ����д�����һ��ʵ������ 2 8 7 9 4 -3 0 9
//*       ע�Ͳ���Ϊ���ӽ�����������Ĵ���
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int m, n, x, a, b;
//bool isswap;
//vector<int> tree;
//map<int, bool> mp;
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        tree.push_back(x);
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            isswap = false;
//            if(a > b) {
//                swap(a, b);
//                isswap = true;
//            }
//            for(auto i : tree) {
////				if((i>=a&&i<=b)||(i<=a&&i>=b)) {
////					if(i==a||i==b) {
////						if(i==a)
////							printf("%d is an ancestor of %d.\n",a,b);
////						else
////							printf("%d is an ancestor of %d.\n",b,a);
////
////					} else
////						printf("LCA of %d and %d is %d.\n",a,b,i);
////				}
//                if(i >= a && i <= b) {
//                    if(i != a && i != b) {
//                        if(isswap)
//                            printf("LCA of %d and %d is ", b, a);
//                        else
//                            printf("LCA of %d and %d is ", a, b);
//                        printf("%d.\n", i);
//                    } else {
//                        if(i == a)
//                            printf("%d is an ancestor of %d.\n", a, b);
//                        else if(i == b)
//                            printf("%d is an ancestor of %d.\n", b, a);
//                    }
//                    break;
//                }
//            }
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            } else if(mp.find(a) == mp.end() && mp.find(b) != mp.end()) {
//                printf("ERROR: %d is not found.\n", a);
//            } else if(mp.find(a) != mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d is not found.\n", b);
//            }
//        }
//    }
//    return 0;
//}




//**
//* ������ֱ�ӽ�������ͨ����������ʵ���㲻���ڴˣ���ôд������TLE
//*       ��˵һ��˼·�����Ǵ洢����㵽������������·��
//*       �����Ǵ洢���ڵ�Ȼ�������·��������DFS��û�Թ���Ӧ�ÿ��ԣ�ģ��ͼ��temppath pathд����
//*       Ȼ��������£��ҵ�һ�鲻��ȵĽ�㣬�������ĸ���㼴Ϊ����
//*       ��vector��ʱ������Ҳ��ʱ������������δ����ύ����A�ģ���̫����
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 10001;
//
//int m, n, x, a, b, root = -1;
//map<int, int> id; //�洢����������е��±�
//map<int, bool> mp; //��ǽ���Ƿ����
//int pa[maxn], pb[maxn];
//
//struct Node {
//    int data, lchild, rchild;
//    int parent;
//} node[maxn];
//
//int idx = 0;
//void insert(int &root, int x, int parent) {
//    if(root == -1) {
//        node[idx].data = x;
//        node[idx].lchild = node[idx].rchild = -1;
//        node[idx].parent = parent;
//        id[x] = idx; //�洢����������е��±�
//        root = idx++;
//        return;
//    }
//    if(x < node[root].data)
//        insert(node[root].lchild, x, root);
//    else
//        insert(node[root].rchild, x, root);
//}
//
//int LCA(int a, int b) { //����Ϊ����±�
//    //vector<int> pa,pb;
//    //pa.push_back(node[a].data),pb.push_back(node[b].data); //·���ϴ�ֵ�������±꣬��Ϊ��󷵻ص��ǽ��ֵ
//    int ca = 1, cb = 1;
//    pa[0] = node[a].data, pb[0] = node[b].data;
//    while(node[a].parent != -1) {
//        a = node[a].parent;
//        //pa.push_back(node[a].data);
//        pa[ca++] = node[a].data;
//    }
//    while(node[b].parent != -1) {
//        b = node[b].parent;
//        //pb.push_back(node[b].data);
//        pb[cb++] = node[b].data;
//    }
//    int i;
////	for(i=0; i<pa.size()||i<pb.size(); i++) { //��������������·���ϵ�һ�鲻��ȵĽ�㣬�������ĸ��ڵ㼴Ϊ����
////		if(pa[pa.size()-1-i]!=pb[pb.size()-i-1]) //ע������±�ı�ʾ
////			return pa[pa.size()-i]; //���������ĸ��ڵ㣬����һ�����
////	}
////	if(i==pa.size())
////		return pa[0];
////	if(i==pb.size())
////		return pb[0];
//    for(i = 0; i < ca || i < cb; i++) {
//        if(pa[ca - 1 - i] != pb[cb - 1 - i])
//            return pa[ca - i];
//    }
//    if(i == ca)
//        return pa[0];
//    if(i == cb)
//        return pb[0];
//}
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        insert(root, x, root); //�����ĸ��ڵ�Ϊ-1
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            int anc = LCA(id[a], id[b]);
//            if(anc != a && anc != b)
//                printf("LCA of %d and %d is %d.\n", a, b, anc);
//            else
//                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end())
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            if(mp.find(a) != mp.end() && mp.find(b) == mp.end())
//                printf("ERROR: %d is not found.\n", b);
//            if(mp.find(a) == mp.end() && mp.find(b) != mp.end())
//                printf("ERROR: %d is not found.\n", a);
//        }
//    }
//    return 0;
//}
