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

int size(Node* head){
    int n=0;
    while(head!=NULL){
        n+=1;
        head = head -> next;
    }
    return n;
}

void sortLinkedList(Node* head){
    for (Node* i=head; i -> next != NULL; i=i->next)
    {
        for (Node* j=i->next; j != NULL; j=j->next)
        {
            if(i->val < j->val){
                swap(i->val, j->val);
            }
        }
    }
}

void printMiddle(Node* head){
    int n = size(head);
    for (int i = 1; i < ceil(n/2.0); i++)
    {
        head = head->next;
    }

    if(n%2==0){
        cout << head->val << " " << head->next->val;
    }
    else{
        cout << head->val;
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
    
    sortLinkedList(head);
    printMiddle(head);
    
    return 0;
}