/**
* ���������Ƽ��⣬ʮ�ּ򵥡��������ǻ��и��ֿ�
*       ��Ŀ��˵�������������ǽ������Ϊlen/2������Ҫ��ȡ��
*       ��������Ϊ0�����Ի��и������
*       �ж������в�����0Ҫд������ʽǰ��
**/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    string s, s1, s2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length();
        s1 = s.substr(0, len / 2);
        s2 = s.substr(len / 2, len / 2);
        int num = stoi(s), a = stoi(s1), b = stoi(s2);
        if((a * b) != 0 && num % (a * b) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
