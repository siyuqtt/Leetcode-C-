/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dump1(-1), dump2(-1);
        ListNode * less = &dump1;
        ListNode * greater = &dump2;
        while ( head != nullptr ) {
            if ( head->val < x ) {
                less->next = head;
                less = less->next;
                
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        greater->next = nullptr;
        less->next = dump2.next;
        return dump1.next;
        
    }
};
