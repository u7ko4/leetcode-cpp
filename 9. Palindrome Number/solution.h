#pragma once

#include <map>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int ori = x;
        long reverse = 0;
        int remain;
        while (x > 0) {
            remain = x % 10;
            reverse = reverse * 10 + remain;
            x = x / 10;
        }
        if (reverse > INT_MAX) return false;
        return ori == reverse;
    }
};