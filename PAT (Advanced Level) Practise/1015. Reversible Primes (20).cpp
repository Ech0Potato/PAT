/**
* ��������Ҫ�������������жϺͽ���ת����������λ��ת����һ��string��reverse����
*       ֵ��ע���������ⲻ�ǵ�����ԣ�����һ��while...EOF��д��
*       �㷨˼·������һ������������������Ĵ����ϲ�һ����ԭд����һ������ʱ����
*       �ĳ�����ĸ����һЩ����Ϊ�������õõ��������飬���跭ת����ֱ���۳˵õ��µ�ʮ����
**/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {
        if(n < 0)
            break;
        scanf("%d", &d);
        if(isPrime(n) == false) {
            printf("No\n");
        } else {
            //ʮ����תd����
            int t[111], num = 0;
            do {
                t[num++] = n % d;
                n = n / d;
            } while(n != 0);
            //d����תʮ����
            for(int i = 0; i < num; i++) {
                n = n * d + t[i];
            }
//			string s;
//			for(int i=num-1; i>=0; i--) {
//				s+=to_string(t[i]);
//			}
//			reverse(s.begin(),s.end());
//			n=stoi(s);
//			int m=0,product=1;
//			while(n!=0) {
//				m=m+(n%10)*product;
//				n=n/10;
//				product*=d;
//			}
            if(isPrime(n) == true)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
