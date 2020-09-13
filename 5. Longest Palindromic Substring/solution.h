#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int offset = -1, max_len = INT_MIN;
        int size = s.size();
        int end = size - 1;
        while (end >= 0) {
            int start = 0;
            while (start < end) {
                if (s[start] != s[end]) {
                    start++;
                } else {
                    int len = end - start + 1;
                    bool is_pal = true;
                    if (len > 3) {
                        int l = start + 1, r = end - 1;
                        while (l <= r) {
                            if (s[l] != s[r]) {
                                is_pal = false;
                                break;
                            } else {
                                l++;
                                r--;
                            }
                        }
                    }
                    if (is_pal) {
                        if (len > max_len) {
                            max_len = len;
                            offset = start;
                        }
                        break;
                    } else {
                        start++;
                    }
                }
            }
            end--;
        }
        if (max_len == INT_MIN) {
            return s.substr(0, 1);
        }
        return s.substr(offset, max_len);
    }
};
