#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> in, level;
void levelorder(int start, int end, int index) {
    if(start > end) return ;
    int n = end - start + 1;
    int l = log(n + 1) / log(2); // �������һ��Ĳ���
    int leave = n - (pow(2, l) - 1);// ���һ���Ҷ�ӽڵ���
    int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave); // pow(2, l - 1) - 1�ǳ���root������ڲ�����һ���⣬�������Ľ�������pow(2, l - 1) ��l+1�����ӵ�е����ڸ�����������Ľ�������min(pow(2, l - 1), leave)�����һ���������ӵ�е����ڸ�����������ϵĽ�����
    level[index] = in[root];
    levelorder(start, root - 1, 2 * index + 1);
    levelorder(root + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    levelorder(0, n - 1, 0);
    printf("%d", level[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}
