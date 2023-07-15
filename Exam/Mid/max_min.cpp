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

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
}

int findMax(Node* head){
    int mx = head->val;
    for (Node* i = head; i -> next != NULL; i=i->next)
    {
        if(mx < i->next->val){
            mx = i->next->val;
        }
    }
    return mx;
    
}

int findMin(Node* head){
    int mn = head->val;
    for (Node* i = head; i -> next != NULL; i=i->next)
    {
        if(mn > i->next->val){
            mn = i->next->val;
        }
    }
    return mn;
    
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

    int mx = findMax(head), mn = findMin(head);
    cout << mx << " " << mn;
    
    return 0;
}