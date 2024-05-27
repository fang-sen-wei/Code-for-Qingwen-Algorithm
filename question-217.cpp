//大整数
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
typedef vector<int> bignum;


bignum getnum(string str)
{
    bignum num;
    int len=str.size();
    for(int i=len-1;i>=0;i--)
    {
        num.pb(str[i]-'0');
    }
    return num;
}

//return 1表示大于，0表示等于，-1表示小于
int compare(bignum n1, bignum n2)
{
    int len1=n1.size(); 
    int len2=n2.size();
    if(len1>len2) return 1;
    else if(len1<len2) return -1;
    if(len1==len2)
    {
        for(int i=len1-1;i>=0;i--)
        {
            if(n1[i]>n2[i]) return 1;
            else if(n1[i]<n2[i]) return -1;
        }
    }
    return 0;
}
//加法！
bignum add(bignum n1, bignum n2) 
{
    int i = 0, j = 0;
    int s = 0; // 进位
    bignum ans;
    while (i < n1.size() || j < n2.size() || s != 0) 
    {
        int sum = s;//每一步先把进位s加上
        if (i < n1.size()) sum += n1[i++]; 
        if (j < n2.size()) sum += n2[j++];
        ans.pb(sum % 10); // 位上的值
        s = sum / 10; // 进位
    }
    return ans;
}
//减法
bignum sub(bignum n1, bignum n2)
{
    int i=0,j=0;
    int s=0;
    bignum ans;
    int t=compare(n1,n2);
    if(t==0)
    {
        ans.pb(0);
    }
    if(t<0) return sub(n2,n1);
    if(t>0)
    {
        int sum;
        while(i<n1.size() or j<n2.size())
        {
            sum=s;
            if(i<n1.size()) sum+=n1[i++];
            if(j<n2.size()) sum-=n2[j++];
            if(sum<0)
            {
                sum+=10;
                s=-1;
            }
            else s=0;
            ans.pb(sum);
        }
        //移除前导0
        while(ans.size()>0 and ans.back()==0)
        {
            ans.pop_back();
        }
    }
    return ans;
}
//乘法
bignum pluss(bignum n1, bignum n2)
{
    bignum ans(n1.size()+n2.size()+1,0);
    //只算每个位的乘法和
    for(int i=0;i<n1.size();i++)//!!!!!!!!!
    {
        for(int j=0;j<n2.size();j++)
        {
            ans[i+j]+=n1[i]*n2[j];
        }
    }
    //进位单独算一次
    for(int i=0;i<n1.size()+n2.size();i++)
    {
        if(ans[i]>=10)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }

    while(ans.size()>1 and ans.back()==0)
    {
        ans.pop_back();
    }
    return ans;
    
}
//除法
bignum div(bignum n, int b, int &r)
{
    bignum ans;
    for(int i=n.size()-1;i>=0;i--)
    {
        r = r*10+n[i];
        ans.pb(r/b);
        r=r%b;
    }
    reverse(ans.begin(),ans.end());
    while(ans.size()>1 and ans.back()==0)
    {
        ans.pop_back();
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0); 
    
    string str1;
    int b,r=0;
    cin>>str1>>b;
    bignum n1=getnum(str1);
    if(b==0) 
    {
       cout<<"undefined"; 
       return 0;
    }
    
    bignum ans=div(n1,b,r);
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
    }
    cout<<" "<<r;
}