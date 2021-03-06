/**
* 分析：找出键盘上哪个键位坏了，实质也是比较两个字符串找重复出现的字母，用散列即可
*       根据实际问题，此题输出要同时判定大小写字母（一个键位）均出现过
*       注意题目要求最后输出全为大写字母，每个坏键只输出一次
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
    for(int i = 0; i < s2.size(); i++)
        hash[s2[i]] = true;
    for(int i = 0; i < s1.size(); i++) {
        if(hash[s1[i]] == false) {
            if(s1[i] >= 97 && s1[i] <= 122) {
                printf("%c", s1[i] - 32);
                hash[s1[i]] = true;
                hash[s1[i] - 32] = true;
            } else if(s1[i] >= 65 && s1[i] <= 90) {
                printf("%c", s1[i]);
                hash[s1[i]] = true;
                hash[s1[i] + 32] = true;
            } else {
                printf("%c", s1[i]);
                hash[s1[i]] = true;
            }
        }
    }
    return 0;
}
