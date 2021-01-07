#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <set>
#include <queue>

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
    void levelOrder(TreeNode *node, int level, vector<vector<int>> &res) {
        if (!node) return;
        if (res.size() == level) {
            res.emplace_back();
        }
        res[level].push_back(node->val);
        levelOrder(node->left, level + 1, res);
        levelOrder(node->right, level + 1, res);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
