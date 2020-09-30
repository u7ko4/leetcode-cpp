#pragma once

#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> m;
        for (char const &c : s) {
            if (c == '(' | c == '{' | c == '[') {
                m.push(c);
            } else {
                if (c == ')') {
                    if (m.empty()) return false;
                    if (m.top() != '(') {
                        return false;
                    }
                    m.pop();
                } else if (c == '}') {
                    if (m.empty()) return false;
                    if (m.top() != '{') {
                        return false;
                    }
                    m.pop();
                } else if (c == ']') {
                    if (m.empty()) return false;
                    if (m.top() != '[') {
                        return false;
                    }
                    m.pop();
                } else {
                    return false;
                }
            }
        }
        return m.empty();
    }
};