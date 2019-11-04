#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int nlines;
    cin >> nlines;

    // vector<string> s(2);
    // cin >> s[0];

    vector<string> charlist(nlines);
    for(int i = 0; i < nlines; i++){
        cin >> charlist[i];
        int size = charlist[i].size();
        charlist[i][size-1] = (char)toupper(charlist[i][size-1]);
        }

    for(int i = 0; i < nlines; i++){
        cout << charlist[i] << endl;
    }

    return 0;
}

// int main() {
//     // int a,b;
//     // while(cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//     //     cout << a+b << endl;

//     char a = 'a';
//     cout << (char)toupper(a);
// }