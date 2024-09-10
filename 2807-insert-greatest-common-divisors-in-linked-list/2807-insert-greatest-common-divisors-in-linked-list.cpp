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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;

        ListNode* ptr1=head;
        ListNode* ptr2=head->next;

        function<int(int,int)>gcd=[&](int num1,int num2)->int
        {
            return (num2==0) ? num1 : gcd(num2,num1%num2);
        };

        while(ptr2!=nullptr)
        {
            ListNode* n=new ListNode(gcd(ptr1->val,ptr2->val));
            
            n->next=ptr2;
            ptr1->next=n;

            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        return head;
    }
};