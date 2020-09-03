#pragma once

#include <map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        // IV=>5, IX=>9
        // XL=>40, XC=>90
        // CD=>400, CM=>900
        map<char, int> m = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int value = 0;
        int count = s.size();
        int i = 0;
        while (i < count) {
            const char c = s[i];
            if (i == count - 1) {
                value += m[c];
            } else {
                const char next = s[i + 1];
                if (c == 'I') {
                    if (next == 'V' || next == 'X') {
                        value += m[next] - m[c];
                        i = i + 2;
                        continue;
                    }
                } else if (c == 'X') {
                    if (next == 'L' || next == 'C') {
                        value += m[next] - m[c];
                        i = i + 2;
                        continue;
                    }
                } else if (c == 'C') {
                    if (next == 'D' || next == 'M') {
                        value += m[next] - m[c];
                        i = i + 2;
                        continue;
                    }
                }
                value += m[c];
            }
            i++;
        }
        return value;
    }
};