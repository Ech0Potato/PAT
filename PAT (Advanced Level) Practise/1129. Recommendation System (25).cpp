/**
* ������ѧϰset����ṹ�����������صĶ����ʽ���Լ�����ֱ���޸�set�ڵ�Ԫ�أ���Ҫɾ�������²���
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;

struct node {
    int id, cnt;
    bool operator < (const node &a)const {
        return cnt != a.cnt ? cnt > a.cnt : id < a.id;
    }
};

set<node> st;
int cnt[maxn]; //��¼����

int main() {
    int n, k, q;
    scanf("%d%d", &n, &k);
    scanf("%d", &q);
    st.insert({q, 1}); //�����һ������
    cnt[q] = 1;
    for(int i = 1; i < n; i++) {
        scanf("%d", &q);
        printf("%d:", q);
        int num = 0;
        for(auto it = st.begin(); it != st.end() && num < k; it++) {
            printf(" %d", it->id);
            num++;
        }
        printf("\n");
        if(cnt[q] > 0) //����Ѵ��� ɾ��
            st.erase({q, cnt[q]});
        cnt[q]++;
        st.insert({q, cnt[q]});
    }
    return 0;
}
