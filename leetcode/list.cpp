#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//28 strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        
        int haystacksize = haystack.size();
        int needlesize = needle.size();
        for (int i=0; i< haystacksize - needlesize +1; i++){
            if (haystack[i]!= needle[0]) continue;
            int j = 1;
            for(; j< needlesize; j++){
                if (haystack[i+j]!=needle[j]) break;
            }
            if (j==needlesize)
                return i;
        }
        return -1;
    }
};