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
    void dfs(int n, int k, int level, vector<int> &tmp, vector<vector<int>> &res) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for (int i = level; i <= n; ++i) {
            tmp.push_back(i);
            dfs(n, k, i + 1, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(n, k, 1, tmp, res);
        return res;
    }
};
