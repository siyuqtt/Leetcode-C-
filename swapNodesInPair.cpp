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
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr) return head;
        ListNode *curr = head;
        if(head->next != nullptr) head = head->next;
        else return head;
        ListNode *four[4];
        ListNode *preT = nullptr;
        int count = 0;
        while(curr != nullptr){
            four[count] = curr;                
            curr = curr->next;
            count ++;
            if(count == 4){
                if(preT != nullptr) preT->next = four[1];
                four[1]->next = four[0];
                four[0]->next = four[3];
                four[3]->next = four[2];
                four[2]->next = curr;
                preT = four[2];
                count = 0;
            }
        }
        
        if(count == 2){
            if(preT != nullptr) preT->next = four[1];
            four[1]->next = four[0];
            four[0]->next = nullptr;
        }
        if(count == 3){
            if(preT != nullptr) preT->next = four[1];
            four[1]->next = four[0];
            four[0]->next = four[2]; 
            
        }
       
        return head;
    }
};
