/**
* �����������ж�ÿλ�ַ���ת�����ֺ����жϷ�Χ��ѧ��stod��ʹ��
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int num = 0;
    double temp, ans = 0;
    string s;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> s;
        bool isnum = true, hp = false; //Ĭ�������֣�ô��С����
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == '-') //���������ĸ���
                continue;
            if(!isdigit(s[j]) && s[j] != '.') { //��������Ҳ����С����
                isnum = false;
                break;
            }
            if(s[j] == '.') {
                if(hp) { //���������������С����
                    isnum = false;
                    break;
                } else {
                    hp = true;
                    if(s.size() - j - 1 > 2) { //���С����󳬹���λ
                        isnum = false;
                        break;
                    }
                }
            }
        }
        if(isnum) {
            temp = stod(s);
            if(temp >= -1000 && temp <= 1000) {
                ans += temp;
                num++;
            } else
                cout << "ERROR: " << s << " is not a legal number" << endl;
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }
    if(num == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    if(num == 1)
        printf("The average of 1 number is %.2f\n", ans);
    if(num > 1)
        printf("The average of %d numbers is %.2f\n", num, ans / num);
    return 0;
}
