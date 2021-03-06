/**
* 分析：链表处理，简单题，套模板即可
*       此题注意输出地址时要写%05d，不然地址00001会输出成1
*       由于输出用了%05d，末尾空结点的地址-1会被输出成0，所以要提前判断
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int flag;
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.flag == 0 || b.flag == 0) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].flag = 0;
    int n, begin;
    int address, data, next, count = 0;
    scanf("%d %d", &n, &begin);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin;
    while(p != -1) {
        node[p].flag = 1;
        p = node[p].next;
        count++;
    }
    //不要忘了特判
    if(count == 0) {
        printf("0 -1\n"); //新链表没有结点时输出0 -1
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address);
        for(int i = 0; i < count; i++) {
            if(i != count - 1)
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else
                printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}
