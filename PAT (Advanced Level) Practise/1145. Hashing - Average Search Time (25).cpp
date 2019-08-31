/**
* ������ɢ�б�ƽ������ʱ�䣬����ȡ�࣬�����ͻʹ������̽��
*       ���ҳɹ��Ĵ������ҵ������������ʧ�����ҵ�һ���յ�λ�û�û���ҵ����߳���������������û���ҵ�
*       Ҫע����ǲ��ҵ�ʱ�򲽳�Ҫȡ��Tsize��������������û�в��ҵ��ǴβŻ����������
*       ���߸ɴ�Ͷ�ȡ�ȣ����������ʱ��ȡ�Ⱦ��Ƕ����һ�Σ������˫��̽����Tsize/2
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int Tsize, n, m, key, q;
double ans = 0;
int h[maxn];

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for(int i = 2; i <= sqr; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    scanf("%d%d%d", &Tsize, &n, &m);
    while(!isPrime(Tsize))
        Tsize++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        int hkey = key % Tsize;
        int k;
        for(k = 0; k < Tsize; k++) { //���벻��ȡ��
            int pos = (hkey + k * k) % Tsize;
            if(h[pos] == 0) {
                h[pos] = key;
                break;
            }
        }
        if(k >= Tsize)
            printf("%d cannot be inserted.\n", key);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &q);
        int hkey = q % Tsize;
        int k;
        for(k = 0; k <= Tsize; k++) { //����ע��ȡ��
            int pos = (hkey + k * k) % Tsize;
            if(h[pos] != q && h[pos] != 0) {
                ans++;
            } else {
                ans++;
                break;
            }
        }
    }
    printf("%.1f\n", ans / m);
    return 0;
}
