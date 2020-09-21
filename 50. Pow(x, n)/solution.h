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
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        uint64_t m = n;
        double val = 1;
        if (n < 0) m = -1 * m;
        while (m > 0) {
            if (m % 2 == 0) {
                x = x * x;
                m = m / 2;
            } else {
                val *= x;
                m = m - 1;
            }
        }
        if (n < 0) return (double) 1.0 / val;
        return val;
    }
};
