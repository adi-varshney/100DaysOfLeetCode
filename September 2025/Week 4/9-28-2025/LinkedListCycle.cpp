// 141: Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

#include <cstddef>
#include <unordered_set>    
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution 1(space complexity O(n), doesn't satisfy problem constraints)
// This solution uses a hash set to track visited nodes.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        while (head != nullptr) {
            if (nodes.count(head) == 1)
                return true;
            
            nodes.insert(head);
            head = head->next;
        }

        return false;
    }
};

// Solution 2(sorta cheesed it??)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head != nullptr) {
            if (head->val == INT_MAX)
                return true;
            
            head->val = INT_MAX;
            head = head->next;
        }

        return false;
    }
};

// Solution 3(solution that problem intended)
// This solution uses the two-pointer technique (Floyd's Cycle-Finding Algorithm).
// It uses two pointers, one moving twice as fast as the other. If they meet,
// it indicates a cycle.
// Time complexity is O(n) and space complexity is O(1).
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //unordered_set<ListNode*> nodes;

        if (head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast)
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};