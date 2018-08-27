/**
* 分析：图的DFS遍历第一题，思路算是理清了
*       要能迅速修改DFS模板，想好需要得出的数据，这些变量作为DFS的参数，同时要使用引用
*       这道题要注意处理好字符串和编号的关系，学会在输入时计算点权，而计算边权时要记得删边防止重复计算
**/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;

int n, k, numPerson = 0; //总人数为numPerson，则每个人的编号为0 ~ numPeople-1
int G[maxn][maxn];
int weight[maxn];
bool visit[maxn];

map<int, string> intTostr; //编号->姓名
map<string, int> strToint; //姓名->编号
map<string, int> gang; //head姓名->成员人数（因为结果输出格式是这样的，同时头目数量也代表团伙数量）

int getInt(string str) {
    if(strToint.find(str) != strToint.end()) {
        return strToint[str];
    } else {
        strToint[str] = numPerson;
        intTostr[numPerson] = str;
        return numPerson++; //返回numHead并将人数+1
    }
}

//需要统计的变量使用引用&
void DFS(int now, int &head, int &numMember, int &totalWeight) {
    numMember++;
    visit[now] = true;
    if(weight[now] > weight[head])
        head = now;
    for(int i = 0; i < numPerson; i++) {
        if(G[now][i] > 0) {
            totalWeight += G[now][i];
            G[now][i] = G[i][now] = 0; //删除这条边，防止重复计算
            if(visit[i] == false)
                DFS(i, head, numMember, totalWeight);
        }
    }
}

void DFSTrave() {
    for(int i = 0; i < numPerson; i++) {
        if(visit[i] == false) {
            int head = i, numMember = 0, totalWeight = 0;
            DFS(i, head, numMember, totalWeight);
            if(numMember > 2 && totalWeight > k)
                gang[intTostr[head]] = numMember;
        }
    }
}

int main() {
    int time;
    int id1, id2;
    string name1, name2;
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        cin >> name1 >> name2 >> time;
        id1 = getInt(name1);
        id2 = getInt(name2);
        weight[id1] += time;
        weight[id2] += time;
        G[id1][id2] += time;
        G[id2][id1] += time;
    }
    DFSTrave(); //写完了别忘了在主函数遍历啊。。。
    cout << gang.size() << endl;
    for(map<string, int>::iterator it = gang.begin(); it != gang.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
