/**
* �����������ķ������9λ�����ڵ��������е��ѣ��������岻�󣬿�������������ˣ�������ʱ��
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}; //num[0]="ling",...
string wei[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"}; //Wei[0]="Shi",...

int main() {
    string str;
    cin >> str; //���ַ�����ʽ��������
    int len = str.size();
    int left = 0, right = len - 1; //left��right�ֱ�ָ���ַ�����βԪ��
    if(str[0] == '-') {
        cout << "Fu";
        left++; //������left����1λ
    }
    while(left + 4 <= right) {
        right -= 4; //��rightÿ������4λ��ֱ��left��right��ͬһ��
    }
    while(left < len) { //ѭ��ÿ�δ������ֵ�һ��(4λ��С��4λ)
        bool flag = false; //flag==false��ʾû���ۻ���0
        bool isPrint = false; //isPrint==false��ʾ�ý�û����������е�λ
        while(left <= right) { //�������Ҵ���������ĳ�ڵ�ÿһλ
            if(left > 0 && str[left] == '0') { //�����ǰλΪ0
                flag = true;
            } else { //�����ǰλ��Ϊ0
                if(flag == true) { //��������ۻ���0
                    printf(" ling");
                    flag = false;
                }
                if(left > 0) { //ֻҪ������λ���������ţ��������ÿһλǰ��Ҫ����ո�
                    cout << " ";
                }
                cout << num[str[left] - '0']; //�����ǰλ����
                isPrint = true; //�ý�������һλ�����
                if(left != right) { //ĳ���г��˸�λ�⣬����Ҫ���ʮ��ǧ
                    cout << " " << wei[right - left - 1];
                }
            }
            left++; //left����1λ
        }
        if(isPrint == true && right != len - 1) { //ֻҪ���Ǹ�λ������������
            cout << " " << wei[(len - 1 - right) / 4 + 2];
        }
        right += 4; //right����4λ�������һ��
    }
    return 0;
}
