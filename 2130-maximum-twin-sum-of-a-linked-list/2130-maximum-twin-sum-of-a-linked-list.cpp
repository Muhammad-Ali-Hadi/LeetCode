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
    int pairSum(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return 0;

        if(head->next->next==nullptr)
        return head->val+head->next->val;

        int sum=0;
        // ListNode* ptr=head;
        // ListNode* last=nullptr;
        // while(ptr!=last)
        // {
        //     ListNode* temp=ptr;
        //     while(temp->next!=last)
        //     {
        //         temp=temp->next;
        //     }
        //     sum=max(sum,ptr->val+temp->val);
        //     ptr=ptr->next;
        //     last=temp;
        // }
        // return sum;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* current=slow;
        ListNode* next=nullptr;
        ListNode* prev=nullptr;
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        
        ListNode* firstHalf=head;
        ListNode* secondHalf=prev;
        while(secondHalf!=nullptr)
        {
            sum=max(sum,firstHalf->val+secondHalf->val);
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return sum;
    }
};