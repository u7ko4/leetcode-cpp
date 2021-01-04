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
    void getSubsets(vector<int> &nums, int level, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = level; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        getSubsets(nums, 0, tmp, res);
        return res;
    }
};
