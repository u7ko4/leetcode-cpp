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
    int mySqrt(int x) {
        if (x <= 0) return x;
        // Newton's method
        // x^2 = n
        // f(x) = x^2 -n
        // f^{'}(x) = 2x
        // eq. x - \frac{f(x)}{2x}
        // x - (x^2 - n)/(2x)
        // (x + n/x)/2
        double accuracy = 1e-7;
        double res = double(x) / 2;
        while (abs(res - (x / res)) > accuracy) {
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
