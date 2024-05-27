#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

typedef int i;//typedef只能为现有的类创建别名
#define pb push_back//用#define为函数创建别名
int main()
{
    //解锁cin和cout,可以让他和scanf和printf一样快
    //平时用scanf和printf即可，但是string对象只能用cin和cout
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0); 

    string str;
    //读取一整行字符串
    getline(cin,str);

    //如果前面有读取别的数字之类的，需要单独一个getchar。但是解锁了就不可以用getchar，用cin.get()
    int n;
    cin>>n;

    getchar();//没解锁时用
    cin.get();//解锁时用
    getline(cin,str);

}
/*

为什么要进行cin和cout的解锁，原因是：
在一些题目中，读入的数据量很大，往往超过了1e5（105）的数据量,而cin和cout的读入输出的速度很慢
（是因为cin和cout为了兼容C语言的读入输出在性能上做了妥协），
远不如scanf和printf的速度，具体原因可以搜索相关的博客进行了解。
所以对cin和cout进行解锁使cin和cout的速度几乎接近scanf和printf，避免输入输出超时。

注意：cin cout解锁使用时，不能与 scanf,getchar, printf,cin.getline()混用，一定要注意，会出错。
*/
