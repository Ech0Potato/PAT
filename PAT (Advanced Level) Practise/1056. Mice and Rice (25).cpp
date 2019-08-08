/**
* �������ö��м�¼�����ǵ���ţ��Ȱ�˳����ӣ�����μ���һ�ֱ���
*       ÿ��ѭ������������Ҫ�ȼ���������Ȼ��ö��ÿһ��ѡ����������
*       �˹����н�ÿֻ���󶼳��ӣ�������ʼ��Ϊ����+1��Ȼ����бȽ�
*       �������Ľ���������һ�֣����ٴ���ӣ���������̭��������Ϊ��ǰ����+1����
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

struct mouse {
    int weight;
    int rank;
} mice[maxn];

int main() {
    int np, ng, id;
    queue<int> q;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &mice[i].weight);
    }
    for(int i = 0; i < np; i++) {
        scanf("%d", &id);
        q.push(id);
    }
    int join = np, group; //��ǰ�ֲ�����������ǰ������
    while(!q.empty()) {
        if(q.size() == 1) { //ֻʣһֻ����ʱ����������Ϊ1��ѭ������
            mice[q.front()].rank = 1;
            break;
        }
        if(join % ng == 0)
            group = join / ng;
        else
            group = join / ng + 1;
        for(int i = 0; i < group; i++) {
            int max = q.front();
            for(int j = 0; j < ng; j++) {
                //�������һ������������ng���������ǰ����֮ǰ�μӸ��ֵ�������������joinʱ�˳�ѭ��
                if(i * ng + j >= join)
                    break;
                int front = q.front();
                q.pop();
                mice[front].rank = group + 1; //���в�������������ʼ��Ϊ����+1
                if(mice[front].weight > mice[max].weight)
                    max = front;
            }
            q.push(max);
        }
        join = group; //ÿ�����һֻ����һ�ֲμӵļ�Ϊ��ǰ�ֵ�����
    }
    for(int i = 0; i < np; i++) {
        printf("%d", mice[i].rank);
        if(i != np - 1)
            printf(" ");
    }
    return 0;
}
