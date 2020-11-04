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
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, sum = 0;
        for (int num :nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};
