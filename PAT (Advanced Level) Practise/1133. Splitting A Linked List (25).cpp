/**
* ����������32���ӣ��������һ���Ĵ�������ֻ����23�֣�����һ��2�ֵĵ�û�õ�������
*       ����ԭ������Ǹ������������ʽ���󣬲������ҳ������������
*       Ȼ�������ж������ʽ������bool�������Ƿ��һ������������Ƿ��и������Ƿ���С��K����
*       ��Ϊ��һ��bool����������������Ƿ��һ��������ݣ��ɹ�A����Ŀ
*       ��Ϊ����������������ʽʵ���϶������ǲ��ǵ�һ������йأ�������ʲô���͵����ݣ������ʽ��һ����
*       �ж�ǰ����ʲô���ݷ������ӻ������⣬��Ȼ�����ʽһ������û�б�Ҫ�ֱ�����ÿ���������һ��˼άȥ�ֱ��ж���������ͺ�
*       ���Ƕ�˼������۶��ܽ�
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.order == -1 || b.order == -1)
        return a.order > b.order;
    else
        return a.order < b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = -1;
    int begin, n, k;
    int address, data, next;
    scanf("%d %d %d", &begin, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, count = 0;
    while(p != -1) {
        node[p].order = ++count;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int isFirst = 1;
    for(int i = 0; i < count; i++) {
        if(node[i].data < 0) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    for(int i = 0; i < count; i++) {
        if(node[i].data >= 0 && node[i].data <= k) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    for(int i = 0; i < count; i++) {
        if(node[i].data > k) {
            if(isFirst == 1) {
                printf("%05d %d ", node[i].address, node[i].data);
                isFirst = 0;
            } else {
                printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].data);
            }
        }
    }
    printf("-1");
    return 0;
}
