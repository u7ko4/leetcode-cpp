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
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (i > 0 && s[i - 1] == ' ') {
                    res = 1;
                } else {
                    res++;
                }
            }
        }
        return res;
    }
};
