//https://practice.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        if(!prev) return head;
        prev->next = NULL;
        curr->next = head;
        head = curr;
        return head;
    }
};