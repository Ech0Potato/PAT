/**
* �����������������㣬��ģ�弴�ɣ��Ӽ��˳�д��һ���������Ǹ���ճ���ˣ�������Ϊ20�ֵ���о����Ǻܷ�ʱ��
*       ����һ��Ҫ������Ҫ��Ѹ�ٵذ�ģ��д����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef long long LL;

struct Fraction {
    LL up, down;
};

LL gcd(LL a, LL b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

Fraction reduction(Fraction f) {
    if(f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0) {
        f.down = 1;
    } else {
        LL d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}

void showFraction(Fraction f) {
    if(f.up < 0)
        printf("(");
    if(f.down == 1)
        printf("%lld", f.up);
    else if(abs(f.up) > f.down)
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld", f.up, f.down);
    if(f.up < 0)
        printf(")");
}

int main() {
    Fraction a, b, c1, c2, c3, c4;
    scanf("%lld/%lld", &a.up, &a.down);
    a = reduction(a);
    scanf("%lld/%lld", &b.up, &b.down);
    b = reduction(b);
    //�ӷ�
    c1.up = a.up * b.down + b.up * a.down;
    c1.down = a.down * b.down;
    c1 = reduction(c1);
    showFraction(a);
    printf(" + ");
    showFraction(b);
    printf(" = ");
    showFraction(c1);
    printf("\n");
    //����
    c2.up = a.up * b.down - b.up * a.down;
    c2.down = a.down * b.down;
    c2 = reduction(c2);
    showFraction(a);
    printf(" - ");
    showFraction(b);
    printf(" = ");
    showFraction(c2);
    printf("\n");
    //�˷�
    c3.up = a.up * b.up;
    c3.down = a.down * b.down;
    c3 = reduction(c3);
    showFraction(a);
    printf(" * ");
    showFraction(b);
    printf(" = ");
    showFraction(c3);
    printf("\n");
    //����
    c4.up = a.up * b.down;
    c4.down = a.down * b.up;
    c4 = reduction(c4);
    showFraction(a);
    printf(" / ");
    showFraction(b);
    printf(" = ");
    if(b.up == 0 && b.down == 1)
        printf("Inf"); //�Գ���Ϊ0��������
    else
        showFraction(c4);
    return 0;
}
