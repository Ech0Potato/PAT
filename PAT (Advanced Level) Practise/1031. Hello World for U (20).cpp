/**
* ��������ӡͼ�Σ�������Ŀ������������ƹ�ʽ����
*       Ȼ���׹�ʽ������λ�õ��ַ����������ݸ�����ӡ
*       ����������ô��ӡ�����������λ�õ����ݿ�һ��
*       ��ʽҪд�ԣ���Ҫ���Լ������չ�ʽ������Ŀ��
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 81;

int main() {
    char str[maxn];
    cin >> str;
    int N = strlen(str);
    int n1, n2, n3;
    n1 = (N + 2) / 3;
    n3 = n1;
    n2 = N + 2 - n1 - n3;
    //printf("%d %d %d", n1, n2, n3);
    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]);
        for(int j = 0; j < n2 - 2; j++)
            printf(" ");
        printf("%c\n", str[N - i - 1]);
    }
    for(int i = 0; i < n2; i++)
        printf("%c", str[n1 + i - 1]);
    return 0;
}
