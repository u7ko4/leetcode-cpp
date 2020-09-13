#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int diff = INT_MAX;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size & diff != 0; ++i) {
            int low = i + 1;
            int high = size - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return target - diff;
    }
};
