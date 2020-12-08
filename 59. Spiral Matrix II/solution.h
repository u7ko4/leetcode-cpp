#pragma once

#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        while (true) {
            // left to right
            for (int i = left; i <= right; ++i) {
                res[up][i] = val++;
            }
            if (++up > down) break;
            // up to down
            for (int i = up; i <= down; ++i) {
                res[i][right] = val++;
            }
            if (--right < left) break;
            // right to left
            for (int i = right; i >= left; --i) {
                res[down][i] = val++;
            }
            if (--down < up) break;
            // down to up
            for (int i = down; i >= up; --i) {
                res[i][left] = val++;
            }
            if (++left > right) break;
        }
        return res;
    }
};