/**
* �������������ҳ�����ֵ��ͬ�����֣���һ������ֻ��һ��������ķŵ��ڶ�������
*       ���Խ������С����������Ч����˳����Ϊ2*maxn
*       Ȼ����1 - maxn�ŵ�һ�����У���maxn+1 - 2*maxn�ŵڶ����У��ֱ��������
*       �����Ժ��-1���У���Ҫдi < count-1Ȼ�������count-1
*       ����д��if(i != count-1)  else  �����ӣ���ʱ�򷽱㴦�������е����
*       ���⻹��ͦ�õģ�˼·һ��Ҫ˳����Ҫ�������ڲ���ݵ�����ϸ�����
*       �����ڲ������ɧ����ֱ�Ӱ���ֺã�Ȼ����ݽ�����ͺ�
*       ��֮���ǲ�Ҫ̫��Ӳ����ģ�壬Ҫ���Լ���˼·��ģ��ֻ�ṩ������
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

bool isExist[maxn] = {false};

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = 2 * maxn;
    int begin, n;
    int address, data, next;
    scanf("%d %d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, cnt1 = 0, cnt2 = 0;
    while(p != -1) {
        if(isExist[abs(node[p].data)] == false) {
            isExist[abs(node[p].data)] = true;
            node[p].order = ++cnt1;
        } else {
            node[p].order = ++cnt2 + maxn;
        }
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int count = cnt1 + cnt2;
    for(int i = 0; i < count; i++) {
        if(i != cnt1 - 1 && i != count - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        else
            printf("%05d %d -1\n", node[i].address, node[i].data);
    }
    return 0;
}
