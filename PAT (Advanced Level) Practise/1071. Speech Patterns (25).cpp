/**
* ������ע��isalnum()��ʹ�ã��ж��Ƿ�Ϊ���ֻ���ĸ�����мǵô�дҪת��Сд��tolower������ʹ��
*       һ��ʼд��O(n^2)���㷨���ã���������WA����˼·�����⣬ֱ�ӱ���һ��ͺ�
*       ���㷨�Ŀӵ����ڣ�ÿ����ʱ�ַ�����պ���������һ���ַ����ǷǷ��ַ������ͳ��һ�����ַ����Ĵ���
*       ���ֻ�е��ʷǿ�ʱ��ͳ�ƴ���
**/

#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    int max = 0;
    string s, res;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            res += s[i];
        }
        if(!isalnum(s[i]) || i == s.size() - 1) {
            if(res != "")
                mp[res]++;
            res = ""; //���ﵼ�µĵ��ʿ���Ϊ��
        }
    }

//	for(int i=0; i<s.size(); i++) {
//		if(isalnum(s[i])) {
//			if(s[i]>='A'&&s[i]<='Z')
//				s[i]=tolower(s[i]); //�ȴ�дתСд
//			for(int j=i+1; j<s.size(); j++) {
//				if(!isalnum(s[j])) {
//					string temp = s.substr(i,j-i);
//					mp[temp]++;
//					i=j;
//					break;
//				}
//			}
//		}
//	}

    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it->second > max) {
            max = it->second;
            res = it->first;
        }
    }
    cout << res << " " << max << endl;
    return 0;
}
