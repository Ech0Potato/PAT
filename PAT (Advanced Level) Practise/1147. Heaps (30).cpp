/**
* �������ж��ǲ���һ���ѣ��Ǵ󶥶ѻ���С���ѣ�������������
*       ������ȫ�����������ʺͶѵĶ����жϣ��������ֱ��д����
*       ��ȫ��������������������洢˳�򼴲�α���˳�򣬸������Ϊn������2*n����2*n+1
*       �������Ϊn�����һ����Ҷ�ӽ��Ľ����Ϊn/2
**/

#include <cstdio>
const int maxn = 1010;

int m, n;
int cbt[maxn];
int flag;

void postorder(int index) {
    if(index > n)
        return;
    postorder(index * 2);
    postorder(index * 2 + 1);
    if(index != 1)
        printf("%d ", cbt[index]);
    else
        printf("%d\n", cbt[index]);
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &cbt[j]);
        }
        if(cbt[1] >= cbt[2]) {
            flag = 1;
            for(int k = 1; k <= n / 2; k++) {
                if(cbt[k] < cbt[2 * k] || ( 2 * k + 1 <= n && cbt[k] < cbt[2 * k + 1])) {
                    flag = 0;
                }
            }
        }
        if(cbt[1] <= cbt[2]) {
            flag = -1;
            for(int k = 1; k <= n / 2; k++) {
                if(cbt[k] > cbt[2 * k] || ( 2 * k + 1 <= n && cbt[k] > cbt[2 * k + 1])) {
                    flag = 0;
                }
            }
        }
        if(flag == 1) {
            printf("Max Heap\n");
        } else if(flag == -1) {
            printf("Min Heap\n");
        } else if(flag == 0) {
            printf("Not Heap\n");
        }
        postorder(1);
    }
    return 0;
}
