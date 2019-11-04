#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n, m;
    cin >> n >> m;
    string temp;
    cin >> temp;

    vector<bool> list(n,true);
    for (int i = 0; i < m; i++){
        int o1, o2;
        cin >> o1 >> o2;
        if (o1 > o2) {
            int t;
            t = o1;
            o1 = o2;
            o2 = t;
        }

        for (int j = o1 - 1; j < o2;j++) {
            list[j] = !list[j];
        }
    }

    for (int i = 0; i < n; i++){
        if (!list[i]) {
            if (temp[i]=='0')
                temp[i] = '1';
            else
                temp[i] = '0';
        }
    }
    cout << temp;

    return 0;
}