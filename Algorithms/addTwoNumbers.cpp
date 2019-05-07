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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr && l2 != nullptr) {
            return l2;
        } else if (l1 !=nullptr && l2 == nullptr) {
            return l1;
        } else if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int newValue = (carry + l1->val + l2->val);
            if (newValue >= 10){
                carry = 1;
            }else {
                carry = 0;
            }
            current->next = new ListNode(newValue%10);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;   
        }
        while(l1 != nullptr){
            current->next = new ListNode((carry + l1->val)%10);
            current = current->next;
            if(carry + l1->val >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            l1 = l1->next;
        }
        while(l2 != nullptr){
            current->next = new ListNode((carry + l2->val)%10);
            current = current->next;
            if(carry + l2->val >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            l2 = l2->next;
        }
        if(carry>0){
            current->next = new ListNode(carry);
        }
        return dummy->next;
        
    }
};