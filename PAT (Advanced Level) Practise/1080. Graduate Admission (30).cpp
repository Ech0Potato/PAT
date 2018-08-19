/**
* ����������ѹ���⣬д�˴��40���ӣ�����22�֣��������Ե�û��ͨ��������һ�������г�ʱ
*       ������˼·��࣬�����������������ṹ�����飬�Ұ�����һ����vector����
*       �о�˼·������˳�������ǻᳬʱ��Ҳ�Ҳ�����ʱ���ġ�����
*       ������߽�����޸�����뻹��22�֣��Ժ�����Ҫ��vector��Ҫ͵�����ϡ�����
*       ��ʱ���������Ȳ���д�������ṹ��İ汾�ˣ��Լ�����OK���Ͼ������ѹ��ĸ��ʲ��󣬴����
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxm = 110;
const int maxk = 6;

struct application {
    int id;
    int ge, gi, gf;
    int rank;
    int per[maxk];
} app[maxn];

int sch[maxm];
vector<int> adm[maxm];

bool cmp(application a, application b) {
    if(a.gf != b.gf)
        return a.gf > b.gf;
    else if(a.ge != b.ge)
        return a.ge > b.ge;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d", &sch[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &app[i].ge, &app[i].gi);
        app[i].id = i;
        app[i].gf = (app[i].ge + app[i].gi) / 2;
        for(int j = 0; j < k; j++)
            scanf("%d", &app[i].per[j]);
    }
    sort(app, app + n, cmp);
    app[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(app[i].gf == app[i - 1].gf && app[i].ge == app[i - 1].ge)
            app[i].rank = app[i - 1].rank;
        else
            app[i].rank = i + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int temp = app[i].per[j];
            if(adm[temp].size() != 0) {
                if((sch[temp] > 0) || (sch[temp] <= 0 && app[i].rank == app[adm[temp][adm[temp].size() - 1]].rank)) {
                    adm[temp].push_back(app[i].id);
                    sch[temp]--;
                    break;
                }
            } else {
                if(sch[temp] > 0) {
                    adm[temp].push_back(app[i].id);
                    sch[temp]--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(adm[i].size() != 0) {
            sort(adm[i].begin(), adm[i].end());
            for(vector<int>::iterator it = adm[i].begin(); it != adm[i].end(); it++) {
                if(it != adm[i].end() - 1)
                    printf("%d ", *it);
                else
                    printf("%d\n", *it);
            }
        } else {
            printf("\n");
        }
    }
    return 0;
}
