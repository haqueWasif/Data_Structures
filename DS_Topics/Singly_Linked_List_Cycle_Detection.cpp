#include<bits/stdc++.h>
using namespace std;


/*

Array Versus Linked List
1. Insertion at tail: O(1) for both
2. Insertion at head: O(n) for array and O(1) for linked list
3. Deletion at tail: O(1) for array and O(n) for linked list
4. Deletion at head: O(n) for array and O(1) for linked list
5. Deletion at position: O(n) for both

*/

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
    
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
}



int size(Node* head){
    int n=0;
    while(head != NULL){
        n++;
        head = head -> next;
    }
    return n;   
}

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);

    head -> next = a;
    a -> next = b;
    b -> next = c;
    c -> next = b;

    bool flag = false;

    Node* slow = head;
    Node* fast = head;

    // In case of and if the left condition is false then the right one is not evaluated
    while(fast != NULL && fast -> next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            flag = true;
            break;
        }
    }

    if(flag == true) cout << "Cycle Detected" << endl;
    else cout << "No Cycle Detected" << endl;

    // Complexity of Cycle -> O(N)
    
    return 0;
}