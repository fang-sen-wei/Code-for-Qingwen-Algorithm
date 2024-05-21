//2-SUM-双指针
#include<cstdio>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    //双指针指向0和n-1
    int i=0,j=n-1;
    int ans=0;
    while(i<j)
    {
        if(a[i]+a[j]==k)
        {
            ans++;
            i++;
            j--;
        }
        else if(a[i]+a[j] >k) j--;
        else i++;
    }
    printf("%d",ans);
}