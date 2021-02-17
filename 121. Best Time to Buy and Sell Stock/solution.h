#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <set>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int buy = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            buy = min(prices[i], buy);
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};
