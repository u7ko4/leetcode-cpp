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
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) return digits;
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
