/**
* ����������ɱ��ȷ�����������ˣ�������˵���ߣ�����һ��������
*       ˼·���Ǳ���ö�٣�����i j�����ˣ������Ǽ���Ϊ˵���ߣ���ĿҪ������������ˣ�����Ŀ��ʾ��
*       ���������ж�ÿ�����Ƿ�˵�ѣ�������ɺ���˵����Ϊһ������һ�����˼�Ϊ����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;

int n, d[maxn], liewolves; //˵�ѵ�������
vector<int> liar; //˵����

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for(int i = 1; i <= n; i++) { //���� i jΪ����
        for(int j = i + 1; j <= n; j++) {
            liewolves = 0;
            liar.clear();
            for(int k = 1; k <= n; k++) { //����ÿһ����
                if(d[k] < 0 && abs(d[k]) != i && abs(d[k]) != j) { //�����ָ��ĳ�������˵���������˲�������Ϊ˵����
                    liar.push_back(k);
                    if(k == i || k == j)
                        liewolves++;
                } else if(d[k] > 0 && (d[k] == i || d[k] == j)) { //�����ָ��ĳ������ͨ���൫Ϊ�������ˣ�ҲΪ˵����
                    liar.push_back(k);
                    if(k == i || k == j)
                        liewolves++;
                }
            }
            if(liar.size() == 2 && liewolves == 1) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
