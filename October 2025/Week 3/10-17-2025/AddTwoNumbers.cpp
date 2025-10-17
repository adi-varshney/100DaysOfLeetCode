// 2. Add Two Numbers - Medium
// https://leetcode.com/problems/add-two-numbers/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// I think the best strategy for this is to create a new linked list along the way and sum the 2 current values

// 342 + 465 = 807

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        int carry = 0;
        while (l1 || l2) {
            head->next = new ListNode();
            head = head->next;

            int sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val;
                
                l1 = l1->next;
                l2 = l2->next;
            } else {
                if (l1) {
                    sum = l1->val;
                    l1 = l1->next;
                } else {
                    sum = l2->val;
                    l2 = l2->next;
                }
            }

            sum += carry;

            carry = (sum >= 10) ? 1 : 0;
            
            head->val = sum%10;
        }

        if (carry)
            head->next = new ListNode(carry, nullptr);

        ans = ans->next;

        return ans;
    }
};
