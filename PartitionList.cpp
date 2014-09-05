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
        if(head == nullptr) return head;
        ListNode * less = nullptr,*lesshead = nullptr;
        ListNode * greater = nullptr,*greaterhead = nullptr;
        while( head->next != nullptr){
            if(head->val < x){
                if(less == nullptr){
                    less = head;
                    lesshead = less;
                }else{
                    less->next = head;
                    less = less->next;
                }
            }else{
                if(greater == nullptr){
                    greater = head;
                    greaterhead = greater;
                }else{
                    greater->next = head;
                    greater = greater->next;
                }
            }
            head = head->next;
        }
        
        greater = nullptr;
        if(lesshead != nullptr) {
            less->next = greaterhead;
            return lesshead;
        }else{
            return greaterhead;
        }
        
    }
};
