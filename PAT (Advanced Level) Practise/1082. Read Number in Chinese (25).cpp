/**
* �����������ж��Ƿ����������Ȼ���ÿһλ�ֱ��жϣ�Ҫϰ�������ҹ��ɵķ��� 
*       �����0��ض������֣�����λ���ж��Ƿ������λ�����������ǧ��ʮ��ǰ��һ�����ز�Ϊ0�������ж�����λ��Ҫ׼ȷ
*       ���Ϊ0�������һλ���жϣ���ǰλ�������һλ����һλ��0�����
*       ��һ��vector�洢��������Է��㴦��ո�
*       ������Ҫ�Ե���һ��0��������
**/
#include <bits/stdc++.h>
using namespace std;

string num[10]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> ans;

int main() {
	string s;
	cin>>s;
	if(s=="0")
		cout<<"ling";
	if(s[0]=='-') {
		cout<<"Fu ";
		s= s.substr(1,s.size()-1);
	}
	for(int i=0; i<s.size(); i++) {
		int d = s[i]-'0';
		if(d!=0) {
			ans.push_back(num[d]);
			if(s.size()-i==8 || s.size()-i==4)
				ans.push_back("Qian");
			if(s.size()-i==7 || s.size()-i==3)
				ans.push_back("Bai");
			if(s.size()-i==6 || s.size()-i==2)
				ans.push_back("Shi");
		} else {
			if(i!=s.size()-1&&s[i+1]!='0')
				ans.push_back(num[0]);
		}
		if(s.size()-i==9)
			ans.push_back("Yi");
		if(s.size()-i==5)
			ans.push_back("Wan");
	}
	for(vector<string>::iterator it = ans.begin(); it!=ans.end(); it++) {
		cout<<*it;
		if(it!=ans.end()-1)
			cout<<" ";
	}
	return 0;
}
