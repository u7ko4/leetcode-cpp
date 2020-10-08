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
    void dfs(vector<int> &nums, int start, vector<vector<int>> &res) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
};
