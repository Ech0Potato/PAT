/**
* ������˼·��ȷ��ʵ�ֲ��ԣ�ԭ�㷨��������TLEֻ��19��
*      �ο�����������д
*      ѧ���������λ�õ�˼�룬һ��Ҫ�ǵ��ã�������Ԥ�����������ѭ���������Լ�swap()��ʹ��
*      ѭ���Ҳ��ڱ�λ��ʱ���ʵ���֦����Ȼ�����������Ե�TLE��������ԭ��Ҳ����������� 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int pos[maxn];

int main() {
	int n,temp,left=0,cnt=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&temp);
		pos[temp]=i;
		if(pos[temp]!=temp && temp!=0)
			left++;
	}
	int k=1; //��Ȼ�ᳬʱ
	while(left>0) {
		if(pos[0]==0) {
			while(k<n) {
				if(pos[i]!=i) {
					swap(pos[0],pos[i]);
					cnt++;
					break;
				}
				k++;
			}
		}
		swap(pos[0],pos[pos[0]]);
		cnt++;
		left--;
	}
	printf("%d\n",cnt);
	return 0;
}





//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 100010;
//
//int d[maxn];
//
//int main() {
//	int n,pos0,post,left=0,cnt=0;
//	scanf("%d",&n);
//	for(int i=0; i<n; i++) {
//		scanf("%d",&d[i]);
//		if(d[i]==0)
//			pos0=i; //��¼0��λ��
//		if(d[i]!=i && d[i]!=0)
//			left++;
//	}
//	while(left>0) {
//		if(pos0==0) {
//			for(int i=0; i<n; i++) {
//				if(d[i]!=i) {
//					d[0]=d[i];
//					d[i]=0;
//					pos0=i;
//					cnt++;
//					break;
//				}
//			}
//		}
//		if(d[pos0]!=pos0) {
//			for(int i=0; i<n; i++) {
//				if(d[i]==pos0) {
//					post=i;
//				}
//			}
//			d[pos0]=pos0;
//			d[post]=0;
//			pos0=post;
//			cnt++;
//			left--;
//		}
//	}
//	printf("%d\n",cnt);
//	return 0;
//}
