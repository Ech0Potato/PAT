/**
* ���������������к���Ϊ����洢����a[1]-a[3]�ĺͿ�����s[3]-s[0]����ʾ
*      ��Ȼ�ǵ����ģ������������������뵽����,�������⣬���ҵ�һ�����ڵ���m���Ҷ˵�
*      �ؼ����ڼ���upper_bound()�ĵ�������������s[right]-s[left-1]>=m�����Ե���������Ϊs[left-1]+m
*      ��һ��ѭ���ҳ���ӽ���ֵ���ڶ���ѭ����ÿ���������ֵ��������������ֵҪ��ʼ��Ϊһ������ֵ���Ҳ�����min()��������Ϊ���s[n]-s[n]=0
*      ע��ÿ��ѭ����ֻ��һ��+һ�ζ��֣���Ȼ�ᳬʱ��������������
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int d[maxn];
int s[maxn];

int main() {
	int n,m,sum=100000010;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
		s[i]=d[i]+s[i-1];
	}
	for(int i=1; i<=n; i++) {
		int pos = lower_bound(s+i,s+n+1,s[i-1]+m)-s; //���ֲ���s[i]-s[n]����һ��d[i]+...+d[n]=s[n]-s[i-1]��m��ֵ
//		sum=min(sum,s[pos]);
		if(s[pos]-s[i-1]==m) {
			sum=s[pos]-s[i-1];
			break;
		} else if(s[pos]-s[i-1]<sum && pos<=n) {
			sum=s[pos]-s[i-1];
		}
	}
	for(int i=1; i<=n; i++) {
		int pos = lower_bound(s+i,s+n+1,s[i-1]+sum)-s;
		if(s[pos]-s[i-1]==sum)
			printf("%d-%d\n",i,pos);
	}
	return 0;
}
