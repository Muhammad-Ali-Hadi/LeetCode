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
    long long int decimal(string num,long long int units=0)
    {
        return ((stoi(num))==0) ? 0 : ((stoi(num))%10)*pow(2,units)+decimal((stoi(num))/10,units+1);
    }

    int getDecimalValue(ListNode* head) {
        if(head->next==nullptr)
        return head->val;
        long long int num=0;
        // while(head!=nullptr)
        // {
        //     num=(num*10)+head->val;
        //     head=head->next;
        // }
        string str="";
        while(head!=nullptr)
        {
            str+=head->val+'0';
            head=head->val;
        }
        return decimal(num);
    }
};