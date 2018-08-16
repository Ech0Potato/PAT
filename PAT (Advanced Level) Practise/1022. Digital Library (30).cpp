/**
* ����������STL���ۺ�ʹ��
*       ��Ϊһ��ID��Ӧ�����Ϣ����ĿҪ����ݳ�ID��������Ϣ���в�ѯ������Ҫʹ��map<string,set<int> >
*       ��Ϊ��ͬ����Ϣ���Զ�Ӧ���ID����������д�˶౾�飬����������˶౾�飬�Ƕ�Զ�Ĺ�ϵ�����Բ���ֱ����int����Ҫ��set<int>
*       ���⣬�Բ�̤�����������������ȫ�ǿӣ����������ע��
*
**/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    int type;
    char c;
    string query;
    int id;
    string title, author, key, pub, year;
    map<string, set<int> > mtitle, mauthor, mkey, mpub, myear;
    set<int>::iterator it;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        //��һ��������id����Ҫ���տո񣬷���getline��ѻ��ж���
        scanf("%d\n", &id);
        getline(cin, title);
        mtitle[title].insert(id);
        getline(cin, author);
        mauthor[author].insert(id);
        //�Ӷ�����Ϊ���ܻ��ȡ����ؼ��ʣ�����Ҫ�ж���������һ���ַ��ǿո��ǻ���
        while(cin >> key) {
            mkey[key].insert(id);
            c = getchar();
            if(c == '\n')
                break;
        }
        getline(cin, pub);
        mpub[pub].insert(id);
        getline(cin, year);
        myear[year].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, query);
        cout << type << ": " << query << endl;
        //������ID������7λ����ʹ�����ʱ��ûҪ�������ʱ��ҲҪ��0����
        switch(type) {
        case 1:
            if(mtitle.find(query) != mtitle.end()) {
                for(it = mtitle[query].begin(); it != mtitle[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 2:
            if(mauthor.find(query) != mauthor.end()) {
                for(it = mauthor[query].begin(); it != mauthor[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 3:
            if(mkey.find(query) != mkey.end()) {
                for(it = mkey[query].begin(); it != mkey[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 4:
            if(mpub.find(query) != mpub.end()) {
                for(it = mpub[query].begin(); it != mpub[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 5:
            if(myear.find(query) != myear.end()) {
                for(it = myear[query].begin(); it != myear[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
