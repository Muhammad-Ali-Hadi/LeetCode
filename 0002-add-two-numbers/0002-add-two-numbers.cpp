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
    // void addToTail(ListNode* &head,int val)
    // {
    //     ListNode* n=new ListNode(val);
    //     if(head==nullptr)
    //     {
    //         head=n;
    //         return;
    //     }
    //     ListNode* ptr=head;
    //     while(ptr->next!=nullptr)
    //     {
    //         ptr=ptr->next;
    //     }
    //     ptr->next=n;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
        if(l1==nullptr && l2==nullptr && carry==0)
        return nullptr;

        // if(l1==nullptr)
        // return l2;

        // if(l2==nullptr)
        // return l1;

        int sum=(l1!=nullptr ? l1->val : 0)+(l2!=nullptr ? l2->val : 0)+carry;

        ListNode* result=new ListNode(sum%10);
        result->next=addTwoNumbers(l1!=nullptr ? l1->next : nullptr,l2!=nullptr ? l2->next : nullptr,sum/10);

        return result;
        // ListNode* ptr1=l1;
        // ListNode* ptr2=l2;
        // ListNode* l=nullptr;
        // int carry=0;
        // while(l1!=nullptr || l2!=nullptr)
        // {
        //     int num1=(l1!=nullptr) ? l1->val : 0;
        //     int num2=(l2!=nullptr) ? l2->val : 0;
        //     int sum=num1+num2+carry;
        //     addToTail(l,(num1+num2+carry)%10);
        //     carry=sum/10;
        //     if(l1!=nullptr)
        //     l1=l1->next;
        //     if(l2!=nullptr)
        //     l2=l2->next;
        // }
        // if(carry>0)
        // addToTail(l,carry);
        // return l;
        // ListNode* ptr1=l1;
        // ListNode* ptr2=l2;
        // string s1,s2;
        // while(ptr1!=nullptr)
        // {
        //     s1+=(ptr1->val+'0');
        //     ptr1=ptr1->next;
        // }
        // while(ptr2!=nullptr)
        // {
        //     s2+=(ptr2->val+'0');
        //     ptr2=ptr2->next;
        // }

        // ListNode* list=nullptr;
        
        // function<void(int)>tailInsertion=[&](int val)
        // {
        //     ListNode* n=new ListNode(val);
        //     if(list==nullptr)
        //     {
        //         list=n;
        //         return;
        //     }
        //     ListNode* temp=list;
        //     while(temp->next!=nullptr)
        //     {
        //         temp=temp->next;
        //     }
        //     temp->next=n;
        // };

        // string result=to_string(stol(s1)+stol(s2));

        // for(int i=result.size()-1;i>=0;--i)
        // {
        //     tailInsertion(result[i]-'0');
        // }
        // return list;

        
    }
};