#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string s = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            const string &n = strs[i];
            string c;
            for (int j = 0; j < min(s.size(), n.size()); ++j) {
                if (s[j] == n[j]) {
                    c += s[j];
                } else {
                    break;
                }
            }
            s = c;
        }
        return s;
    }
};
