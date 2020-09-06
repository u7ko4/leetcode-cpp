#pragma once

#include <map>
#include <array>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        array<tuple<string, int>, 13> m{
                {
                        {"M", 1000},
                        {"CM", 900},
                        {"D", 500},
                        {"CD", 400},
                        {"C", 100},
                        {"XC", 90},
                        {"L", 50},
                        {"XL", 40},
                        {"X", 10},
                        {"IX", 9},
                        {"V", 5},
                        {"IV", 4},
                        {"I", 1},
                }
        };
        string str;
        for (const auto &[s, n] : m) {
            while (num >= n) {
                str += s;
                num -= n;
            }
        }
        return str;
    }
};
