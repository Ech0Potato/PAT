/**
* ����������N���ַ��������������׺
*       ��Ϊ���׺�����㣬�����Ƚ��ַ�����ת������ʹ��<algorithm>�µ�reverse()
*       ��Ϊ�ַ����к��ո����Բ�����cin��ѡ����getline
*       ͬʱscanf����NʱҪ���һ�����з�����ֹ������з���getline����
*       ����ʱ�������������һ���ַ��������п��������ԭ��
*       ˼·�����Ƚ���ȡ�ĵ�һ���ַ�����Ϊans������ÿ����һ������ans�Ƚ�
*       ������ͬ�ַ��ͽ�ȡ������µ�ans��������ans�ĳ���
*       ע���ж�ʱÿ�α���������ans��������str�н϶̵ĳ���
**/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    string ans, str;
    int anslen, strlen, minlen;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        strlen = str.size();
        reverse(str.begin(), str.end());
        if(i == 0) {
            ans = str;
            anslen = ans.size();
            continue;
        }
        minlen = min(anslen, strlen);
        for(int j = 0; j < minlen; j++) {
            if(ans[j] != str[j]) {
                ans = ans.substr(0, j);
                anslen = ans.size();
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if(anslen == 0)
        cout << "nai";
    else
        cout << ans;
    return 0;
}
