/**
* ������һ�������ᳬʱ
*       ���񱦵�Ҫ����ɢ�з������ֲ��Ҽ�two pointers�����ֱ�ʵ��һ�Ρ�����
*       ɢ�з�ע�������С������Ҫ����10^5����Ϊ���ݲ��ᳬ��10^3
*       ��Ҫע��i == m-i�����
*       ��֪��Ϊɶhash�������д��main�������棬��Ȼ����һ�������ٵ�2�֡�����
**/

#include <cstdio>
const int maxM = 1001;

int hash[maxM];

int main() {
    int N, M, temp, flag;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &temp );
        hash[temp]++;
    }
    for(int i = 1; i < M; i++) {
        if(hash[i] && hash[M - i] ) {
            if(i == M - i && hash[i] > 1) {
                printf("%d %d\n", i, M - i);
                break;
            } else if(i != M - i) {
                printf("%d %d\n", i, M - i);
                break;
            }
        }
        flag = i;
    }
    if(flag == M - 1)
        printf("No Solution\n");
    return 0;
}

/*
    һ�������ᳬʱ

    int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        int V[N + 1], V1, V2, flag;
        for(int i = 0; i < N; i++) {
            scanf("%d", &V[i]);
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(V[i] + V[j] == M) {
                    V1 = V[i];
                    V2 = V[j];
                    break;
                    break;
                }
            }
        }
        if(flag == N - 1)
            printf("No Solution");
        else
            printf("%d %d", V1, V2);
        return 0;
    }
*/
