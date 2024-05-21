//快速幂ii
#include<cstdio>
typedef long long ll;
ll mi(ll a, ll b, ll m)
{
    if(b==0) return 1;
    else if(b%2)
    {
        return a*mi(a,b-1,m) % m;//数字太大了，只能在此处直接%m,再进行下一步
    }
    else
    {
        ll temp=mi(a,b/2,m);//临时存储下来，如果写mi()*mi()会递归两次
        return temp*temp % m;//数字太大了，只能在此处直接%m,再进行下一步
    }
}
int main()
{
    ll a,b,m;
    scanf("%lld %lld %lld",&a,&b,&m);
    printf("%lld",mi(a,b,m));
    
}