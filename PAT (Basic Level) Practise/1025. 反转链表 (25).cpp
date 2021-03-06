#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

//定义静态链表（步骤1）
struct Node {
    int address, data, next;
    int order; //结点在链表上的序号，无效结点记为maxn
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order; //按order从小到大排序
}

int main() {
    //初始化（步骤2）
    for (int i = 0; i < maxn; i++) {
        node[i].order = maxn; //初始化全部为无效结点
    }
    int begin, n, K, address; //起始地址、结点个数、步长、地址
    scanf("%d%d%d", &begin, &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    int p = begin, count = 0; //count计数有效结点的数目
    //遍历链表找出单链表的所有有效结点（步骤3）
    while (p != -1) {
        node[p].order = count++; //结点在单链表中的序号
        p = node[p].next; //下一个结点
    }

    //按单链表从头到尾顺序排列（步骤4）
    sort(node, node + maxn, cmp);

    n = count; //有效结点为前count个结点，为了下面书写方便，因此把count赋给n
    //单链表已经形成，按题目要求进行输出（步骤5）
    for (int i = 0; i < n / K; i++) { //枚举完整的n/K块
        for (int j = (i + 1) * K - 1; j > i * K; j--) {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address); //第i块倒着输出
        }
        printf("%05d %d ", node[i * K].address, node[i * K].data); //每一块的最后一个结点的next地址的处理
        if (i < n / K - 1) { //如果不是最后一块，就指向下一块的最后一个结点
            printf("%05d\n", node[(i + 2)*K - 1].address);
        } else { //是最后一块时
            if (n % K == 0) { //恰好是最后一个结点，输出-1
                printf("-1\n");
            } else { //剩下不完整的块按原先的顺序输出
                printf("%05d\n", node[(i + 1)*K].address);
                for (int i = n / K * K; i < n; i++) {
                    printf("%05d %d ", node[i].address, node[i].data);
                    if (i < n - 1) {
                        printf("%05d\n", node[i + 1].address);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
