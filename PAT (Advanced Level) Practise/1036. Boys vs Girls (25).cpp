/**
* ������Ҫ������ɼ���ߵ�Ů������Ϣ�ͳɼ���͵���������Ϣ���Լ����ǵĳɼ���ֵ
*       ���Ƚ������˰���Ů���У��ɼ��Ӹߵ����������һ�����ǳɼ���ߵ�Ů�������һ�����ǳɼ���͵�����
*       ѭ��ͳ���Ա��������ֳ����������ȫŮ��ȫ�С�������Ů������ͬ������������
*       ����ע�������ʽ���������⣬Ҫ��ϸ������
**/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct student {
    char name[11];
    char gender; //F or M
    char id[11];
    int score;
};

//����Ů���У��ɼ��Ӹߵ��͵�˳������
bool cmp(student stu1, student stu2) {
    if(stu1.gender != stu2.gender)
        return stu1.gender < stu2.gender;
    else if(stu1.score != stu2.score)
        return stu1.score > stu2.score;
}

int main() {
    int N, fName, fId, mName, mId;
    int gender = 0;
    scanf("%d", &N);
    student stu[N];
    for(int i = 0; i < N; i++) {
        scanf("%s %c %s %d", stu[i].name, &stu[i].gender, stu[i].id, &stu[i].score);
    }
    for(int i = 0; i < N; i++) {
        if(stu[i].gender == 'F')
            gender++;
    }
    if(gender == N)
        printf("%s %s\nAbsent\nNA", stu[0].name, stu[0].id); //ȫΪŮ��
    else if(gender == 0)
        printf("Absent\n%s %s\nNA", stu[N - 1].name, stu[N - 1].id); //ȫΪ����
    else {
        sort(stu, stu + N, cmp);
        printf("%s %s\n%s %s\n%d", stu[0].name, stu[0].id,
               stu[N - 1].name, stu[N - 1].id,
               stu[0].score - stu[N - 1].score);
    }
    return 0;
}
