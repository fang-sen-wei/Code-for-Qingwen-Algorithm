#include<iostream>
//计算n!中有几个p质因子
//只能算质数因子的个数，因为他们没有更小的因数了
using namespace std;
int cal(int n, int p)
{
    int ans=0;
    while(n)
    {
        ans+=n/p;
        n/=p;
    }
    return ans;
}
//p表示质因子
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    cout<<cal(n,m);
    //cal(n,5)表示求末尾0的个数
}
