#pragma once

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int com = target - nums[i];
            if (m.find(com) != m.end()) {
                return vector<int>{m[com], i};
            }
            m.insert({nums[i], i});
        }
        throw std::runtime_error("No two sum");
    }
};