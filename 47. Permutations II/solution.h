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
    void dfs(vector<int> &nums, vector<vector<int >> &res,
             int level, vector<int> &out, vector<bool> &visited) {
        if (level >= nums.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            visited[i] = true;
            out.push_back(nums[i]);
            dfs(nums, res, level + 1, out, visited);
            out.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> out;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, 0, out, visited);
        return res;
    }
};
