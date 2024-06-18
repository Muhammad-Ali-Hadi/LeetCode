        /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr=new ListNode(0);
        ListNode* n=ptr;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr)
        {
            int num1=(l1!=nullptr) ? l1->val : 0;
            int num2=(l2!=nullptr) ? l2->val : 0;
            int sum=num1+num2+carry;
            carry=sum/10;
            n->next=new ListNode(sum%10);
            n=n->next;
            if(l1!=nullptr) 
            l1=l1->next;
            if(l2!=nullptr)
            l2=l2->next;
        }
        if(carry>0)
        n->next=new ListNode(carry);
        ListNode* result=ptr->next;
        delete ptr;
        return result;
    }
};