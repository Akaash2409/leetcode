
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;


        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *prev =NULL, *cur=slow->next, *Next;
        while (cur) {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        slow->next=NULL;

        ListNode *A = head, *B=prev;
        while (A && B) {
            ListNode* A_next=A->next;
            ListNode *B_next=B->next;

            A->next=B;
            B->next=A_next;

            A=A_next;
            B=B_next;
        }
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();