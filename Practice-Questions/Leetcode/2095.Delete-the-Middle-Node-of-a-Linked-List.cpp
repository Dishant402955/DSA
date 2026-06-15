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
    ListNode* deleteMiddle(ListNode* head) {
        delet(head,head);
        return head;
    }

    void delet(ListNode* &head,ListNode* h)
    {
        if(h==nullptr || h->next==nullptr){
           head=head->next;
        }
        else{
            delet(head->next,h->next->next);
        }
    }
};
