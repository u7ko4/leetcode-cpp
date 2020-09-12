#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int count = 1, index = 0;
        int last = nums[index];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                nums[index + 1] = nums[i];
                count += 1;
                last = nums[i];
                index += 1;
            }
        }
        return count;
    }
};
