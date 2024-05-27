//质因子分解
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=1e6;
vector<int> prime;
bool p[maxn];
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
    int n;
    scanf("%d",&n);
    get_prime(n);
    for(int i=0;i<prime.size();i++)
    {
        int count=0;
        if(n%prime[i] == 0)//从素数表从低往高遍历
        {
            while(n%prime[i]==0)
            {
                count++;
                n/=prime[i];
            }
            printf("%d %d\n",prime[i],count);
        }
        if(n==1) break;
    }
}
