#include <cstdio>
#include <cstring>

int main() {
    char str1[100], str2[100];
    bool HashTable[128] = { false }; //HashTable数组用来标记字符是否已被输出
    gets(str1);
    gets(str2);
    int len1 = strlen(str1); //获取长度
    int len2 = strlen(str2);
    //枚举第一个字符串中的每个字符
    for (int i = 0; i < len1; i++) {
        int j;
        char c1, c2;
        //枚举第二个字符串中的每个字符
        for (j = 0; j < len2; j++) {
            c1 = str1[i];
            c2 = str2[j];
            //如果是小写字母则转化为大写
            if (c1 >= 'a' && c1 <= 'z')
                c1 -= 32;
            if (c2 >= 'a' && c2 <= 'z')
                c2 -= 32;
            //如果c1在第二个字符串中出现则跳出
            if (c1 == c2)
                break;
        }
        if (j == len2 && HashTable[c1] == false) {
            printf("%c", c1); //在第二个字符串中未出现c1，且c1未被输出过
            HashTable[c1] = true;
        }
    }
    return 0;
}
