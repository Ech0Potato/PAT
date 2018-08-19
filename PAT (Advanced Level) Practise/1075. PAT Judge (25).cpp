/**
* ������ʱ�������45min��������ˣ�����ֻ����19�֣�������3�ֵĲ��Ե�û��ͨ��
*       ���ò��ˣ���ſ��Խ��ܣ�
*       ����Ҫѧϰ�ڽṹ���г�ʼ������ķ�������Ȼ�����û���ã����Ժ�����õ�
*       ������<cstring>��memset��ѭ����ʼ������Ȼû���ԣ����Ҿ���fill���ܱ�memset��һЩ
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxk = 6;

struct User {
    int id, total, perfect, rank;
    int score[maxk];
    int flag[maxk];
    int pernum[maxk];
} user[maxn];

bool cmp(User a, User b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else if(a.id != b.id)
        return a.id < b.id;
}

int main() {
    int n, k, m;
    int id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    int mark[k];
    for(int i = 0; i < k; i++)
        scanf("%d", &mark[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &id, &num, &score);
        num = num - 1;
        user[id].id = id;
        if(user[id].flag[num] == 0) {
            if(score != -1) {
                user[id].flag[num] = 1;
                user[id].score[num] = score;
            } else {
                user[id].flag[num] = 1;
            }
        } else {
            if(user[id].score[num] < score)
                user[id].score[num] = score;
        }
        if(user[id].score[num] == mark[num])
            user[id].pernum[num] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            user[i].total += user[i].score[j];
            if(user[i].pernum[j] == 1)
                user[i].perfect++;
        }
    }
    sort(user, user + maxn, cmp);
    user[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(user[i].total == user[i - 1].total)
            user[i].rank = user[i - 1].rank;
        else
            user[i].rank = i + 1;
    }
    for(int i = 0; i < n; i++) {
        if(user[i].total != 0) {
            printf("%d %05d %d", user[i].rank, user[i].id, user[i].total);
            for(int j = 0; j < k; j++) {
                if(user[i].flag[j] != 0)
                    printf(" %d", user[i].score[j]);
                else
                    printf(" -");
            }
            printf("\n");
        }
    }
    return 0;
}
