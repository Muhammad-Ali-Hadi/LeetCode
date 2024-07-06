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

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr=head;
        vector<int> nums;
        for(int i=0;i<getSize(head);++i)
        {
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }
        set<int> set(nums.begin(),nums.end());
        ListNode* list=nullptr;
        for(auto& i : set)
        {
            insertToTail(list,i);
        }
        return list;
    }
};