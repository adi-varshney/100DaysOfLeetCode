// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // Handle 0 or 1 node
        if (!head || !head->next)
            return true;

        ListNode *end = head;

        int length = 0;
        while (end)
        {
            length++;
            end = end->next;
        }

        ListNode *curr = head;    // current node
        ListNode *prev = nullptr; // node which points to the rest of the reversed list at the end
        ListNode *nxt = curr->next;
        for (int i = 0; i < length / 2; i++)
        { // reverse first half of list
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if (length % 2 == 1)
            curr = curr->next; // if length is odd then skip the middle node

        while (prev && curr)
        { // check if it is palindrome
            if (prev->val != curr->val)
                return false;
            prev = prev->next;
            curr = curr->next;
        }

        return true;
    }
};