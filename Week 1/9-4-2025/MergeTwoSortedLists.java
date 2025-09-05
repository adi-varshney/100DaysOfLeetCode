
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        //ListNode curr1 = list1;
        //ListNode curr2 = list2;

        if ( list1 == null )
            return list2;
        if ( list2 == null )
            return list1;

        ListNode sort = null;

        while (list1 != null && list2 != null) { // First merge both lists in order of greatest to least(opposite/reverse order that we want)
            if (list1.val < list2.val) {
                sort = new ListNode(list1.val, sort); // Add next smallest number
                list1 = list1.next; // Move to the next node
            } else {
                sort = new ListNode(list2.val, sort); // Add next smallest number
                list2 = list2.next; // Move to the next node
            }
        }

        while (list1 != null && list2 == null) {
            sort = new ListNode(list1.val, sort); // Add next smallest number
            list1 = list1.next; // Move to the next node
        }

        while (list2 != null && list1 == null) {
            sort = new ListNode(list2.val, sort); // Add next smallest number
            list2 = list2.next; // Move to the next node
        }

        ListNode prev = null, next;
        while ( sort != null ) { // Then reverse the reversed linked list to get the sorted linked list that we want
            next = sort.next;

            sort = new ListNode(sort.val, prev);
            prev = sort;
            sort = next;
        }
        
        return sort;
    }
}