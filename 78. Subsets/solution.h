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
    void dfs(vector<int> &nums, int level, vector<int> &tmp, vector<vector<int>> &res) {
        res.push_back(tmp);
        for (int i = level; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, 0, tmp, res);
        return res;
    }
};
