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
    void insertToTail(ListNode* &head,int val)
    {
        ListNode* n=new ListNode(val);
        if(head==nullptr)
        {
            head=n;
            return;
        }
        ListNode* ptr=head;
        while(ptr->next!=nullptr)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
    }

    int getSize(ListNode* head)
    {
        int size=0;
        while(head!=nullptr)
        {
            ++size;
            head=head->next;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        ListNode* list=nullptr;
        if(n==getSize(head))
        {
            ptr=ptr->next;
            for(int i=0;i<getSize(head)-1;++i)
            {
                insertToTail(list,ptr->val);
                ptr=ptr->next;
            }
            return list;
        }
        else
        {
            for(int i=0;i<getSize(head)-n;++i)
            {
                insertToTail(list,ptr->val);
                ptr=ptr->next;
            }
            ptr=ptr->next;
        }
        for(int i=0;i<n-1 && ptr!=nullptr;++i)
        {
            insertToTail(list,ptr->val);
            ptr->next;
        }
        return list;
    }
};