/**
* ��������Ŀ������Χ��[-2^63,2^63]����long long�����ݵķ�ΧΪ[-2^63,2^63)
*       ����������ӿ��ܻ��������������������ֱ���жϴ�С�����
*       ����֪��A>0,B>0,A+B<0ʱΪ�������A<0,B<0,A+B>=0ʱΪ�������Ӧ��ֱ�Ӽ�ס���У�
*       û����������ֱ���жϼ���
*       ע��A+B��Ҫ��ŵ�long long�ͱ����вſ���C���бȽϣ���������if��������ֱ�������C�Ƚ�
*       �������ɺ�������ݴ�����Ȼ��Ҳ��֪��Ϊɶ�����ס�ͺã�long long�ͱȽϵ����⣩
**/

#include <cstdio>
typedef long long LL;

int main() {
    int T;
    LL A, B, res, C;
    bool flag;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        res = A + B;
        if(A > 0 && B > 0 && res < 0)
            flag = true;
        else if(A < 0 && B < 0 && res >= 0)
            flag = false;
        else if(res > C)
            flag = true;
        else
            flag = false;
        if(flag == true)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
