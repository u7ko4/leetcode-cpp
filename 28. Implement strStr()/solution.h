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
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        if (n == 0) return 0;
        if (h < n) return -1;
        map<char, int> offset;
        for (int i = 0; i < n; ++i) {
            offset[needle[i]] = n - i;
        }
        int i = 0;
        while (i <= h - n) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
            if (i + n > h - 1) {
                return -1;
            }
            auto r = offset.find(haystack[i + n]);
            if (r != offset.end()) {
                i += r->second;
            } else {
                i += n + 1;
            }
        }
        return -1;
    }
};
