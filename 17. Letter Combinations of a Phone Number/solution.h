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
    vector<string> pc(vector<string> &v, vector<char> &chars) {
        vector<string> n;
        for (string const &s :v) {
            for (char const &c : chars) {
                n.push_back(s + c);
            }
        }
        return n;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<vector<char>> m{
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'},
        };
        res.emplace_back("");
        for (char const &d: digits) {
            res = pc(res, m[d - '2']);
        }
        return res;
    }
};
