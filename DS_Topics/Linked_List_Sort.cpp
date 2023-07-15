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

void sortLinkedList(Node* head){
    // O(N^2)
    for (Node* i = head; i -> next != NULL; i=i->next)
    {
        for (Node* j = i->next; j != NULL; j=j->next)
        {
            if(i->val > j->val){
                swap(i->val, j->val);
            }
        }
    }
}

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
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
    printLinkedList(head);

    return 0;
}