/**
* ���������������ַ������ڵ�һ���ַ�����ɾ���ڶ����ַ����г��ֹ��������ַ����뵽��ɢ��
*       ע����ⲻ����scanf����Ϊscanf��ȡ�ַ������ÿո���Ϊ�ضϱ�־���޷�һ�ζ�ȡһ���д��пո���ַ���
*       ����Ϊgets�����ã�����ʹ��getline�����ͬʱ��string���char���飬��string.size()���strlen(char[])
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    bool hash[128] = {false};
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.size(); i++) {
        hash[s2[i]] = true;
    }
    for(int i = 0; i < s1.size(); i++) {
        if(hash[s1[i]] == false)
            printf("%c", s1[i]);
    }
    return 0;
}
