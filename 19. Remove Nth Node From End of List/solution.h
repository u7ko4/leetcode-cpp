#pragma once

#include <vector>
#include <string>
#include <map>
#include <array>

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) return head;
        vector<ListNode *> nodes;
        ListNode *node = head;
        while (node != nullptr) {
            nodes.push_back(node);
            node = node->next;
        }
        int length = nodes.size();
        int index = length - n;
        if (index == 0) {
            if (nodes.size() == 1) {
                head = nullptr;
            } else {
                head = nodes[1];
            }
        } else {
            if (index == length - 1) {
                nodes[index - 1]->next = nullptr;
            } else {
                nodes[index - 1]->next = nodes[index + 1];
            }
        }
        return head;
    }
};
