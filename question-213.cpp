//最小最大质因子
#include<cstdio>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int maxn=1e6;
vector<int> prime;
bool p[maxn+1];
//得到1-n素数表
void get_prime(int n)
{
    fill(p,p+n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(p[i]) 
        {
            prime.push_back(i);
            for(int j=2;j*i<=n;j++)
            {
                p[i*j]=false;
            }
        }
        
    }
}

int main()
{
    get_prime(maxn);
    
    int n;
    scanf("%d",&n);
    int list[n];
    set<int> res;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
        for(int j=0;j<prime.size();j++)//从素数表从低往高遍历
        {
            if(list[i]<prime[j]) break;
            if(list[i]%prime[j] == 0)//除得尽，就是他的一个质因数
            {
                res.insert(prime[j]);//set自动排序以及去重
            }
        }
    }
    printf("%d %d",*res.begin(), *res.rbegin());
      
}
