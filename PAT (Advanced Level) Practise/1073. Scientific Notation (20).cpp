/**
* ������������������ţ�Ȼ���ҵ�E��λ��pos��ͬʱ���ݴ����С��λ�ĸ���n
*       ���Ž�ԭ�ַ�����Ϊ������ָ�������֣�ͬʱ�������ַ���ȥ��С���㣬��ָ���ַ���תΪ����exp
*       Ȼ�����E����ķ����������ֱ����
*       ��Ϊ-�������Ϊ0.0������0XXXX�������0.��Ȼ�����exp-1��0��������ȥ��С����ĵ����ַ���
*       ȥ��С����ĵ����ַ�������substr��s[0]ƴ�ӻ��
*       ��Ϊ+������Ҫ�ж�С�����λ�ã�����n��exp�Ĺ�ϵ���
*       ��������԰��������д�������ݹ۲�ó����ɣ��ַ���������ģ�⣬�ҹ��ɾ����ˣ�����ÿһλ����ô����� 
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, s1, s2;
    int pos, exp, n; //E��λ�� ָ�� С��λ����
    cin >> str;
    if(str[0] == '-')
        cout << '-';
    pos = str.find("E");
    n = pos - 3;
    int len = pos - 1;
    s1 = str.substr(1, len);
    s1 = s1[0] + s1.substr(2, s1.size() - 2);
    s2 = str.substr(pos + 2, str.size() - pos - 2);
    exp = atoi(s2.c_str());
    if(str[pos + 1] == '-') {
        cout << "0.";
        for(int i = 0; i < exp - 1; i++)
            cout << "0";
        cout << s1;
    } else {
        if(exp == n) {
            cout << s1;
        }
        if(exp > n) {
            cout << s1;
            for(int i = 0; i < exp - n; i++)
                cout << "0";
        }
        if(exp < n) {
            for(int i = 0; i <= exp; i++)
                cout << s1[i];
            cout << ".";
            for(int i = exp + 1; i < s1.size(); i++)
                cout << s1[i];
        }
    }
    return 0;
}
