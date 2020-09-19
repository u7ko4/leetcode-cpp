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
    string convert(string s, int numRows) {
        vector<vector<char>> rows(numRows);
        int n = s.size();
        int idx = 0;
        bool down = true;
        int i = 0;
        while (i < n) {
            if (down) {
                for (int j = 0; j < numRows; ++j) {
                    if (i >= n) break;
                    rows[j].push_back(s[i]);
                    i++;
                }
                idx = numRows - 2;
                down = false;
            } else {
                while (idx > 0) {
                    if (i >= n) break;
                    rows[idx].push_back(s[i]);
                    i++;
                    idx--;
                }
                down = true;
            }
        }
        string r;
        for (auto row: rows) {
            r += string(row.begin(), row.end());
        }
        return r;
    }
};
