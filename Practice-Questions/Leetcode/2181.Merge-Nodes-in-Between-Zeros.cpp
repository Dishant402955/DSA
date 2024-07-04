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
    ListNode* mergeNodes(ListNode* head) {
        
        int sum = 0;
        vector<int> ans;
        
        ListNode* temp = head->next;
        
        while( temp != NULL){
            
            if(temp->val){
                sum += temp->val;
            }   
            else{
                ans.push_back(sum);
                sum = 0;
            }
            
            temp = temp->next;
            
        }
        
        temp = head;
        temp->val = ans[0];
        
        for(int i = 1 ; i < ans.size() ; i++ ){
            temp = temp->next;
            temp->val = ans[i];
        }
        
        temp->next = NULL;
        
        return head;
    }
};