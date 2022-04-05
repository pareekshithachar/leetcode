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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        int size = 0;
        while(temp){
            st.push(temp);
            temp = temp ->next;
            size++;
        }
        temp = head;
        for(int i = 0 ; i< size/2;i++){
            if(i == size/2 - 1 && size%2 ==0){
                temp = temp->next;
                break;
            }
            ListNode* toInsert = st.top();
            st.pop();
            toInsert->next = temp->next;
            temp->next = toInsert;
            temp= temp->next->next;
            
        }
        temp->next = NULL;
    }
};