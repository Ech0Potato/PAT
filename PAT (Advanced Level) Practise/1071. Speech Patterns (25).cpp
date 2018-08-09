/**
* ��������Ҫ��ע��һ�㣬resΪ��ʱmapҲ��ͳ�������
*       ������������Ч�ַ�ʱ��res[]�Ĵ����ͻ�����
*       �����Ҫ��һ���жϣ���ǰ���ʷǿ�ʱ��ͳ�ƴ���
*       ��Ҫע����ַ���ĩβ�������У�����ĩβ��ʹ����Ч����ҲҪ����ǰ��resͳ�ƽ�map
*       ������ѧϰcctype�ļ���isalnum��ʹ�ã����Խ�ʡ����������
**/

#include <cstdio>
#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string str, res;
    map<string, int> mp;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++) {
        if(isalnum(str[i])) {
            str[i] = tolower(str[i]);
            res += str[i];
        }
        if(!isalnum(str[i]) || i == str.size() - 1) {
            if(res.size() != 0)
                mp[res]++;
            res = "";
        }
    }
    int maxn = 0;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second > maxn) {
            maxn = it->second;
            res = it->first;
        }
    }
    cout << res << " " << maxn << endl;
    return 0;
}
