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
    void insertAtHead(ListNode* &head,int val)
    {
        ListNode* n=new ListNode(val);
        n->next=head;
        head=n;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* list=nullptr;
        while(head!=nullptr)
        {
            insertAtHead(list,head->val);
            head=head->next;
        }
        return list;
    }
};