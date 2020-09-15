#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int last = size - 1;
        set<tuple<int, int>> dup;
        for (int fir = 0; fir < nums.size() - 2; ++fir) {
            int sec = fir + 1, thr = last;
            while (sec < thr) {
                int sum = nums[fir] + nums[sec] + nums[thr];
                if (sum == 0) {
                    auto tup = make_tuple(nums[fir], nums[sec]);
                    if (dup.find(tup) == dup.end()) {
                        dup.insert(tup);
                        res.push_back({nums[fir], nums[sec], nums[thr]});
                    }
                    sec++;
                    thr--;
                } else {
                    if (sum > 0) {
                        thr--;
                    } else {
                        sec++;
                    }
                }
            }
        }
        return res;
    }
};
