/**
* ���㣺�ַ�������
* ��������������
*       ע����while��д����������������ʱ��Ҫ��������0�����������
*       �Լ�����ĿҪ��ĩβ��Ҫ����
**/

#include <cstdio>

int main() {
    int a, b, sum;
    int num[10];
    int len = 0; //len���sum�ĳ���
    scanf("%d%d", &a, &b);
    sum = a + b; //��a+b��ֵ��sum
    if(sum < 0) {
        //sumΪ����ʱ��������Ų�ȡsum���෴��
        printf("-");
        sum = -sum;
    }
    if(sum == 0)
        num[len++] = 0; //sumΪ0ʱ���⴦��
    //��sum��������num[]�У�����sum�ĵ�λ��ŵ�num[]�ĵ�λ
    while(sum) {
        //��sum��ĩλsum%10��ŵ�num[len]��Ȼ��len++
        num[len++] = sum % 10;
        sum /= 10; //ȥ��sum��ĩλ
    }
    for(int k = len - 1; k >= 0; k--) { //�Ӹ�λ��ʼ���
        printf("%d", num[k]);
        if(k > 0 && k % 3 == 0)
            printf(","); //ÿ3λһ�����ţ����һλ����
    }
    return 0;
}
