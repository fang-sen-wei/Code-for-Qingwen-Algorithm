//棋盘覆盖问题
//分治、递归
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = (256 * 256 - 1) / 3;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) {x = _x; y = _y;}//构造函数，用于初始化
} cards[MAXN];

int num = 0;//用于L型骨牌的计数

bool cmp(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
    //x从小到大排序，x相同,y就从小到大
}
//x,y为棋盘的原点坐标，n为棋盘的边长，cx，cy为特殊点的坐标
void cover(int x, int y, int n, int cx, int cy) {
    if (n == 1) {//递归边界，当方格为1*1时停止递归
        return;
    } else {
        int h = n / 2;  //将方格分成四份
        if (cx < x + h && cy >= y + h) 
        {
            //如果特殊点在左上的小格子里
            cards[num++] = Point(x + h, y + h - 1); 
            //在十字分割处放置一个L型，使得另外三个小方格也有一个特殊点
            //关键点！！！
            cover(x, y + h, h, cx, cy); //继续处理左上角的小方格
        } 
        else 
        {
            cover(x, y + h, h, x + h - 1, y + h);
            //若初始特殊点不在左上方格，会默认以预定的特殊点位置进行递归，后续会放置L型使得该位置成为特殊点
            //后续都如此操作
        }
        if (cx >= x + h && cy >= y + h) {
            cards[num++] = Point(x + h - 1, y + h - 1);
            cover(x + h, y + h, h, cx, cy);
        } else {
            cover(x + h, y + h, h, x + h, y + h);
        }
        if (cx < x + h && cy < y + h) {
            cards[num++] = Point(x + h, y + h);
            cover(x, y, h, cx, cy);
        } else {
            cover(x, y, h, x + h - 1, y + h - 1);
        }
        if (cx >= x + h && cy < y + h) {
            cards[num++] = Point(x + h - 1, y + h);
            cover(x + h, y, h, cx, cy);
        } else {
            cover(x + h, y, h, x + h, y + h - 1);
        }
    }
}

int main() {
    int k, cx, cy;
    scanf("%d%d%d", &k, &cx, &cy);
    cover(1, 1, (int)pow(2.0, k), cx, cy);
    sort(cards, cards + num, cmp);
    for(int i = 0; i < num; i++) {
        printf("%d %d\n", cards[i].x, cards[i].y);
    }
    return 0;
}