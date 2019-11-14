#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// insert sort
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

// shell sort
void shellSort(int a[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;++i)//从gap位置开始比较
            for(j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
                swap(a[j],a[j+gap]);
}

// heap sort
void MinHeapInsert(int a[],int i)
{
    int j=(i-1)/2;//找到i结点的根节点
    int temp=a[i];//将待插入新值保存
    while(j>=0&&i!=0)
    {
        if(a[j]<=temp)//说明若将值放在此位置,此时的堆已是最小堆
            break;
        a[i]=a[j];//根结点向下移动
        i=j;
        j=(i-1)/2;
    }
    a[i]=temp;//找到了合适的位置，对i点进行赋值
}
void MinHeapDelete(int a[],int i,int n)//堆的删除
{
    int j,temp=a[i];
    j=2*i+1;//节点i的左孩子
    while(j<n)
    {
        if(j+1<n&&a[j+1]<a[j])//在左右孩子中找到最小的
            j++;
        if(a[j]>=temp)//满足该条件时说明原始堆有序
            break;
        a[i]=a[j];//小数据上移，替换其父节点
        i=j;
        j=2*i+1;//继续处理
    }
    a[i]=temp;
}
void MakeMinHeap(int a[],int n)//建立最小堆
{
    for(int i=n/2-1;i>=0;--i)//认为叶子节点都是符合最小堆的
        MinHeapDelete(a,i,n);
}
void MinHeapSort(int a[],int n)//最小堆排序获得的是递减的数组
{
    for(int i=n-1;i>=1;--i)
    {
        swap(a[i],a[0]);//每次“删除”最小堆的根节点
        MinHeapDelete(a,0,i);//每次都是从0(根节点开始调整)
    }
}

// quick sort
void quickSort(int a[],int first,int last)
{
    int i=first,j=last;
    if(i>j)
        return;
    while(i<j)
    {       
        while(i<j&&a[j]>=a[first])//从后往前找小于基准数的位置
            j--;
        while(i<j&&a[i]<=a[first])//从前往后找大于基准数的位置
            i++;
        if(i<j)//注意，i,j不能相遇或交叉
            swap(a[i],a[j]);
    }
    swap(a[first],a[j]);
    quickSort(a,first,j-1);
    quickSort(a,j+1,last);
}


// merge sort
void mergearr(int *arr, int p, int q, int r){
    int len1 = q - p + 1;
    int len2 = r - q;
    // 创建长度为len1和len2的新数组。
    int *arr1 = new int[len1 + 1];
    int *arr2 = new int[len2 + 1];
    // 赋值，尾部值为无穷。
    for(int i = 0; i < len1; i++){
        arr1[i] = arr[p + i];
    }
    for(int i = 0; i < len2; i++){
        arr2[i] = arr[q + 1 + i];
    }
    arr1[len1] = INT_MAX;
    arr2[len2] = INT_MIN;
    // 比较两个新数组的元素大小，将小的元素添加的arr，进行排序。
    for(int k = 0, i = 0, j = 0; k < len1 + len2; k++){
        if(arr1[i] < arr2[j]){
            arr[p + k] = arr1[i++];
        }else{
            arr[p + k] = arr2[j++];
        }
    }
}
void mergeSort(int *arr, int p, int r){
    if (p < r){
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        mergearr(arr, p, q, r);
    }

}

// 二分法
// def binary_search(l, r):
//     while l < r:
//         m = l + (r - l) // 2
//         if f(m):    # 判断找了没有，optional
//             return m
//         if g(m):
//             r = m   # new range [l, m)
//         else:
//             l = m + 1 # new range [m+1, r)
//     return l    # or not found