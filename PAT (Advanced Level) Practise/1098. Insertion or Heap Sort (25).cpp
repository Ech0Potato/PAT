/**
* ������Ҫ��ģ���������Ͷ�������̣�Ҫ�ܿ���д�����������㷨
*       ��ΪҪ�ö��������Բ���������vector���������ڲ������������sort����
*       ������A1089���ƣ��������뻹����Щ�����㷨�������һ�𿼣�׼��һ��ѺѺ��
*       ͬʱ�Ժ������ͳһ�������������飬��дһ���жϣ�Ȼ��������ʱ����ֱ��ȥģ���������
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n;
int a[maxn], b[maxn], t[maxn], heap[maxn];

bool isEqual(int a[], int b[]) {
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if(heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        t[i] = a[i];
        heap[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    //��������
    bool f1 = false;
    for(int i = 2; i <= n; i++) {
        sort(t + 1, t + i + 1); //����ҿ�
        //ÿ���һ���������һ�αȽ�
        if(f1) { //��Ϊ���������һ�������������԰����д����������
            for(int k = 1; k <= n; k++) {
                printf("%d", t[k]);
                if(k != n)
                    printf(" ");
            }
            break;
        }
        if(isEqual(t, b)) {
            printf("Insertion Sort\n");
            f1 = true;
        }
    }
    //������
    bool f2 = false;
    for(int i = n / 2; i >= 1; i--) { //����
        downAdjust(i, n);
    }
    for(int i = n; i > 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
        if(f2) {
            for(int k = 1; k <= n; k++) {
                printf("%d", heap[k]);
                if(k != n)
                    printf(" ");
            }
            break;
        }
        if(isEqual(heap, b)) {
            printf("Heap Sort\n");
            f2 = true;
        }
    }
    return 0;
}









//**
//* ��������ȷ��������Ͷ�������ص�
//*       ������ǰ�������������Һ���δ�����������ȫ��ͬ����������󼸸�����������δ����ĵ�һ������Ϊ���ֵ
//*       ������ҵ���С�����һ�����ٵ��������֣�Ȼ�����������ֿ�ʼ��ԭ���бȶԣ������ȫ��ͬ����Ϊ���ţ�����Ϊ������
//*       �ж�֮��������������еĻ������ٽ���һ�����򼴿�
//*       ���ſ���sort���棬��ԭ���ж���һ������
//*       ��������Ҫ�ǵ÷����������Ѷ���δ����Ķѵ����һ��Ԫ�أ�Ȼ�����µ�������
//**/
//
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 110;
//
//int n, t = 2;
//int a[maxn], b[maxn];
//
//void downAdjust(int low, int high) {
//    int i = 1, j = i * 2;
//    while(j <= high) {
//        if(j + 1 <= high && b[j] < b[j + 1])
//            j = j + 1;
//        if(b[i] < b[j]) {
//            swap(b[i], b[j]);
//            i = j;
//            j = i * 2;
//        } else {
//            break;
//        }
//    }
//}
//
//int main() {
//    scanf("%d", &n);
//    for(int i = 1; i <= n; i++)
//        scanf("%d", &a[i]);
//    for(int i = 1; i <= n; i++)
//        scanf("%d", &b[i]);
//    while(t <= n && b[t - 1] <= b[t])
//        t++;
//    int index = t;
//    while(t <= n && a[t] == b[t])
//        t++;
//    if(t == n + 1) {
//        printf("Insertion Sort\n");
//        sort(b + 1, b + index + 1);
//        printf("%d", b[1]);
//        for(int i = 2; i <= n; i++)
//            printf(" %d", b[i]);
//    } else {
//        printf("Heap Sort\n");
//        t = n;
//        while(t >= 2 && b[t] >= b[t - 1])
//            t--;
//        swap(b[1], b[t]);
//        downAdjust(1, t - 1);
//        printf("%d", b[1]);
//        for(int i = 2; i <= n; i++)
//            printf(" %d", b[i]);
//    }
//    return 0;
//}
