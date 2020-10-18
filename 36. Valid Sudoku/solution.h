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
    bool isValidSudoku(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        unordered_map<int, set<char>> rows, cols, blocks;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i].find(board[i][j]) != rows[i].end()) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                if (cols[j].find(board[i][j]) != cols[j].end()) {
                    return false;
                }
                cols[j].insert(board[i][j]);
                int b = i / 3 * 3 + j / 3;
                if (blocks[b].find(board[i][j]) != blocks[b].end()) {
                    return false;
                }
                blocks[b].insert(board[i][j]);
            }
        }
        return true;
    }
};
