#include <cstdio>
const int Galleon = 17 * 29; //1个Galleon兑换17*29个Knut
const int Stickle = 29; //1个Stickle兑换29个Knut

int main() {
    int a1, b1, c1;
    int a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int price = a1 * Galleon + b1 * Stickle + c1; //价格，兑换成Knut单位
    int money = a2 * Galleon + b2 * Stickle + c2; //付款，兑换成Knut单位
    int change = money - price; //找零的钱
    //如果是负数
    if (change < 0) {
        printf("-"); //输出符号
        change = -change; //取绝对值
    }
    //转换成原先的格式
    printf("%d.%d.%d\n", change / Galleon, change % Galleon / Stickle, change % Stickle);
    return 0;
}
