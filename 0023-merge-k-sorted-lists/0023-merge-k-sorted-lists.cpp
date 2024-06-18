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
    void addToTail(ListNode* &head,int val)
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

    void sort(ListNode* &head)
    {
        if(head==nullptr || head->next==nullptr)
        return;
        ListNode* ptr;
        bool swap=true;
        while(swap)
        {
            ptr=head;
            swap=false;
            while(ptr->next!=nullptr)
            {
                if(ptr->val>ptr->next->val)
                {
                    int temp=ptr->val;
                    ptr->val=ptr->next->val;
                    ptr->next->val=temp;
                    swap=true;
                }
                ptr=ptr->next;
            }
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* list=nullptr;
        for(int i=0;i<lists.size();++i)
        {
            ListNode* ptr=lists[i];
            while(ptr!=nullptr)
            {
                addToTail(list,ptr->val);
                ptr=ptr->next;
            }
        }
        sort(list);
        return list;
    }
};