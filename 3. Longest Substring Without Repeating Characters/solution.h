#pragma once

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length(), res = 0;
        map<char, int> m;
        int i = 0, j = 0;
        while (j < size) {
            char c = s[j];
            auto x = m.find(c);
            if (x != m.end()) {
                i = max(x->second, i);
            }
            res = max(res, j - i + 1);
            m[c] = j + 1;
            j++;
        }
        return res;
    }
};