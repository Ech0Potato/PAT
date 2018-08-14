/**
* ������37���ӣ�6�����Ե�ͨ����4��ȴֻ��8�֣�һ����ʽ����һ�����г�ʱ
*       �о��Լ����ӱ������߼������⡣����
*       ������⣬�����߼���࣬����˼·�ǣ���ȡÿ�ſε�����ѡ��ѧ����Ȼ�󽫿γ̱�ż���ѡ�����ſε�ѧ����ȥ
*       ֻ���������������ʹ��cin��cout��map��string���ᵼ�³�ʱ
*       Ҫ��hash��ѧ������ת��Ϊint�ʹ洢��vector��
*       ���������Զ���ο���ֵ���󡣡���
*       ����Ҫͨ�������ѧ��vector�Ĳ����������Ƕ�ά����
**/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010; //������
const int M = 26 * 26 * 26 * 10 + 1; //������ɢ�гɵ������Ͻ�
vector<int> selectCourse[M]; //ÿ��ѧ��ѡ��Ŀγ̱��

int getID(char name[]) {
    int id = 0;
    for(int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++) {
        int course, x;
        scanf("%d%d", &course, &x);
        for(int j = 0; j < x; j++) {
            scanf("%s", name);
            int id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end()); //Ĭ�ϴ�С��������
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0; j < selectCourse[id].size(); j++)
            printf(" %d", selectCourse[id][j]);
        printf("\n"); //���һ�п���������з�
    }
    return 0;
}

/*

struct Class {
    int id;
    int count;
    vector<string> stu;
};

struct Student {
    string name;
    int count;
    vector<int> cls;
};

int main() {
    int n, k, temp;
    int id, count;
    string name;
    scanf("%d %d", &n, &k);
    temp = k;
    Class cls[k];
    Student stu[n];
    while(temp--) {
        scanf("%d %d", &id, &count);
        cls[id - 1].id = id;
        cls[id - 1].count = count;
        while(count--) {
            cin >> name;
            cls[id - 1].stu.push_back(name);
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> name;
        stu[i].name = name;
        stu[i].count = 0;
        for(int j = 0; j < k; j++) {
            for(vector<string>::iterator it = cls[j].stu.begin(); it != cls[j].stu.end(); it++) {
                if(*it == name) {
                    stu[i].cls.push_back(cls[j].id);
                    stu[i].count++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].count << " ";
        for(vector<int>::iterator it = stu[i].cls.begin(); it != stu[i].cls.end(); it++) {
            if(it != stu[i].cls.end() - 1)
                cout << *it << " ";
            else
                cout << *it;
        }
        if(i != n - 1)
            cout << endl;
    }
    return 0;
}

*/
