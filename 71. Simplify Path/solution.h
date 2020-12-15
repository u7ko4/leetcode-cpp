#pragma once

#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token;
        istringstream stream(path);
        vector<string> vec;
        while (getline(stream, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == ".." && !vec.empty()) {
                vec.pop_back();
            } else if (token != "..") {
                vec.push_back(token);
            }
        }
        string res;
        for (auto s : vec) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};