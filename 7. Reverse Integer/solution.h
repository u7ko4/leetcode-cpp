#pragma once

#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        long value = 0;
        while (x != 0) {
            int r = x % 10;
            x = x / 10;
            value = value * 10 + r;
            if (value > INT_MAX || value < INT_MIN) {
                return 0;
            }
        }
        return value;
    }
};