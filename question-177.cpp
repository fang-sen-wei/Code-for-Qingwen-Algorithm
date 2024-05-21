//归并排序
#include<cstdio>
int n;//n个数
const int maxn=1000;
int a[maxn];
int temp[maxn];
void merge(int l1,int r1, int l2,int r2)
{
    int i=l1,j=l2;
    int ind=0;
    while(i<=r1 and j<=r2)//把两个序列合并
    {
        if(a[i]<a[j]) temp[ind++]=a[i++];
        else temp[ind++]=a[j++];
    }
    while(i<=r1)
    {
        temp[ind++]=a[i++];
    }
    while(j<=r2)
    {
        temp[ind++]=a[j++];
    }
    //把有序的序列复制到原数组中
    for(int i=0;i<ind;i++)
    {
        a[l1+i]=temp[i];
    }
}

void mergesort(int l, int r)
{
    int mid=l+(r-l)/2;
    if(l<r)
    {
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
    {
       
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
}