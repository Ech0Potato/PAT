/**
* ��������ȷ��������Ͷ�������ص�
*       ������ǰ�������������Һ���δ�����������ȫ��ͬ����������󼸸�����������δ����ĵ�һ������Ϊ���ֵ
*       ������ҵ���С�����һ�����ٵ��������֣�Ȼ�����������ֿ�ʼ��ԭ���бȶԣ������ȫ��ͬ����Ϊ���ţ�����Ϊ������
*       �ж�֮��������������еĻ������ٽ���һ�����򼴿�
*       ���ſ���sort���棬��ԭ���ж���һ������
*       ��������Ҫ�ǵ÷����������Ѷ���δ����Ķѵ����һ��Ԫ�أ�Ȼ�����µ�������
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

int n, t = 2;
int a[maxn], b[maxn];

void downAdjust(int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && b[j] < b[j + 1])
            j = j + 1;
        if(b[i] < b[j]) {
            swap(b[i], b[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    while(t <= n && b[t - 1] <= b[t])
        t++;
    int index = t;
    while(t <= n && a[t] == b[t])
        t++;
    if(t == n + 1) {
        printf("Insertion Sort\n");
        sort(b + 1, b + index + 1);
        printf("%d", b[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", b[i]);
    } else {
        printf("Heap Sort\n");
        t = n;
        while(t >= 2 && b[t] >= b[t - 1])
            t--;
        swap(b[1], b[t]);
        downAdjust(1, t - 1);
        printf("%d", b[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", b[i]);
    }
    return 0;
}
