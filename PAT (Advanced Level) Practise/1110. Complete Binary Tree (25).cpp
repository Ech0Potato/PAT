/**
* ������ע�ⲻ�������ַ���Ӧ�����ַ�������Ϊ���ֿ�������λ
*      ܳ���̫ɵ���ˣ���Ϊ��ôһ�㣬�װ׿���9�֣���ȻҲֱ��A��
*      �����ж�д�ĺܸ��ӣ���ʵBFS�Ļ����и��򵥵�����
*      ������һ��ֻ�����ӻ���û�к��ӽ��Ľ��֮�󣬺��������һ��ȫ��Ҷ�ӽ�㣬������CBT
*      ����֮�ⵥ�������Ƿ����û�����ӵ����Һ��ӵ������Ҳ����CBT
*      ��ô������ԭ����࣬���ǲ��üӲ����ˡ�����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;

int n, root, ans;
bool isRoot[maxn];

struct Node {
    int lchild, rchild;
} node[maxn];

bool BFS(int root) {
    bool flag = false;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans = front; //��¼���һ�����
        int l = node[front].lchild;
        int r = node[front].rchild;
        if(flag) { //��֮��ֻҪ�в���Ҷ�ӽ��Ľ����ô������Ͳ���CBT
            if(l != -1 || r != -1)
                return false;
        }
        if((l != -1 && r == -1) || (l == -1 && r == -1)) //������һ��ֻ�����ӻ���û�к��ӽ��Ľ��
            flag = true;
        if(l == -1 && r != -1)
            return false;
        if(l != -1)
            q.push(l);
        if(r != -1)
            q.push(r);
    }
    return true;
}

int main() {
    string l, r; //��λ���Ļ���ֹһ���ַ�
    scanf("%d", &n);
    getchar();
    fill(isRoot, isRoot + n, true);
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        if(l != "-") {
            int lc = stoi(l);
            node[i].lchild = lc;
            isRoot[lc] = false;
        } else
            node[i].lchild = -1;
        if(r != "-") {
            int rc = stoi(r);
            node[i].rchild = rc;
            isRoot[rc] = false;
        } else
            node[i].rchild = -1;
    }
    for(int i = 0; i < n; i++) {
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    if(BFS(root))
        printf("YES %d", ans);
    else
        printf("NO %d", root);
    return 0;
}














//int n,root,ans;
//int last=0;
//
//struct Node {
//	int lchild,rchild;
//	int level;
//} node[maxn];
//
//bool BFS(int root) {
//	int num=0;
//	bool noleaves=false;
//	queue<int> q;
//	q.push(root);
//	node[root].level=0;
//	while(!q.empty()) {
//		int front=q.front();
//		q.pop();
//		ans=front; //��¼���һ�����
//		num++;
//		int l=node[front].lchild;
//		int r=node[front].rchild;
//		if(node[front].level!=last) {
//			if(l==-1&&r!=-1) {
//				return false;
//			}
//			if(l==-1&&r==-1) {
//				noleaves=true;
//			}
//			if(noleaves) {
//				if(l!=-1||r!=-1)
//					return false;
//			}
//		} else {
//			if(l!=-1||r!=-1) {
//				return false;
//			}
//		}
//		if(l!=-1) {
//			node[l].level=node[front].level+1;
//			q.push(l);
//		}
//		if(r!=-1) {
//			node[r].level=node[front].level+1;
//			q.push(r);
//		}
//	}
//	return true;
//}
//
//bool isRoot[maxn];
//
//int main() {
//	string l,r; //��λ���Ļ���ֹһ���ַ�
//	scanf("%d",&n);
//	getchar();
//	fill(isRoot,isRoot+n,true);
//	for(int i=0; i<n; i++) {
//		cin>>l>>r;
//		if(l!="-") {
//			int lc=stoi(l);
//			node[i].lchild=lc;
//			isRoot[lc]=false;
//		} else
//			node[i].lchild=-1;
//		if(r!="-") {
//			int rc=stoi(r);
//			node[i].rchild=rc;
//			isRoot[rc]=false;
//		} else
//			node[i].rchild=-1;
//	}
//	for(int i=0; i<n; i++) {
//		if(isRoot[i]) {
//			root=i;
//			break;
//		}
//	}
//	int m=n;
//	while(m!=0) {
//		m/=2;
//		last++;
//	}
//	if(BFS(root))
//		printf("YES %d",ans);
//	else
//		printf("NO %d",root);
//	return 0;
//}
