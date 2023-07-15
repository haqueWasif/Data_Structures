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
    Node* newNode = new Node(v);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
} 

void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
}


void reverse(Node* &head, Node* curr){
    if(curr -> next == NULL){
        head = curr;
        return;
    }

    reverse(head, curr->next);
    curr -> next -> next = curr;
    curr -> next = NULL;
}

int checkPalindrome(Node* head){
    Node* copyhead = NULL;
    Node* copytail = NULL;
    
    Node* temp = head;
    while(temp != NULL){
        insertAtTail(copyhead, copytail, temp->val);
        temp = temp -> next;
    }

    reverse(copyhead, copyhead);

    Node* copytemp = copyhead;
    temp = head;
    while(temp != NULL){
        if(temp -> val != copytemp -> val) return 0;
        temp = temp -> next;
        copytemp = copytemp -> next;
    }

    return 1;
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

    int isPalindrome = checkPalindrome(head);
    if(isPalindrome) cout << "YES";
    else cout << "NO";
    
    return 0;
}