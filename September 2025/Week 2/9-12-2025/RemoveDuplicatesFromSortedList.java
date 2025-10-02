// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

import java.util.HashSet;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    @SuppressWarnings("unused")
    ListNode() {
    }

    @SuppressWarnings("unused")
    ListNode(int val) {
        this.val = val;
    }

    @SuppressWarnings("unused")
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

// My initial solution using a HashSet to track seen values.
// This works for unsorted lists but uses extra space.
@SuppressWarnings("unused")
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        HashSet<Integer> seen = new HashSet<>();

        ListNode iterator = head, prev = null;
        while (iterator != null) {
            if (seen.contains(iterator.val)) {
                prev.next = iterator.next;
                iterator = iterator.next;
            } else {
                seen.add(iterator.val);
                prev = iterator;
                iterator = iterator.next;
            }
        }

        return head;
    }
}

// Optimized solution that leverages the sorted property of the list.
// This approach uses O(1) extra space and is more efficient.
@SuppressWarnings("unused")
class Solution2 {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode iterator = head;
        while (iterator != null && iterator.next != null) {
            if (iterator.val == iterator.next.val) {
                iterator.next = iterator.next.next;
            } else {
                iterator = iterator.next;
            }
        }

        return head;
    }
}