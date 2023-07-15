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

void insertAtTail(Node* &head, int v){
    Node* newNode = new Node(v);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
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

    while (true)
    {   
        int val;
        cin >> val;
        if(val == -1) break;
        insertAtTail(head, val);
    }
    printLinkedList(head);

    return 0;
}