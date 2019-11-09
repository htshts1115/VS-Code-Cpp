#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void InsertSort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;++i)//从1开始，认为a[0]是有序的
        if(a[i]<a[i-1])
        {
            int temp=a[i];
            for(j=i-1;j>=0&&a[j]>temp;--j)
                a[j+1]=a[j];//在找到合适的插入点前，数据都往后移一位
            //a[j]为小于等于temp(不满足a[j]>temp)的第一个位置
            a[j+1]=temp;//找到了合适的插入点
        }
}

void shellSort(int a[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;++i)//从gap位置开始比较
            for(j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
                swap(a[j],a[j+gap]);
}

