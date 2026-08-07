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
 ListNode* solve(ListNode* list1, ListNode* list2){
    ListNode*curr1=list1;
    ListNode*forward=list1->next;
    ListNode*curr2=list2;
    ListNode*forward2=curr2->next;
    if(list1->next==NULL){
        list1->next=list2;
        return list1;
    }
    while(forward!=NULL && curr2!=NULL){
        if((curr1->val<=curr2->val) && (curr2->val<=forward->val)){
            curr1->next=curr2;
            forward2=curr2->next;
            curr2->next=forward;
            curr1=curr2;
            curr2=forward2;
        }
        else{
            curr1=forward;
            forward=forward->next;
            if(forward==NULL){
                curr1->next=curr2;
                return list1;
            }
        }
    }
    return list1;
 }
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
          return   solve(list1,list2);
        }
        else{
         return   solve(list2,list1);
        }
        
    }
};