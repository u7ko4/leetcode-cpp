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
    void rotate(vector<vector<int>> &matrix) {
        // matrix[row][col] => matrix[col][n - row -1]
        // n is even
        // **..    ..**    ....    ....
        // **.. => ..** => .... => ....
        // ....    ....    ..**    **..
        // ....    ....    ..**    **..
        // n is odd
        // ***..    ...**    .....    .....
        // ***..    ...**    .....    .....
        // ..x.. => ..x** => ..x.. => **x..
        // .....    .....    ..***    **...
        // .....    .....    ..***    **...
        int n = matrix.size();
        for (int row = 0; row < n / 2; ++row) {
            for (int col = 0; col < (n + 1) / 2; ++col) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[n - col - 1][row];
                matrix[n - col - 1][row] = matrix[n - row - 1][n - col - 1];
                matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
                matrix[col][n - row - 1] = temp;
            }
        }
    }
};
