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
    void insertAtTail(ListNode* &head,int val)
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

    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;

        ListNode* list=nullptr;
        // if(getSize(head)%2==0)
        // {
            ListNode* ptr=head;
            int mid=getSize(head)/2;
            for(int i=0;i<getSize(head);++i)
            {
                if(i<mid)
                ptr=ptr->next;
                else
                {
                    insertAtTail(list,ptr->val);
                    ptr=ptr->next;
                }
            }
        // }
        // else
        // {
        //     ListNode* ptr=head;
        //     int mid=getSize(head)/2;
        //     for(int i=0)
        // }
        return list;
    }
};