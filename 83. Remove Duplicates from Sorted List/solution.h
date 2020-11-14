#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return head;
        set<int> values;
        ListNode *pre = head, *next = head->next;
        values.insert(head->val);
        while (next != nullptr) {
            if (values.find(next->val) == values.end()) {
                pre->next = next;
                pre = next;
            } else {
                pre->next = nullptr;
            }
            values.insert(next->val);
            next = next->next;
        }
        return head;
    }
};
