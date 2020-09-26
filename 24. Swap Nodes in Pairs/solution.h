#pragma once

#include <vector>
#include <string>
#include <map>
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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != nullptr && fast != nullptr) {
            int tmp = slow->val;
            slow->val = fast->val;
            fast->val = tmp;
            if (slow->next != nullptr) {
                slow = slow->next->next;
            }
            if (fast->next != nullptr) {
                fast = fast->next->next;
            }
        }
        return head;
    }
};
