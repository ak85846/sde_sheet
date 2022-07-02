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
public:
    Node* copyRandomList(Node* head) {
        Node* iter=head;
        Node* front=head;
        while(iter!=NULL){
            front=iter->next;
            Node* temp=new Node(iter->val);
          iter->next=temp;
            temp->next=front;
            iter=front;     
        }
        iter=head;
        while(iter!=NULL){
            if(iter->random!=NULL){
            iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        iter=head;
        front=head;
        Node* dummyhead=new Node(0);
        Node* copy=dummyhead;
        while(iter!=NULL){
            front=iter->next->next;
            copy->next=iter->next;
            copy=copy->next;
            iter->next=front;
            iter=iter->next;
            
            
        }
        return dummyhead->next;
    }
};