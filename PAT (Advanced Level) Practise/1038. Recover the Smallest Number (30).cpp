/**
* �����������������㷨˼·̫ţ���ˣ�30�ֵ���20���д���AC
*      ע����Ҫ����ȫ��Ϊ0�����
*      ������Ϊ���8λ�������Բ��ܶ�����ȥǰ��0��ֱ�Ӷ��ַ���
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

string s[maxn];

bool cmp(string a,string b) {
	return a+b<b+a;
}

int main() {
	int n;
	string str;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0; i<n; i++)
		str+=s[i];
	while(str.size()!=0&&str[0]=='0') {
		str.erase(str.begin());
	}
	if(str.size()==0)
		cout<<0;
	else
		cout<<str;
	return 0;
}
