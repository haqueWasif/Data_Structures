#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> next = NULL;
        }

};

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail -> next = newNode;
    tail = newNode;

}

void printReverse(Node* head){
    if(head == NULL) return;

    printReverse(head->next);
    cout << head -> val << " " ;
}

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head-> val << " ";
        head = head -> next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail(head, tail, v);
    }

    printReverse(head);
    cout << endl;
    printLinkedList(head);
    
    return 0;
}