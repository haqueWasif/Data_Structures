#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> prev = NULL;
            this -> next = NULL;
        }

};

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = newNode;
        tail = newNode;        
        return;
    }

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode; 
}

void sortList(Node* head){
        for(Node* i=head; i -> next != NULL; i=i->next){
            for(Node* j=i->next; j != NULL; j=j->next){
                if(i->val > j->val){
                    swap(i->val, j->val);
                }
            }
        }
}

void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail(head, tail, v);
    }

    sortList(head);
    printList(head);

    
    
    return 0;
}