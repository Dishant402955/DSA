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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* prev,*curr,*nxt;
        prev=head,curr=head->next;

        if(curr == nullptr)
            return {-1,-1};

        nxt = curr->next;

        vector<int> v;
        int i=1;

        while(nxt!=NULL)
        {
            if((curr->val>prev->val && curr->val>nxt->val) ||
               (curr->val<prev->val && curr->val<nxt->val))
            {
                v.push_back(i);
            }

            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }

        if(v.size()<2)
            return {-1,-1};

        int mind=INT_MAX;

        for(i=1;i<v.size();i++)
        {
            mind=min(mind,v[i]-v[i-1]);
        }

        return {mind,v.back()-v.front()};
    }
};                    // Calculate the minimum distance between critical points
                    minDistance =
                        min(minDistance, currentIndex - previousCriticalIndex);
                    previousCriticalIndex = currentIndex;
                }
            }

            // Move to the next node and update indices
            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        // If at least two critical points were found
        if (minDistance != INT_MAX) {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }

        return result;
    }
};
