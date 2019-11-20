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
#include <bitset>

using namespace std;


int main_exam(){
    long long n;
    cin >> n;
    if (n<1){
        cout << -1;
        return 0;
    }
    char ch;
    // ch = cin.get();
    cin >> ch;
    if (ch>'9' || ch<'0'){
        cout << -1;
        return 0;
    }

    long long c(0);
    for (long long i = 1; i < n+1; i++){
        string t = to_string(i);
        c += count(t.begin(), t.end(), ch);
    }
    cout << c;
    return 0;
}

int main(){
    // long long n;
    // cin >> n;
    char ch;
    ch = cin.get();
    cout << ch << endl
         << (ch > '9') << endl
         << (ch < '0');

    // string temp = to_string(n);
    // cout << temp << endl
    //      << count(temp.begin(), temp.end(), ch);
    return 0;
}