/**
* 分析：实质是字符串比对问题，用hash，没难度，注意统计数量即可
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    int hash[128] = {0};
    int count = 0, lose = 0;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size(); i++) {
        hash[s1[i]]++;
    }
    for(int i = 0; i < s2.size(); i++) {
        if(hash[s2[i]] > 0) {
            hash[s2[i]]--;
            count++;
        } else {
            lose++;
        }
    }
    if(count == s2.size())
        printf("Yes %d", s1.size() - count);
    else
        printf("No %d", lose);
    return 0;
}
