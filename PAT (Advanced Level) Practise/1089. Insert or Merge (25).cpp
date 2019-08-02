/**
* ������ģ���������͹鲢����Ĺ��̣�Ҫ����������׼ȷ��д�����־��������㷨�Ĵ���
*       ����Ϊ�˷���Ƚ���vector����������
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, temp;
    bool f1 = false, f2 = false;
    vector<int> a, b, t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        b.push_back(temp);
    }
    //��������
    t = a;
    for(int i = 1; i < n; i++) {
        temp = t[i];
        int j = i;
        while(j > 0 && temp < t[j - 1]) {
            t[j] = t[j - 1];
            j--;
        }
        t[j] = temp;
        if(f1 == true) {
            for(int k = 0; k < n; k++) {
                printf("%d", t[k]);
                if(k != n - 1)
                    printf(" ");
            }
            break;
        }
        if(f1 == false && t == b) {
            printf("Insertion Sort\n");
            f1 = true;
        }
    }
    //�鲢����
    t = a;
    for(int step = 2; step / 2 <= n; step *= 2) {
        for(int i = 0; i < n; i += step)
            sort(t.begin() + i, t.begin() + min(i + step, n));
        if(f2 == true) {
            for(int k = 0; k < n; k++) {
                printf("%d", t[k]);
                if(k != n - 1)
                    printf(" ");
            }
            break;
        }
        if(f2 == false && t == b) {
            printf("Merge Sort\n");
            f2 = true;
        }
    }
    return 0;
}
