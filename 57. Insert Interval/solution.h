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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        int idx = 0;
        for (auto &interval : intervals) {
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
                idx++;
            } else if (interval[0] > newInterval[1]) {
                res.push_back(interval);
            } else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        res.insert(res.begin() + idx, newInterval);
        return res;
    }
};
