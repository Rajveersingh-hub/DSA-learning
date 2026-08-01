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
    ListNode* middleNode(ListNode* head) {
        // Brute force using length concept TC-O(N) SC-O(1)
    //    ListNode*temp=head;
    //    int len=0;
    //    while(head!=NULL){
    //     head=head->next;
    //     len++;
    //    }
    //    int ans=(len/2);
    //    int cnt=0;
    //    while(cnt<ans){
    //     temp=temp->next;
    //     cnt++;
    //    }
    //    return temp;
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
    }
    return slow;


     
    } 
};