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

void insertAtTail(Node* &head, Node* &tail, int val){ //O(1)
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
}

void reverseList(Node* head, Node* tail){
    Node* i = head;
    Node* j = tail;
    while(i!=j){
        swap(i->val, j->val);
        if(i->next == j) i = j;
        else{
            i = i->next;
            j = j->prev;
        }
    }    
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

    reverseList(head, tail);
    printList(head);

    return 0;
}