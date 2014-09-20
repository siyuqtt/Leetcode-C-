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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return head;
        ListNode * temp = head;
        int cur = head->val;
        while (temp != nullptr){
            if (temp->next != nullptr){
                if (temp->next->val == cur){
                    temp->next = temp->next->next;
                }else{
                    cur  = temp->next->val;
                    temp = temp->next;
                }
            }else temp = temp->next;
            
        }
        return head;
    }
};
