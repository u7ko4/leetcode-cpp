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
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 2, j = n - 1;
        // Find first decline number index i reverse
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            // Find first great than ith number index reverse
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        // Reverse remain
        reverse(nums.begin() + i + 1, nums.end());
    }
};
