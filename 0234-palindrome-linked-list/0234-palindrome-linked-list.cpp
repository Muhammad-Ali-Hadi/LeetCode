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

    bool isPalindrome(ListNode* head) {
        if(getSize(head)==1 || (getSize(head)==3 && head->val==head->next->next->val))
        return true;
        if(head->val!=head->next->val && getSize(head)==2)
        return false;
        int mid=getSize(head)/2;
        stack<int> st;
        ListNode* n=head;
        if(getSize(head)%2==0)
        {
            for(int i=0;i<mid;++i)
            {
                st.push(n->val);
                n=n->next;
            }
            for(int i=mid;i<getSize(head);++i)
            {
                if(st.top()!=n->val)
                {
                    return false;
                }
                n=n->next;
                st.pop();
            }
        }
        else
        {
            for(int i=0;i<mid;++i)
            {
                st.push(n->val);
                n=n->next;
            }
            n=n->next;
            for(int i=mid+1;i<getSize(head);++i)
            {
                if(st.top()!=n->val)
                {
                    return false;
                }
                n=n->next;
                st.pop();
            }
        }
        return true;
    }
};