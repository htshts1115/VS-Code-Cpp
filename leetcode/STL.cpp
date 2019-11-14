#include <set>
#include <map>
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

// set; multiset与Set用法一样，只是允许重复元素。
class set_example{
    public:
    void set_ex(){
        set<int>::iterator it;
        set<int> first;
        int myints[]= {10,20,30,40,50};
        set<int> second (myints,myints+5);
        set<int> third (second);
        set<int> fourth (second.begin(), second.end());
        third.rbegin(); third.rend();//rend相当于begin，rbegin相当于end
        third.size();//返回大小
        third.insert(60);
        third.erase(it);
        third.erase(50);//删除元素'50'
        third.find(10);//找元素'10'
        third.count(10); //只可能是1或0
        third.lower_bound(30); third.upper_bound(30);//第一个/最后一个大于等于key_value 
        third.clear();//清除
    }
};

// map
// map 有序，基于红黑树；unordered_map 无序，基于哈希表；
class map_example{
    public:
    void map_ex(){
        map<char, int> first;
        map<char, int>::iterator it;
        first['a'] = 10;
        first.insert(make_pair('b', 20));
        it++;
        ++it;
        it--;
        --it;
        first.erase(1);  //删除元素
        first.count(1); //看有没有关系
        cout<< it->first << it->second;       //键
    }
};

int main(){
// merge
    //merge(first, first + 5, second, second + 5, v.begin(), compare);

// reverse
    // Reverse(myvector.begin(),myvector.end());

// sort 
    // sort(起始地址,结束地址,compare函数);

// unique
    // bool myfunction (int i, int j)
    // {
    // return (i==j);
    // }
    // unique(起始地址,结束地址,去重条件函数);//按照函数里面编写的规则去重，当然也可以没有第三个参数

// hash
    // #define ull unsigned long long
    // ull hash(char *s)
    // {
    // 	int l=strlen(S);
    // 	ull ans=0;
    // 	int seed=27;
    // 	for(int a=0;a<l;a++)
    // 		ans=ans*seed+a[i]-'a'+1;
    // 	return ans;
    // };

// 快速幂 quick power
    // #define ull unsigned long long
    // ull qpow(ull x,ull y,ull p) // x^y mod p
    // {
    //     ull ret=1;
    //     while(y)
    //     {
    //         if(y&1)ret = ret * x % p;
    //         x=x*x%p;
    //         y>>=1;
    //     };
    //     return ret;
    // }

// 验证质数 验证素数 prime
    // bool flag=true;
    // for(int i=1;i<=trunc(sqrt(prime));i++)
    //     if(prime%i==0)flag=false;//置不是素数标志

// gcd 最大公约数 lcm 最小公倍数
    // int gcd(int a,int b)//注意此处a要大于b
    // {
    //     return b==0?a:gcd(b,a%b);
    // };
    // int lcm(int a,int b)
    // {
    //     return a*b/gcd(a,b);
    // };


}