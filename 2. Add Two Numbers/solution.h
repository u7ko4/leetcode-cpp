#pragma once

#include <vector>
#include <map>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry = false;
        ListNode *root = new ListNode();
        ListNode *h1 = l1, *h2 = l2, *r = root;
        while (true) {
            if (h1 == nullptr || h2 == nullptr) {
                if (h1 == nullptr && h2 == nullptr) {
                    if (carry) {
                        r->next = new ListNode(1);
                    }
                    break;
                }
                int d = carry ? 1 : 0;
                r->val = h1 == nullptr ? (h2->val + d) : (h1->val + d);
                break;
            }

            int sum = h1->val + h2->val + (carry ? 1 : 0);
            carry = sum >= 10;
            r->val = carry ? (sum - 10) : sum;

            if (h1->next != nullptr || h2->next != nullptr) {
                r->next = new ListNode();
                r = r->next;
            }

            h1 = h1->next;
            h2 = h2->next;
        }
        return root;
    }
};