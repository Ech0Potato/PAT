/**
* ���������鼯���е�����⣬��ҪŪ�츸�׽��͸���㣬�ϲ���ʱ���Ǹ����
*       ģ��̶���������Ҫ�Լ�˼����д���ǲ��鼯�Ľ�������
*       �ٶ�ˢ���������һ�°�
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, k, t, cnt = 0;
int father[maxn];
int isRoot[maxn];
int hobby[maxn];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = 0;
    }
}

int findFather(int a) {
    int b = a;
    while(a != father[a]) {
        a = father[a];
    }
    //·��ѹ��
    while(b != father[b]) {
        int c = b;
        father[b] = a;
        b = father[c];
    }
    return a;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        father[fb] = fa;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(hobby[t] == 0)
                hobby[t] = i; //���һ������Ȥt����Ȥ����iΪ��Ȥt�ļ��ϵĸ����
            Union(i, hobby[t]);
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    sort(isRoot + 1, isRoot + 1 + n, cmp);
    for(int i = 1; i <= cnt; i++) {
        if(i < cnt)
            printf("%d ", isRoot[i]);
        else
            printf("%d", isRoot[i]);
    }
    return 0;
}
