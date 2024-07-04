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
    void insertAtTail(ListNode* &head,long long int val)
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

    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr)
        return nullptr;
        ListNode* list=nullptr;
        ListNode* node=head;
        if(node->val==0)
        node=node->next;
        long long int sum=0;
        while(node!=nullptr)
        {
            if(node->val!=0)
            sum+=node->val;
            else
            {
                if(sum>0)
                insertAtTail(list,sum);
                sum=0;
            }
            node=node->next;
        }
        if(sum>0)
        insertAtTail(list,sum);
        return list;
    }
};