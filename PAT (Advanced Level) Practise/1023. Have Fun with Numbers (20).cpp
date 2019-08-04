/**
* �������������˷�����������long long���͵ı�������11��
*       Ȼ����ģ�壬һ��AC��Ҫ������д��Ҫ��
*       Ψһһ���ӵ㣬��Ȼ˵�˲��ᳬ��20λ�����뵽�˻����ܻ�20*20����������û�¾Ϳ����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

struct bign {
    int d[maxn];
    int len;
    bign() {
        fill(d, d + maxn, 0);
        len = 0;
    }
};

bign strToBign(string s) {
    bign n;
    for(int i = s.size() - 1; i >= 0; i--)
        n.d[n.len++] = s[i] - '0';
    return n;
}

bign multiBign(bign n, int m) {
    bign t;
    int carry = 0;
    for(int i = 0; i < n.len; i++) {
        int temp = n.d[i] * m + carry;
        t.d[t.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0) {
        t.d[t.len++] = carry % 10;
        carry /= 10;
    }
    return t;
}

void print(bign n) {
    for(int i = n.len - 1; i >= 0; i--)
        printf("%d", n.d[i]);
}

int h1[10], h2[10];

int main() {
    bool flag = true;
    string s;
    cin >> s;
    bign n = strToBign(s);
    bign m = multiBign(n, 2);
    for(int i = 0; i < n.len; i++)
        h1[n.d[i]]++;
    for(int i = 0; i < m.len; i++)
        h2[m.d[i]]++;
    for(int i = 0; i < 10; i++) {
        if(h1[i] != h2[i])
            flag = false;
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    print(m);
    return 0;
}

//typedef long long LL;
//const int maxn = 10;
//
//int h1[maxn]= {0};
//int h2[maxn]= {0};
//
//int main() {
//	bool flag = true;
//	LL n,m;
//	scanf("%lld",&n);
//	m=n*2;
//	string s1,s2;
//	s1=to_string(n);
//	s2=to_string(m);
//	for(int i=0; i<s1.size(); i++)
//		h1[s1[i]-'0']++;
//	for(int i=0; i<s2.size(); i++)
//		h2[s2[i]-'0']++;
//	for(int i=0; i<maxn; i++) {
//		if(h1[i]!=h2[i]) {
//			flag=false;
//			break;
//		}
//	}
//	if(flag)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	printf("%lld",m);
//	return 0;
//}
