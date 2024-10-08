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
    bool isPalindrome(ListNode* head) {
        // Time Complexity Error!
        // if(getSize(head)==1 || (getSize(head)==3 && head->val==head->next->next->val))
        // return true;
        // if(head->val!=head->next->val && getSize(head)==2)
        // return false;
        // int mid=getSize(head)/2;
        // stack<int> st;
        // ListNode* n=head;
        // if(getSize(head)%2==0)
        // {
        //     for(int i=0;i<mid;++i)
        //     {
        //         st.push(n->val);
        //         n=n->next;
        //     }
        //     for(int i=mid;i<getSize(head);++i)
        //     {
        //         if(st.top()!=n->val)
        //         {
        //             return false;
        //         }
        //         n=n->next;
        //         st.pop();
        //     }
        // }
        // else
        // {
        //     for(int i=0;i<mid;++i)
        //     {
        //         st.push(n->val);
        //         n=n->next;
        //     }
        //     n=n->next;
        //     for(int i=mid+1;i<getSize(head);++i)
        //     {
        //         if(st.top()!=n->val)
        //         {
        //             return false;
        //         }
        //         n=n->next;
        //         st.pop();
        //     }
        // }
        // return true;

        // Two Pointer Approach
        // if(head==nullptr || head->next==nullptr)
        // return true;
        // ListNode* slow=head;
        // ListNode* fast=head;
        // stack<int> st;
        // while(fast!=nullptr && fast->next!=nullptr)
        // {
        //     st.push(slow->val);
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // if(fast!=nullptr)
        // {
        //     slow=slow->next;
        // }

        // while(slow!=nullptr)
        // {
        //     if(st.top()!=slow->val)
        //     return false;
        //     st.pop();
        //     slow=slow->next;
        // }
        // return true;

        // Recursion
        stack<int> st;
        ListNode* ptr=head;
        while(ptr!=nullptr)
        {
            st.push(ptr->val);
            ptr=ptr->next;
        }

        function<bool(ListNode*)>checkPalindrome=[&](ListNode* head)->bool
        {
            if(head==nullptr)
            return true;

            if(st.top()!=head->val)
            return false;

            st.pop();
            return checkPalindrome(head->next);
        };
        return checkPalindrome(head);
    }
};