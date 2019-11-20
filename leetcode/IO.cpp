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

// 输入
    // 字符
    // ch=cin.get(); //或者cin.get(ch);只能获取一个字符
    // 字符串输入
    // 遇“空格”、“Tab”、'\n'都结束
    // char a[20];
    // cin>>a;
    // cin >> s;
    // 可以读入空格、制表符，以回车结束 '\n'
    // getline(cin, m);
    // cin.getline(m,5);  接受5个字符到m中，其中最后一个为'\0'
    // gets(m);
    
    // 逗号分隔！（输入的字符串是逗号分开的）
    // stringstream 可以用于分割被空格、制表符等符号分割的字符串
    // string str="i am a boy";  
    // istringstream is(str);  
    // string s;  
    // while(is>>s)  {  
    //     cout<<s<<endl;  // i/am/a/boy
    // }  
    // std::string str ="1,2,3,4,5,6";
    // std::vector<int> vect;
    // std::stringstream ss(str);
    // int i;
    // while (ss >> i)
    //     vect.push_back(i);
    //     if (ss.peek() == ',')
    //         ss.ignore();
    // }
    // 或者
    // while( ss.good() )    {
    //     string substr;
    //     getline( ss, substr, ',' );
    //     result.push_back( substr );
    // }

    // string 字符串操作
    // 查找子串
    // s.find(t);
    // 字符串连接
    // s1 = s1+s2;
    // s1.append(s2);
    // 转字符数组
    // s = str; // str 为char数组
    // strcpy(str, s.c_str()); // str 为char数组
    
    // // 预先不输入数据的组数
    // int a;
    // vector<int> array;
    // while(cin>>a){
    //     array.push_back(a);
    // }
    // 或者
    // while(cin.get() != '\n'){
    //     cin >> a;
    //     array.push_back(a);
    // }

    // 多组输入
    // while(cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    // cout << a+b << endl;
    // 预知组数，多行输入
    // cin >> n;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         int x; scanf("%d",&x);
    //         ans += x;
    //     }
    // }


// 输出
    // // 不需要输出case数
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int a, b;
    //     cin>>a>>b;
    //     cout<<a+b<<endl;
    // }
    // // 需要输出case数
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int a, b;
    //     cin>>a>>b;
    //     cout<<"Case"<<i+1<<a+b<<endl;
    // }
    // // 每个case之后有空行
    // for(int i=0; i<n; i++){
    //     int a, b;
    //     cin>>a>>b;
    //     cout<<"Case"<<i+1<<a+b<<endl<<endl;
    // }
    // // 两个Case之间有空行
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int a, b;
    //     cin>>a>>b;
    //     if(i>0){
    //         cout<<endl;
    //     }
    //     cout<<"Case"<<i+1<<a+b<<endl;
    // }


