/**
* ���������ǵ�ָ������Ϊ�������Բ��������飬������map
*       ���������֮����Ե�2���ǲ��ԣ�ȥ�������ʲ����ˣ��˷�ʱ��
*       ���Ƿ��ˣ���֪�����ֲ���������ʲô����
*       ֱ�ӱ���������
*       �ҳ����ˣ�����0 0�����ݣ�����a��0 0���������Ҳ��0 0����ָ��������û�й�ϵ
*       ��������ˡ�����
**/

//#include <cstdio>
//using namespace std;
//
//int main() {
//    int a, b;
//    bool isFirst = true; //�Ƿ����й����
//    while (scanf("%d%d", &a, &b) != EOF) {
//        if(b != 0) {
//            if(!isFirst)
//                printf(" "); //����ÿ������ǰ��Ŀո�
//            printf("%d %d", a * b, b - 1);
//            isFirst = false;
//        }
//    }
//    if(isFirst == true)
//        printf("0 0");
//    return 0;
//}

#include <cstdio>
#include <map>
using namespace std;

map<int, int> e;
map<int, int> ans;

int main() {
    int a, b, cnt = 0; //cnt��������ո�
    scanf("%d%d", &a, &b);
    e[b] = a;
    //if(a == 0 && b == 0) {
    if(b == 0) {
        printf("0 0");
        return 0;
    }
    while(scanf("%d%d", &a, &b) != EOF)
        e[b] = a;
    for(int i = 1000; i >0; i--) {
        if(e[i] != 0 && i != 0) {
            ans[i - 1] = i * e[i];
            cnt++;
        }
    }
    for(int i = 999; i >= 0; i--) {
        if(ans[i] != 0) {
            printf("%d %d", ans[i], i);
            cnt--;
            if(cnt != 0)
                printf(" ");
        }
    }
    return 0;
}
