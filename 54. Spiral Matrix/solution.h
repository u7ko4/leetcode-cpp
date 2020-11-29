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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int rows = matrix.size(), cols = matrix[0].size();
        int up = 0, down = rows - 1, left = 0, right = cols - 1;
        while (true) {
            // left to right
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;
            // up to down
            for (int i = up; i <= down; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            // right to left
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) break;
            // down to up
            for (int i = down; i >= up; --i) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};
