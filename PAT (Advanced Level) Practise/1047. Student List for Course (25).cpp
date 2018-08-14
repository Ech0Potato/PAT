/**
* ������ѧ���ö�ά�����ʾm������Ϊn���ַ�����char[m][n]
*       �о����ֶ�ά�������������char�����ӳ�䣬Ҫ�������
*       �������⣬��Ҫ����Ŀ��nameĩβ�������Ի��Ǹ�����û���κ�����
**/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxM = 2510;

char name[maxn][5]; //maxn������Ϊ5��char���飬name[i]��ʾ��i����������ѧ���������һλ������û��ϵ��������˳���й�
vector<int> courses[maxM]; //courses[i]��ʾѡ��i�ſε�ѧ�����

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0; //���ֵ�������
}

int main() {
    int n, k;
    int count, courseID;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", &name[i], &count);
        for(int j = 0; j < count; j++) {
            scanf("%d", &courseID);
            courses[courseID].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for(int j = 0; j < courses[i].size(); j++)
            printf("%s\n", name[courses[i][j]]);
    }
    return 0;
}
