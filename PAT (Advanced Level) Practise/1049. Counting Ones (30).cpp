/**
* ������������22��Ѫ׬����������TLE��ʣ��8�ֿ϶����������ڵ��㷨
*       ����������㷨������Ҫ���շָ���λ���ӵ͵��߷ֳ���ǰλ�͵�ǰλ��ߵ������ұߵ���
*       Ȼ����ݵ�ǰλ��������ۣ����������дһ����һ������ҹ��ɣ�����ǰλΪ0Ϊ1λ����1����ʱ�ֱ��ж��������
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 1, ans = 0;
    int left, now, right;
    scanf("%d", &n);
    while(n / a != 0) {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if(now == 0) {
            ans += left * a;
        } else if(now == 1) {
            ans += left * a + 1 + right;
        } else {
            ans += (left + 1) * a;
        }
        a *= 10;
    }
    printf("%d\n", ans);
    return 0;
}








//int main() {
//	int n,cnt=0;
//	scanf("%d",&n);
//	for(int i=1; i<=n; i++) {
//		string s = to_string(i);
//		for(int i=0; i<s.size(); i++) {
//			if(s[i]=='1')
//				cnt++;
//		}
//	}
//	printf("%d",cnt);
//	return 0;
//}
