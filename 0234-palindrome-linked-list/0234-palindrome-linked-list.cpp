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
    private:
    ListNode* middle(ListNode* head){
       ListNode*slow=head;
       ListNode*fast=head->next;
       while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
        
       }
       return slow;
    }
    ListNode* reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        //Aproch-1 TC-O(N) SC-O(N)
        // vector<int>data;
        // ListNode*temp=head;
        // while(temp!=NULL){
        //     data.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int st=0;
        // int end=data.size()-1;
        // while(st<=end){
        //     if(data[st]==data[end]){
        //         st++;
        //         end--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;

      //Aproch-2 TC-O(N) SC-O(N)
      if(head->next==NULL){
        return true;
      }
    //step-1 get middle
    ListNode*middlenode=middle(head);
    //step-2 revrse the ll after middle
    ListNode*temp=middlenode->next;
    middlenode->next=reverse(temp);
    // step-3 compare both data reverse and middle
    ListNode*head1=head;
    ListNode*head2=middlenode->next;
    while(head2!=NULL){
        if(head1->val!=head2->val){
            return false;
        }
        else{
            head1=head1->next;
            head2=head2->next;
        }
    }
     temp=middlenode->next;
    middlenode->next=reverse(temp);

    return true;

    }
};