#pragma once

#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int offset) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = offset; i < candidates.size(); ++i) {
            // Skip same root node
            if (i > offset && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            // No reuse number
            dfs(candidates, res, tmp, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, tmp, target, 0);
        return res;
    }
};