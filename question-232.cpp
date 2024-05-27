//组合数
#include<iostream>
using namespace std;

//只要m的复杂度,但是只能n=<=61,m<=31
//方法1，用数学的思路，=（n-m+i)/i ，i为 1到m 的连乘
long long cal_1(int n, int m)
{
    long long ans=1;
    for(int i=1;i<=m;i++)
    {
        ans *= (n-m+i)/i; 
    }
    return ans;
}

//方法2，自顶向下的递归，res[n][m]存下所有用过的
//递归，但也只能算出67 ，33的范围，复杂度为不超过n*n
//如果是组合数取余数，那么return处加上%即可
int p;
long long res[1010][1010];
long long cal_2(int n, int m)
{
    if(m==0 or m==n) return 1;
    if(res[n][m]!= 0) return res[n][m];
    else return res[n][m] = (cal_2(n-1,m-1)+cal_2(n-1,m)); // %p
   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    // cin>>p;
    cout<<cal_2(n,m);
}