/**
* ������̰�ĵ�һ�⣬�����ѣ�15����AC 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

struct Mooncake {
	double sum; //�ܼ�
	double num; //���
	double price; //����
} m[maxn];

bool cmp(Mooncake a,Mooncake b) {
	return a.price>b.price;
}

int main() {
	int n;
	double d;
	double p = 0;
	scanf("%d%lf",&n,&d);
	for(int i=0; i<n; i++) {
		scanf("%lf",&m[i].num);
	}
	for(int i=0; i<n; i++) {
		scanf("%lf",&m[i].sum);
		m[i].price = m[i].sum/m[i].num;
	}
	sort(m,m+n,cmp);
	for(int i=0; i<n; i++) {
		if(m[i].num>=d) {
			p+=m[i].price*d;
			break;
		} else {
			p+=m[i].price*m[i].num;
			d-=m[i].num;
		}
	}
	printf("%.2f\n",p);
	return 0;
}
