/**
* ��������Ϊ������С��ֻ��169�����Բ��ô�������ݽ���Ԥ����
*       ������ѵ�����Ԥ��������ʱ�������ʽ�Ŀ��ƣ�����֮ǰ��д��ֻ�ܵ�16�֣��������÷ֵ㲻֪��������
*       �ĳ������д����ͨ����ע��ѧϰ����Ԥ�������ݵķ�ʽ
*       ��סcctype��isdigit��ʹ�ã����������ж��Ƿ�Ϊ����
*       �о�������Ҫ���ַ�������ʹ�������map������
**/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

string unitdigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}; //��λ����
string tendigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; //ʮλ����

string numtostr[170]; //���͵��ַ�����ӳ�䣬������ת��Ϊ������
map<string, int> strtonum; //�ַ��������͵�ӳ�䣬��������ת��Ϊ����

//�����д��
void init() {
    for(int i = 0; i < 13; i++) {
        //��λΪ[0,12]��ʮλΪ0
        numtostr[i] = unitdigit[i];
        strtonum[unitdigit[i]] = i;
        //ʮλΪ[0,12]����λΪ0
        numtostr[i * 13] = tendigit[i];
        strtonum[tendigit[i]] = i * 13;
    }
    //ʮλ
    for(int i = 1; i < 13; i++) {
        //��λ
        for(int j = 1; j < 13; j++) {
            string str = tendigit[i] + " " + unitdigit[j]; //������
            numtostr[i * 13 + j] = str; //����->������
            strtonum[str] = i * 13 + j; //������->����
        }
    }
}

////���Ԥ��������
//void init() {
//    //�������͵��ַ�����ת��
//    for(int i = 0; i < 170; i++) {
//        if(i >= 0 && i <= 12) {
//            numtostr[i] = unitdigit[i];
//        } else if(i % 13 != 0) {
//            numtostr[i] = tendigit[i / 13];
//            numtostr[i] += " " + unitdigit[i % 13];
//        } else {
//            numtostr[i] = tendigit[i / 13];
//        }
//    }
//    //�����ַ��������͵�ת��
//    for(int i = 0; i < 170; i++) {
//        if(i >= 0 && i <= 12) {
//            strtonum[unitdigit[i]] = i;
//        } else if(i % 13 != 0) {
//            strtonum[tendigit[i / 13] + " " + unitdigit[i % 13]] = i;
//        } else {
//            strtonum[tendigit[i / 13]] = i;
//        }
//    }
//}

int main() {
    init();
    int n;
    string str;
    scanf("%d\n", &n);
    while(n--) {
        getline(cin, str);
        if(isdigit(str[0])) {
            int num = 0;
            for(int i = 0; i < str.size(); i++) {
                num = num * 10 + str[i] - '0';
            }
            cout << numtostr[num] << endl;
        } else {
            cout << strtonum[str] << endl;
        }
    }
    return 0;
}
