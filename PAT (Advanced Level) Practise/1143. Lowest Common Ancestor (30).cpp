

























//**
//* ��������BST����LCA��һ��ʼ�������ʱ��ѡ�����жϴ�С������������������ֻ��19��
//*       debug����һ��ʼ��д����������Ϊ�ϴ��������Ϊ����㣬�Ǳ������Ǹ�ֻ�����ӵ��������ˣ����������ֻ���Һ��ӵ������ͻ����
//*       ����iӦ��>=a����<=b��������Ϊ20�֣�debug���ֽ�����˵�����д�������������29��
//*       ����dubug������������ͬʱ����д�����һ��ʵ������ 2 8 7 9 4 -3 0 9
//*       ע�Ͳ���Ϊ���ӽ�����������Ĵ���
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int m, n, x, a, b;
//bool isswap;
//vector<int> tree;
//map<int, bool> mp;
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        tree.push_back(x);
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            isswap = false;
//            if(a > b) {
//                swap(a, b);
//                isswap = true;
//            }
//            for(auto i : tree) {
////				if((i>=a&&i<=b)||(i<=a&&i>=b)) {
////					if(i==a||i==b) {
////						if(i==a)
////							printf("%d is an ancestor of %d.\n",a,b);
////						else
////							printf("%d is an ancestor of %d.\n",b,a);
////
////					} else
////						printf("LCA of %d and %d is %d.\n",a,b,i);
////				}
//                if(i >= a && i <= b) {
//                    if(i != a && i != b) {
//                        if(isswap)
//                            printf("LCA of %d and %d is ", b, a);
//                        else
//                            printf("LCA of %d and %d is ", a, b);
//                        printf("%d.\n", i);
//                    } else {
//                        if(i == a)
//                            printf("%d is an ancestor of %d.\n", a, b);
//                        else if(i == b)
//                            printf("%d is an ancestor of %d.\n", b, a);
//                    }
//                    break;
//                }
//            }
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            } else if(mp.find(a) == mp.end() && mp.find(b) != mp.end()) {
//                printf("ERROR: %d is not found.\n", a);
//            } else if(mp.find(a) != mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d is not found.\n", b);
//            }
//        }
//    }
//    return 0;
//}
