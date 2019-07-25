/**
* ��������Ȼ��ѹ���⵫ûʲô�ѵģ�40����һ��AC
*       �����һ��Ǳ�ȥ��ǿ��һЩ�������� 
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

struct Record {
	char id[8];
	int h,m,s;
	int time;
	int status; // 1:in 2:out
} rec[maxn];

bool cmp(Record a,Record b) {
	if(strcmp(a.id,b.id)!=0)
		return strcmp(a.id,b.id)<0;
	else
		return a.time<b.time;
}

int parkNum[86410]= {0}; //ÿ��ʱ�̵�ͣ������ 24*3600=86400
map<string,int> parkTime; //ÿ������ͣ��ʱ��

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	char st[4];
	for(int i=0; i<n; i++) {
		scanf("%s %d:%d:%d %s",rec[i].id,&rec[i].h,&rec[i].m,&rec[i].s,st);
		rec[i].time = rec[i].h * 3600 + rec[i].m * 60 + rec[i].s;
		if(strcmp(st,"in")==0)
			rec[i].status = 1;
		else
			rec[i].status = 2;
	}
	sort(rec,rec+n,cmp);
	for(int i=1; i<n; i++) {
		if(strcmp(rec[i].id,rec[i-1].id)==0 && rec[i].status ==2 && rec[i-1].status==1) {
			string str = rec[i].id;
			parkTime[str]+=rec[i].time-rec[i-1].time;
			for(int j=rec[i-1].time; j<rec[i].time; j++)
				parkNum[j]++;
		}
	}
	int h,m,s,time;
	while(k--) {
		scanf("%d:%d:%d",&h,&m,&s);
		time = h*3600+m*60+s;
		printf("%d\n",parkNum[time]);
	}
	int longest=0;
	for(map<string,int>::iterator it = parkTime.begin(); it!=parkTime.end(); it++) {
		if(it->second>longest)
			longest = it->second;
	}
	for(map<string,int>::iterator it = parkTime.begin(); it!=parkTime.end(); it++) {
		if(it->second==longest)
			printf("%s ",it->first.c_str());
	}
	printf("%02d:%02d:%02d",longest/3600,longest%3600/60,longest%60);
	return 0;
}





///**
//* ������Ӧ�������ѵ��������ˣ��ο���֮��д�˺þã�������һ��3�ֵĲ��Ե�û��ͨ�������г�ʱ
//*       ����ԭ���Ǽ���ͣ��������ʱ����ʽ���Ǻܺã�ÿ�ζ������¿�ʼ�ظ�����
//*       �������д����û�б�Ҫÿ�����¼��㣬��Ϊʱ����Ǵ�С���������
//*       �ڲ���һ��֮����һ�εĲ��ҿ�������һ�εĽ��֮�ϼ������У����Ա��ⳬʱ
//*       ����ܰ�����ѧ���ĺܶ࣬�����ܽᵽ�ĵ���
//**/
//
//#include <cstdio>
//#include <cstring>
//#include <map>
//#include <string>
//#include <algorithm>
//using namespace std;
//const int maxn = 10010;
//const int maxk = 8 * 10010;
//
//struct record {
//    char id[8];
//    int time;
//    int flag = 0; //in=1,out=-1
//} rec[maxn], nrec[maxn];
//
//char temp[4];
//map<string, int> ptime;
//
//bool cmp1(record a, record b) {
//    if(strcmp(a.id, b.id))
//        return strcmp(a.id, b.id) < 0;
//    else
//        return a.time < b.time;
//}
//
//bool cmp2(record a, record b) {
//    return a.time < b.time;
//}
//
//int main() {
//    int n, k;
//    int h, m, s, time, maxtime = 0;
//    int num = 0;
//    scanf("%d%d", &n, &k);
//    for(int i = 0; i < n; i++) {
//        scanf("%s %d:%d:%d %s", rec[i].id, &h, &m, &s, temp);
//        rec[i].time = h * 3600 + m * 60 + s;
//        if(strcmp(temp, "in") == 0)
//            rec[i].flag = 1;
//        else
//            rec[i].flag = -1;
//    }
//    sort(rec, rec + n, cmp1);
//    for(int i = 0; i < n; i++) {
//        if(strcmp(rec[i].id, rec[i + 1].id) == 0 && rec[i].flag == 1 && rec[i + 1].flag == -1) {
//            nrec[num++] = rec[i];
//            nrec[num++] = rec[i + 1];
//            ptime[rec[i].id] += rec[i + 1].time - rec[i].time;
//            if(maxtime < ptime[rec[i].id])
//                maxtime = ptime[rec[i].id];
//        }
//    }
//    sort(nrec, nrec + num, cmp2);
//    int count = 0, now = 0;
//    for(int i = 0; i < k; i++) {
//        scanf("%d:%d:%d", &h, &m, &s);
//        time = h * 3600 + m * 60 + s;
////        int count = 0;
////        for(int j = 0; j < num; j++) {
////            if(nrec[j].time <= time) {
////                if(nrec[j].flag == 1)
////                    count++;
////                else
////                    count--;
////            }
////        }
//        while(now < num && nrec[now].time <= time) {
//            if(nrec[now].flag == 1)
//                count++;
//            else
//                count--;
//            now++;
//        }
//        printf("%d\n", count);
//    }
//    for(map<string, int>::iterator it = ptime.begin(); it != ptime.end(); it++) {
//        if(it->second == maxtime)
//            printf("%s ", it->first.c_str());
//    }
//    printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
//    return 0;
//}
