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
    bool isPalindrome(ListNode* head) {
        vector<int>data;
        ListNode*temp=head;
        while(temp!=NULL){
            data.push_back(temp->val);
            temp=temp->next;
        }
        int st=0;
        int end=data.size()-1;
        while(st<=end){
            if(data[st]==data[end]){
                st++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};