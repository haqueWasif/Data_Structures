#include<bits/stdc++.h>
using namespace std;


/*

Array Versus Linked List
1. Insertion at tail: O(1) for both
2. Insertion at head: O(n) for array and O(1) for linked list

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

// Using reference is a must
void insertAtTail(Node* &head, int v){
    // O(N)
    Node* newNode = new Node(v);
    
    if(head == NULL) {
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void insertAtTail2(Node* &head, Node* &tail, int v){
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

void insertAtHead(Node* &head, int v){
    // O(1)
    Node* newNode = new Node(v);
    
    newNode -> next = head;
    head = newNode;
}

void insertAtPos(Node* &head, int index, int v){
    // O(N)
    Node* newNode = new Node(v);
        
    Node* temp = head;
    for (int i = 1; i <= index-1; i++)
    {
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
    
}

int size(Node* head){
    int n=0;
    while(head != NULL){
        n++;
        head = head -> next;
    }
    return n;   
}


void print_linked_list(Node *head){
    // O(N)
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    while(true){
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Insert at Head" << endl;
        cout << "Option 3: Insert at any Position" << endl;
        cout << "Option 4: Print Linked List" << endl;
        cout << "Option 5: Terminate" << endl;        
        
        int op;
        cin >> op;

        if(op == 1){
            int v;
            cin >> v;
            insertAtTail2(head, tail, v);
        }

        else if(op == 2){
            int v;
            cin >> v;
            insertAtHead(head, v);
        }

        else if(op == 3){
            int pos, v;
            cin >> pos >> v;

            if(pos == 1) insertAtHead(head, v);
            else if(pos-1 > size(head)){
                cout << "Invalid Position !" << endl;
            }
            else if(pos-1 == size(head)){
                insertAtTail2(head, tail, v);
            }
            else insertAtPos(head, pos-1, v);  
        }

        else if(op == 4){
            cout << "Your Linked List: ";
            print_linked_list(head);
        }
          
        else if(op == 5){
            break;
        }
    
    }
 
    return 0;
}