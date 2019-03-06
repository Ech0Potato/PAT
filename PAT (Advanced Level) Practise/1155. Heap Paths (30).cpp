/**
* ���������Ƕ����򣬶ѵĸ�����
*       �Ӹ�������DFS������Ҷ�ӽ��ʹ�ӡ·��
*       ������������������������еݹ鼴��
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, heap[maxn];
bool isMax = true, isMin = true;
vector<int> path;

void DFS(int v) {
    //�ݹ�߽磺����Ҷ�ӽ��
    if(v * 2 > n && v * 2 + 1 > n) {
        for(int i = 0; i < path.size(); i++) {
            printf("%d", path[i]);
            if(i != path.size() - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    //����������Ҳ��������
    if(v * 2 <= n && v * 2 + 1 <= n) {
        path.push_back(heap[v * 2 + 1]);
        DFS(v * 2 + 1);
        path.pop_back();
        path.push_back(heap[v * 2]);
        DFS(v * 2);
        path.pop_back();
    }
    //ֻ��������û��������
    if(v * 2 <= n && v * 2 + 1 > n) {
        path.push_back(heap[v * 2]);
        DFS(v * 2);
        path.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &heap[i]);
    path.push_back(heap[1]);
    DFS(1);
    for(int i = 2; i <= n; i++) {
        if(heap[i / 2] < heap[i])
            isMax = false;
        if(heap[i / 2] > heap[i])
            isMin = false;
    }
    if(isMax)
        printf("Max Heap");
    if(isMin)
        printf("Min Heap");
    if(!isMax && !isMin)
        printf("Not Heap");
    return 0;
}
