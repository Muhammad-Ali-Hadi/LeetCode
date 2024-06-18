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
        bool flag=true;
        while(flag)
        {
            flag=false;
            ptr=head;
            while(ptr->next!=nullptr)
            {
                if(ptr->val>ptr->next->val)
                {
                    int temp=ptr->val;
                    ptr->val=ptr->next->val;
                    ptr->next->val=temp;
                    flag=true;
                }
                ptr=ptr->next;
            }
        }
    }

    ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
        ListNode* list=nullptr;
        if(list1==nullptr && list2==nullptr)
        return list;
        else if(list1==nullptr)
        {
            return list2;
        }
        else if(list2==nullptr)
        {
            return list1;
        }
        else
        {
            ListNode* ptr1=list1;
            ListNode* ptr2=list2;
            while(ptr2!=nullptr)
            {
                if(ptr1!=nullptr)
                {
                    addToTail(list,ptr1->val);
                    ptr1=ptr1->next;
                }
                else
                {
                    addToTail(list,ptr2->val);
                    ptr2=ptr2->next;
                }
            }
        }
        sort(list);
        return list;
    }
};