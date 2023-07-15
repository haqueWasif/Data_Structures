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

void insertAtTail(Node* &head, Node* &tail, int v){
    // O(1)
    Node* newNode = new Node(v);
    
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
}

// int size(Node* head){
//     int n=0;
//     while(head != NULL){
//         n++;
//         head = head -> next;
//     }
//     return n;   
// }


// void reverseLinkedList(Node* head){
//     Node* tail = head;
    
//     int count=size(head)-1;
//     while(count >= 1){
        
//         for (int i = 1; i <= count; i++)
//         {
//             tail = tail -> next;
//         }
//         swap(head->val, tail->val);
//         head = head->next;
//         tail = head;
//         count-=2;
//     }
// }

void reverseLinkedList(Node* &head, Node* cur){
    if(cur -> next == NULL){
        head = cur;
        return;
    }

    reverseLinkedList(head, cur->next);
    cur -> next -> next = cur;
    cur -> next = NULL;
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

    reverseLinkedList(head, head);
    printLinkedList(head);


    return 0;
}