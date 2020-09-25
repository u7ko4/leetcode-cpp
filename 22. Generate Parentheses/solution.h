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
    void backtrack(vector<string> &res, string c, int open, int close, int n) {
        if (c.size() == n * 2) {
            res.emplace_back(c);
            return;
        }
        if (open < n) {
            backtrack(res, c + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(res, c + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};
