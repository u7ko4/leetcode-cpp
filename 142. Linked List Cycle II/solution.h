#pragma once

#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};