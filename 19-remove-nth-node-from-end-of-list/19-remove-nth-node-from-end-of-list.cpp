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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int x = 1;
        int length =1;
        
        while(cur->next){
            length++;
            cur=cur->next;
        }
        if(length == 1) return NULL;
        if(length == n) return head->next;
        cur = head;
        
        while(x < length - n){
            cur = cur->next;
            x++;
        }
        cur->next = cur->next->next;
        
        
        // while(x < )
        return head;
    }
};