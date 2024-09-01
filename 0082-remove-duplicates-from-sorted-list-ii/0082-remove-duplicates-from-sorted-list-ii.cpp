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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(head!=nullptr)
        {
            bool isDuplicate=false;
            while(head->next!=nullptr && head->val==head->next->val)
            {
                isDuplicate=true;
                ListNode* temp=head->next;
                head->next=head->next->next;
                delete temp;
            }
            if(isDuplicate)
            {
                ListNode* temp=head;
                prev->next=head->next;
                head=head->next;
                delete temp;
            }
            else
            {
                prev=head;
                head=head->next;
            }
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};