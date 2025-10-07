// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;

        while (head->val == val) {
            head = head->next;

            if (head == nullptr)
                return nullptr;
        }

        ListNode* ans = head;

        while (head->next != nullptr) {
            if (head->next->val == val) {
                head->next = head->next->next;
                continue;
            }

            head = head->next;
        }

        return ans;
    }
};