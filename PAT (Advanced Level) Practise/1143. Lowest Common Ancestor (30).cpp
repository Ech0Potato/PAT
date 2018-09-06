/**
* ��������֪BST�������������������������������
*       ��ס���ɣ������������У���һ��������ڵ�������һ��㲢С�ڵ�����һ���Ľ�㼴Ϊ����
*       ������bool�����ǻ���һ���δ����һ�����Ե��޷�ͨ������5�֣��ĳ�map��AC
*       �мǲ�Ҫ������bool����
**/

#include <cstdio>
#include <map>
using namespace std;
const int maxn = 10010;

int m, n;
int pre[maxn];
//bool flag[maxn];
map<int, bool> mp;

int main() {
    scanf("%d%d", &m, &n);
    int temp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        pre[i] = temp;
        //flag[temp] = true;
        mp[temp] = true;
    }
    int u, v, r;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        for(int j = 0; j < n; j++) {
            r = pre[j];
            if((r >= u && r <= v) || (r <= u && r >= v))
                break;
        }
//        if(flag[u] == false && flag[v] == false) {
//            printf("ERROR: %d and %d are not found.\n", u, v);
//        } else if(flag[u] == false || flag[v] == false) {
//            printf("ERROR: %d is not found.\n", flag[u] == false ? u : v);
//        } else if(r == u || r == v) {
//            printf("%d is an ancestor of %d.\n", r, r == u ? v : u);
//        } else {
//            printf("LCA of %d and %d is %d.\n", u, v, r);
//        }
        if(mp[u] == false && mp[v] == false) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if(mp[u] == false || mp[v] == false) {
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        } else if(r == u || r == v) {
            printf("%d is an ancestor of %d.\n", r, r == u ? v : u);
        } else {
            printf("LCA of %d and %d is %d.\n", u, v, r);
        }
    }
    return 0;
}
