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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;

        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* temp;
        while(cur!=NULL)
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }  
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
        return head;
        ListNode* dummy=new ListNode(-600);
        dummy->next=head;
        ListNode* temp1;
        ListNode* temp2;
        ListNode* temp=dummy;
        int l=left,r=right;
        while(temp)
        {
            l--;
            r--;
            if(l==0)
            temp1=temp;
            if(r==0)
            temp2=temp;
            temp=temp->next;

        }
        ListNode* end=temp2->next->next;
        ListNode* newh=temp1->next;
        temp1->next=NULL;
        temp2->next->next=NULL;
        newh=reverseList(newh);
        temp1->next=newh;
        while(newh->next)
        {
            newh=newh->next;
        }
        newh->next=end;
        return dummy->next;
        

    }
};