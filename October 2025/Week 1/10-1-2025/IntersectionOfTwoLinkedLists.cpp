// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <cstddef>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution 1 (doesn't meet O(1) space constraint)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *a = headA;
        ListNode *b = headB;
        unordered_set<ListNode *> seen;

        while (a != nullptr)
        {
            seen.insert(a);
            a = a->next;
        }

        while (b != nullptr)
        {
            if (seen.find(b) != seen.end())
                return b;

            b = b->next;
        }

        return nullptr; // if no intersection
    }
};

// Solution 2
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *a = headA;
        ListNode *b = headB;
        unordered_set<ListNode *> seen;

        int l1 = 1;
        int l2 = 1;
        while (a != nullptr || b != nullptr)
        {
            if (a == nullptr)
            {
                b = b->next;
                l2++;
            }
            else if (b == nullptr)
            {
                a = a->next;
                l1++;
            }
            else
            {
                a = a->next;
                b = b->next;
                l1++;
                l2++;
            }
        }

        while (l1 != l2)
        {
            if (l1 > l2)
            {
                headA = headA->next;
                l1--;
            }
            else
            {
                headB = headB->next;
                l2--;
            }
        }

        while (l1)
        {
            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
            l1--;
        }

        return nullptr; // if no intersection
    }
};