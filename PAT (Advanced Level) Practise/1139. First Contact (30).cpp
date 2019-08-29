/**
* ������ģ�⣬�ӵ�������
*       һ�Ƕ���0000��-0000��int���ն���0������Ҫ���ַ������룬��0��������
*       �����ж�ͬ�Ե�ʱ�����ֱ�����������ǲ�����Ϊ���
*       д�ñȽϸ��ӣ��еĴ��а��Ա���ͬ���Ա�ͬ�棬���Լ��ٴ�������˼·��һ����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;

int g[maxn][maxn];
set<int> boy, girl;
vector<pair<int, int> > ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int n, m, k, a, b;
    string sa, sb;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        cin >> sa >> sb;
        a = stoi(sa), b = stoi(sb);
        g[abs(a)][abs(b)] = g[abs(b)][abs(a)] = 1;
        if(a > 0)
            boy.insert(a);
        else
            girl.insert(a);
        if(b > 0)
            boy.insert(b);
        else
            girl.insert(b);
        if(sa == "0000")
            boy.insert(a);
        else if(sa == "-0000")
            girl.insert(a);
        if(sb == "0000")
            boy.insert(b);
        else if(sb == "-0000")
            girl.insert(b);

    }
    scanf("%d", &k);
    while(k--) {
        cin >> sa >> sb;
        a = stoi(sa), b = stoi(sb);
        ans.clear();
        if(a > 0 && b < 0) { //��Ů
            for(auto it = boy.begin(); it != boy.end(); it++) {
                for(auto jt = girl.begin(); jt != girl.end(); jt++) {
                    int c = *it, d = *jt;
                    if(g[abs(a)][abs(c)] == 1 && g[abs(c)][abs(d)] == 1 && g[abs(d)][abs(b)] == 1)
                        ans.push_back({abs(c), abs(d)});
                }
            }
        } else if(a < 0 && b > 0) { //Ů��
            for(auto it = girl.begin(); it != girl.end(); it++) {
                for(auto jt = boy.begin(); jt != boy.end(); jt++) {
                    int c = *it, d = *jt;;
                    if(g[abs(a)][abs(c)] == 1 && g[abs(c)][abs(d)] == 1 && g[abs(d)][abs(b)] == 1)
                        ans.push_back({abs(c), abs(d)});
                }
            }
        } else if(a > 0 && b > 0) { //����
            for(auto it = boy.begin(); it != boy.end(); it++) {
                for(auto jt = boy.begin(); jt != boy.end(); jt++) {
                    int c = *it, d = *jt;
                    if(g[abs(a)][abs(c)] == 1 && g[abs(c)][abs(d)] == 1 && g[abs(d)][abs(b)] == 1 && a != d && c != b)
                        ans.push_back({abs(c), abs(d)});
                }
            }
        } else if(a < 0 && b < 0) { //ŮŮ
            for(auto it = girl.begin(); it != girl.end(); it++) {
                for(auto jt = girl.begin(); jt != girl.end(); jt++) {
                    int c = *it, d = *jt;
                    if(g[abs(a)][abs(c)] == 1 && g[abs(c)][abs(d)] == 1 && g[abs(d)][abs(b)] == 1 && abs(a) != abs(d) && abs(c) != abs(b))
                        ans.push_back({abs(c), abs(d)});
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(auto it : ans)
            printf("%04d %04d\n", it.first, it.second);
    }
    return 0;
}
