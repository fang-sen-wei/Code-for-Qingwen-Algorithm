//快速排序
#include<cstdio>
int n;
int quick(int l, int r, int a[])
{
    int temp=a[l];
    while(l<r)
    {
        while(l<r and a[r]>temp)
        {
            r--;//从右边往左边找 小于等于 temp的数的位置
        }
        a[l]=a[r];//把小的换到原来的位置
        while(l<r and a[l]<=temp)
        {
            l++;//从左边找比temp大的
        }
        a[r]=a[l];
    }
    a[l]=temp;
    return l;
}

void quicksort(int l, int r,int a[])
{
    if(l<r)
    {
        int pos=quick(l,r,a);//先扫描一轮，把基准位置定下来
        quicksort(l,pos-1,a);//左边再排序
        quicksort(pos+1,r,a);//右边再排序
        //每次都确定了一个数的位置pos,所以pos不需要排序
    }
}

int main()
{
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(0,n-1,a);
    for(int i=0;i<n;i++)
    {
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
}