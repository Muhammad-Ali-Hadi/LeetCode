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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(getSize(head)<=2)
        return {-1,-1};
        vector<int> nums;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        while(curr->next!=nullptr)
        {
            ListNode* next=curr->next;
            if(((curr->val)>(prev->val) && (curr->val)>(next->val)) || ((curr->val)<(prev->val) && (curr->val)<(next->val)))
            nums.push_back(index);
            prev=curr;
            curr=next;
            ++index;
        }

        if(nums.size()<2)
        return {-1,-1};

        int minDist=INT_MAX;
        for(int i=0;i<nums.size()-1;++i)
        {
            minDist=min(minDist,nums[i+1]-nums[i]);
        }
        return {minDist,nums.back()-nums.front()};
    }
};