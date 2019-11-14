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

//49. Group Anagrams 字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mv;
    for (int i= 0; i < strs.size(); ++i) {
        string t = strs[i];
        //将strs中的元素排序，排序完的t作为key，原本的strs[i]作为value
        sort(t.begin(), t.end());
        mv[t].push_back(strs[i]);
    }
    //c++中一种遍历map的快捷方式
    for (auto a : mv) {
        res.push_back(a.second);
    }
    return res;   
}
//如果不使用排序，我们就要把strs中的元素映射到一个26位的数组中，然后重新按照26位字母顺序组成key值
vector<vector<string>> groupAnagrams_nosortstring(vector<string>& strs) {
    vector<vector<string> >res;
    unordered_map<string,vector<string>> mv;
    for(int i= 0; i < strs.size(); ++i)
    {
        vector<int> cnt(26,0);
        string t = "";
        for(char c: strs[i])
        {
            ++cnt[c-'a'];
        }
        for(int d:cnt)
        {
            t += to_string(d)+"/";
        }
        mv[t].push_back(strs[i]);
    }
    for(auto a:mv)
    {
        res.push_back(a.second);
    }
    return res;
}

// 347. Top K Frequent Elements 前k个高频元素
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    priority_queue<pair<int, int>> maxheap;
    vector<int> res;
    for (auto i: nums){
        hash[i]++;
    }
    for (auto it: hash){
        maxheap.push(make_pair(it.second, it.first));
    }
    for (int j = 0; j < k; j++){
        res.push_back(maxheap.top().second);
        maxheap.pop();
    }
    return res;
    // unordered_map<int, int> um;
    // priority_queue<pair<int, int>> p;
    // vector<int> res;
    // for (auto a : nums) 
    //     ++um[a];
    // for (auto it : um) 
    //     p.push({it.second, it.first});
    // for (int i = 0; i < k; ++i) 
    // {
    //     res.push_back(p.top().second); 
    //     p.pop();
    // }
    // return res;
}