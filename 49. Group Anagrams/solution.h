#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) != map.end()) {
                map[tmp].push_back(str);
            } else {
                map[tmp] = {str};
            }
        }
        res.reserve(map.size());
        for (auto &i : map) {
            res.push_back(i.second);
        }
        return res;
    }
};
