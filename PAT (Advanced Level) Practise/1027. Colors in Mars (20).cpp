/**
* ������Ҫ������0-168��ʮ������ת��Ϊ13��������ͬʱǰ���#��������λҪ��0
*       ֱ���׽���ת����ģ�壬����ȡ�༴�ɣ����ע����������ʽ�ͺã������ʽ�Ĳ�ͬ����Ҫ����ȫ
*       �������񱦵仹�и��õķ�������Ϊ��ΧΪ[0,168]����������һ�����Ա�ʾΪx = a * 13^1 + b * 13^0
*       ���������ʽͬʱ����13���ɵ�x / 13 = a������ͬʱ��13ȡģ���ɵ�x % 13 = b
*       �����char�������ʾ�������ַ��Ķ�Ӧ��ϵ��һ��Ҫѧ�����������������Ӧ��ϵ�ļ��ɣ�������
*       ���a��b���ɣ�����
**/

#include <cstdio>

//����0-13��'0'-'9'��'A'��'B'��'C'�Ĺ�ϵ
char radix[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main() {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#");
    printf("%c%c", radix[r / 13], radix[r % 13]);
    printf("%c%c", radix[g / 13], radix[g % 13]);
    printf("%c%c", radix[b / 13], radix[b % 13]);
    return 0;
}

/*
    һ�����������鷳������

    const int maxn = 2;

    //���ֻ��һλʱ��0��ת��
    void printOne(int d) {
        if(d < 10)
            printf("0%d", d);
        else if(d == 10)
            printf("0A");
        else if(d == 11)
            printf("0B");
        else if(d == 12)
            printf("0C");
    }

    //�����λʱ��ת��
    void printTwo(int d) {
        if(d < 10)
            printf("%d", d);
        else if(d == 10)
            printf("A");
        else if(d == 11)
            printf("B");
        else if(d == 12)
            printf("C");
    }

    //10������ת13�����������
    void toThree (int d) {
        int D[maxn], num = 0;
        do {
            D[num++] = d  %  13; //����ȡ��
            d = d / 13;
        } while(d != 0);
        if(num == 1) {
            printOne(D[0]);
        } else {
            printTwo(D[1]);
            printTwo(D[0]);
        }
    }

    int main() {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        printf("#");
        toThree(r);
        toThree(g);
        toThree(b);
        return 0;
    }
*/
