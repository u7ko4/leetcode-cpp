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
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int end = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[end - 2] < nums[i]) {
                nums[end++] = nums[i];
            }
        }
        return end;
    }
};
