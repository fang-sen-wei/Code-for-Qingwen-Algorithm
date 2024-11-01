#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    int p[n]={0};
    queue<int> q;
    int sum=0;
    int j=0;
    
    while(q.size() < n-1)
    {
        if(p[j]==0) sum++;//报数
        if(sum==k)//报数为k
        {
            q.push(j+1);//0 - n-1 需要+1下标
            sum=0;
            p[j]=1;
        }
        j=(j+1)%n;
    }
    //最后一个数下标入队
    for(int i=0;i<n;i++)
    {
        if(p[i]==0) q.push(i+1);
    }
    while(!q.empty())
    {
        cout<<q.front();
        if(q.size()>1) cout<<" ";
        q.pop();
    }

}