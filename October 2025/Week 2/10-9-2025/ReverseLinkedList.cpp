// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* n = head->next;
        while (n != nullptr) {
            head->next = prev;
            prev = head;
            head = n;
            n = n->next;
        }

        head->next = prev;

        return head;
    }
};