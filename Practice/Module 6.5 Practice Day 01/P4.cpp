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

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);

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

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode -> next = head;
    head = newNode;
    printLinkedList(head);
}

void insertAtPos(Node* &head, int index, int val){
    Node* newNode = new Node(val);

    if(index == 0){
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < index; i++)
    {
        if(temp == NULL){
            cout << "Invalid" << endl;
            return;
        }
        temp = temp -> next;
    }

    if(temp == NULL){
        cout << "Invalid" << endl;
        return;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
    printLinkedList(head);

}

int main(){
    Node* head = NULL;
    while(true){
        int v;
        cin >> v;
        if(v == -1) break;
        insertAtTail(head, v);
    }

    int q;
    cin >> q;
    while(q--){
        int i, v;
        cin >> i >> v;
        if(v == -1) break;
        insertAtPos(head, i, v);
    }

    return 0;
}