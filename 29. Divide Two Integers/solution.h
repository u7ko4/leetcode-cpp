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
    int divide(int dividend, int divisor) {
        if (divisor == 0) throw runtime_error("Divisor is zero");
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long ldividend = labs(dividend);
        long ldivisor = labs(divisor);
        bool neg = ((dividend < 0) ^ (divisor < 0));
        if (ldivisor == 1) return neg ? -ldividend : ldividend;
        long res = 0;
        while (ldividend >= ldivisor) {
            long t = ldivisor, reg = 1;
            while (ldividend >= (t << 1)) {
                t <<= 1;
                reg <<= 1;
            }
            res += reg;
            ldividend -= t;
        }
        return neg ? -res : res;
    }
};
