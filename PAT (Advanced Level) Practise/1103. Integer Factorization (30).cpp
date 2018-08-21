/**
* ������DFS��Ҫ������Ϊʲô��DFS��Ҫ�ҵ�����ͬ�Ͳ�·�ڣ�Ҫ������ĿҪ��
*       ע��ݹ������������ʽ
*       ��������ΪɶCB������������bug��pow(5,2)��Ȼ�����24�Բۣ�
**/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, k, p, maxfacsum = -1;
vector<int> fac, ans, temp;

void DFS(int index, int nowk, int sum, int facsum) {
    //����ͬ
    if(nowk == k && sum == n) {
        if(facsum > maxfacsum) {
            maxfacsum = facsum;
            ans = temp;
        }
        return;
    }
    if(nowk > k || sum > n)
        return;
    //�����
    if(index >= 1) {
        temp.push_back(index);
        DFS(index, nowk + 1, sum + fac[index], facsum + index);
        temp.pop_back();
        DFS(index - 1, nowk, sum, facsum);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    //Ԥ����
    for(int i = 0; pow(i, p) <= n; i++)
        fac.push_back(pow(i, p));
    DFS(fac.size() - 1, 0, 0, 0);
    if(maxfacsum == -1)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for(int i = 1; i < ans.size(); i++)
            printf(" + %d^%d", ans[i], p);
    }
    return 0;
}
