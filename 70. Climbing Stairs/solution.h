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
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int m = 2;
        // dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + ...
        vector<int> dp(n);
        for (int i = 0; i < m; ++i) {
            dp[i] = i + 1;
        }
        for (int i = m; i < n; ++i) {
            int t = 0;
            for (int j = 1; j <= m; ++j) {
                t += dp[i - j];
            }
            dp[i] = t;
        }
        return dp.back();
    }
};
