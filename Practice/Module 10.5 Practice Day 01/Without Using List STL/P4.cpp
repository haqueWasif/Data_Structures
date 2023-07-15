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

void insertAtHead(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;        
        return;
    }

    newNode -> next = head;
    head -> prev = newNode;
    head = newNode; 
}

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

void insertAtPos(Node* &head, Node* &tail, int index, int val){
    Node* newNode = new Node(val);

    Node* prevNode = head;
    for (int i = 1; i <= index-1; i++)
    {
        prevNode = prevNode -> next;
    }

    Node* nextNode = prevNode -> next;
    newNode -> prev = prevNode;
    newNode -> next = nextNode;
    prevNode -> next = newNode;
    nextNode -> prev = newNode;
    
}

int size(Node* head){
    int n=0;
    while(head!=NULL){
        n++;
        head = head -> next;
    }
    return n;
}

void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

void printReverse(Node* tail){
    while(tail != NULL){
        cout << tail -> val << " ";
        tail = tail -> prev;
    }
    cout << endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    int q;
    cin >> q;
    while(q--){
        int x, v;
        cin >> x >> v;

        if(x == 0){
            insertAtHead(head, tail, v);
        }
        else if(x == size(head)){
            insertAtTail(head, tail, v);
        }
        else if(x > size(head)){
            cout << "Invalid" << endl;
            continue;
        }
        else{
            insertAtPos(head, tail, x, v);
        }

        printList(head);
        printReverse(tail);
    }

    
    
    return 0;
}