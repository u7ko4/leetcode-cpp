#pragma once

#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        // '+'=>43,'-'=>45
        // '0'=>48,...,'9'=>57
        int sign = 0;
        bool found = false;
        long value = 0;
        for (char const &c: str) {
            if (c == ' ') {
                if (sign == 0 && !found) {
                    continue;
                } else {
                    return value * (sign == 0 ? 1 : sign);
                }
            } else if (c == 43 && sign == 0 && !found) {
                sign = 1;
            } else if (c == 45 && sign == 0 && !found) {
                sign = -1;
            } else if (c >= 48 && c <= 57) {
                int digit = c - 48;
                if (value == 0) {
                    value += digit;
                } else {
                    value = value * 10 + digit;
                    if (value > INT_MAX) {
                        return (sign == 0 || sign == 1) ? INT_MAX : INT_MIN;
                    }
                }
                found = true;
            } else {
                break;
            }
        }
        return value * (sign == 0 ? 1 : sign);
    }
};