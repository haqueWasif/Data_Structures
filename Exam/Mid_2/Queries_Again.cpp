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

void insertAtIndex(Node* &head, int index, int val){
    Node* newNode = new Node(val);
    
    Node* temp = head;
    for (int i = 1; i <= index-1; i++)
    {
        temp = temp -> next;
    }
    
    Node* nextNode = temp -> next;
    newNode -> prev = temp;
    newNode -> next = nextNode;
    temp -> next = newNode;
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

void printNormal(Node* head){
    cout << "L -> ";
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

void printReverse(Node* tail){
    cout << "R -> ";
    while(tail != NULL){
        cout << tail -> val << " ";
        tail = tail -> prev;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int q;
    cin >> q;
    while(q--){
        int x, v;
        cin >> x >> v;

        if(x == 0) insertAtHead(head, tail, v);
        else if(x == size(head)) insertAtTail(head, tail, v);
        else if(x > size(head)){
            cout << "Invalid" << endl;
            continue;
        }
        else insertAtIndex(head, x, v);
        printNormal(head);
        printReverse(tail);
    }

    return 0;
}