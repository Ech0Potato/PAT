/**
* ����������set��ʹ�ã���סset��ʹ�����κ���غ������ɣ������������߼�
*       ����Ҫ�������⣬���ж��������ϵĽ���ռ�����İٷֱȣ�����һ��set�����ÿ�����ݴ�����set�Ｔ��
*       Ȼ��ע�������һ�����ϼ��ɣ�ֱ�Ӳ��ҵڶ���������������ͬԪ��Ȼ��ͳ�ƣ��������Դ�󽵵�ʱ�临�Ӷ�
*       ��Ҫע�������ʽ�Լ������������һ��.0
**/

#include <cstdio>
#include <set>
using namespace std;
const int maxn = 50;

int main() {
    int n, m, k, temp, s1, s2, sameNum = 0, totalNum = 0;
    set<int> num[maxn];
    set<int>::iterator it;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            num[i].insert(temp);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &s1, &s2);
        s1 = s1 - 1;
        s2 = s2 - 1;
        for( it = num[s1].begin(); it != num[s1].end(); it++) {
            if(num[s2].find(*it) != num[s2].end())
                sameNum++;
        }
        totalNum = num[s1].size() + num[s2].size() - sameNum;
        printf("%.1f%%\n", sameNum * 100.0 / totalNum);
        sameNum = 0;
        totalNum = 0;
    }
    return 0;
}
