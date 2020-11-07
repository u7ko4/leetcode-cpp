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
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int l = i >= 0 ? a[i] - '0' : 0;
            int r = j >= 0 ? b[j] - '0' : 0;
            int sum = l + r + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            i--;
            j--;
        }
        if (carry > 0) {
            return "1" + res;
        }
        return res;
    }
};
