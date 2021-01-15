#pragma once

#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        TreeNode *node = new TreeNode(nums[mid]);

        auto left = vector<int>(nums.begin(), nums.begin() + mid);
        auto right = vector<int>(nums.begin() + mid + 1, nums.end());

        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);

        return node;
    }
};