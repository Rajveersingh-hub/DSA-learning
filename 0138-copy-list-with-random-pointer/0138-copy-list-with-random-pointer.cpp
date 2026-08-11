/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
     void insertAtTail(Node* &head,Node* &tail,int val){
        Node*temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
     }
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node*temp=head;
       unordered_map<Node*,Node*>mpp;
        // clone a list simply next ptr
        while(temp!=NULL){
            int val=temp->val;
           insertAtTail(clonehead,clonetail,val);
           temp=temp->next;
        }
        Node*original=head;
        Node*clone=clonehead;
        while(original!=NULL && clone!=NULL){
            mpp[original]=clone;
            original=original->next;
            clone=clone->next;
        }
        original=head;
        clone=clonehead;
        while(original!=NULL){
           clone->random=mpp[original->random];
           original=original->next;
           clone=clone->next;
        }
        return clonehead;
    }
};