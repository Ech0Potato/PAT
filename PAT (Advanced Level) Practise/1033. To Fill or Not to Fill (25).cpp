/**
* ������д�˺���ô�ð���д�����ⲻҪ�ż�����д��һ��Ҫ�����ÿһ�������˼·
*       ˼άҪ�죬��������Ѹ��debug
*       ��������â�Ƿֲ���Ӧ�������ѵ�һ��̰���ˣ���Ȼʱ��õ��ô��Լ�����˼·AC���� 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;

struct station {
	double price; //����
	double distance; //�����ݵľ���
} s[maxn];

bool cmp(station a,station b) {
	return a.distance<b.distance;
}

int main() {
	double c,d,a; // ���䴢����Ŀ�ľ��롢ÿ��λ�����ܵľ���
	int n; //����վ����
	double nowTank=0,needTank=0,cost=0;
	scanf("%lf%lf%lf%d",&c,&d,&a,&n);
	double A = c*a; //����һ�������ܵľ���
	for(int i=0; i<n; i++) {
		scanf("%lf%lf",&s[i].price,&s[i].distance);
	}
	s[n].price=0,s[n].distance=d; //��Ŀ�ĵص����ͼ�Ϊ0������Ϊd�ļ���վ�������
	sort(s,s+n,cmp);
	if(s[0].distance==0) {
		for(int i=0; i<n; i++) {
			bool f1=false,f2=false;
			int low = i+1;
			for(int j=i+1; j<=n; j++) {
				if(s[j].distance-s[i].distance<=A) {
					f1=true;
					if(s[j].price<s[i].price) {
						f2=true;
						needTank=(s[j].distance-s[i].distance)/a;
						if(nowTank<needTank) {
							cost+=s[i].price*(needTank-nowTank);
							nowTank=needTank;
						}
						i=j-1;
						break;
					}
					if(s[j].price<s[low].price)
						low=j;
				}
			}
			if(f1&&f2) {
				nowTank-=needTank;
			} else if(f1&&!f2) {
				needTank=(s[low].distance-s[i].distance)/a;
				cost+=s[i].price*(c-nowTank);
				nowTank=c;
				i=low-1;
				nowTank-=needTank;
			} else {
				printf("The maximum travel distance = %.2f\n",s[i].distance+A);
				return 0;
			}
		}
	} else {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	printf("%.2f\n",cost);
	return 0;
}
