#include <iostream>
#include <algorithm>
#include <vector>


// //基类
// class D
// {
// public:
//     D(){cout<<"D()"<<endl;}
//     ~D(){cout<<"~D()"<<endl;}
// protected:
//     int d;
// };

// class B:virtual public D
// {
// public:
//     B(){cout<<"B()"<<endl;}
//     ~B(){cout<<"~B()"<<endl;}
// protected:
//     int b;
// };

// class A:virtual public D
// {
// public:
//     A(){cout<<"A()"<<endl;}
//     ~A(){cout<<"~A()"<<endl;}
// protected:
//     int a;
// };

// class C:public B, public A
// {
// public:
//     C(){cout<<"C()"<<endl;}
//     ~C(){cout<<"~C()"<<endl;}
// protected:
//     int c;
// };

int main()
{
    // C c;   //D, B, A ,C
    // std::cout<<sizeof(c)<<std::endl;

    std::vector<std::string> names;
    names.push_back("James");
    names.push_back("Tom");
    names.push_back("Kelly");

    std::sort(names.begin(), names.end());

    std::vector<std::string>::iterator iter= names.begin();
    while (iter != names.end()) {
        std::cout << *iter << std::endl;
        iter++;
    }

    return 0;
}