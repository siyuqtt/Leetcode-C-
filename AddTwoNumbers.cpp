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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dump(-1);
        ListNode * out  = &dump;
        int sumup;
        int cur = 0;
        int nex = 0;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 != nullptr ){
                if (l2 != nullptr){
                    sumup = l1->val + l2->val;
                    l2 = l2->next;
                }else {
                    sumup = l1->val;
                }
                l1 = l1->next;
            }else {
                sumup = l2->val;
                l2 = l2->next;
            }
            cur = (sumup + nex)%10;
            nex = (sumup + nex)/10;
            out->next = new ListNode(cur);
            out = out->next;
        }
        if (nex != 0){
            out->next = new ListNode(nex);
        }
        return dump.next;
    }
};
