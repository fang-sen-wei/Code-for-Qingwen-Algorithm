//双序列中位数
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<double> res;
    int n,m;
    scanf("%d %d",&n,&m);
    double a[n],b[m];
    
    for(int i=0;i<n;i++) scanf("%lf",&a[i]);
    for(int j=0;j<m;j++) scanf("%lf",&b[j]);
    
    for(int i=0;i<n;i++) res.push_back(a[i]);
    for(int i=0;i<m;i++) res.push_back(b[i]);
   
    sort(res.begin(),res.end());
    if(res.size()%2)
    {
        printf("%.1f",res[res.size()/2]);
    }
    else
    {
        printf("%.1f",(res[res.size()/2]+res[res.size()/2 -1])/2.0);
    } 
}