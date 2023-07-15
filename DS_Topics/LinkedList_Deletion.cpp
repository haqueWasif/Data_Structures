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
    Node* newNode = new Node(v);

    newNode -> next = head;
    head = newNode;
}

void insertAtPos(Node* &head, int index, int v){
    Node* newNode = new Node(v);

    Node* temp = head;
    for (int i = 0; i < index-1; i++)
    {
        if(temp == NULL) {
            cout << "Invalid Position !" << endl;
            return;
        }
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void insertAtPos2(Node* &head, int index, int v){
    Node* newNode = new Node(v);

    Node* temp = head;
    for (int i = 0; i < index-1; i++)
    {
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void deleteAtTail(Node* &head){
    Node* temp = head;

    Node* delNode = temp -> next;
    while(delNode -> next != NULL){
        temp = temp -> next;
        delNode = delNode -> next;
    }
    
    temp -> next = NULL;
    delete delNode;
}

void deleteAtHead(Node* &head){
    Node* delNode = head;

    if(head == NULL){ 
        cout << "Empty Linked List !" << endl;
        return;
    }
    head = head -> next;

    delete delNode;
}

void deleteAtPos(Node* &head, int index){
    Node* temp = head;
    
    for (int i = 1; i <= index-1; i++)
    {   
        if(temp == NULL) {
            cout << "Invalid Position !" << endl;
            return;
        }
        temp = temp -> next;
    }

    if(temp == NULL){
        cout << "Invalid Position !" << endl;
        return;
    }

    else if(temp -> next == NULL){
        cout << "Invalid Position !" << endl;
        return;
    }

    Node* delNode = temp -> next;
    temp -> next = delNode -> next;

    delete delNode;

}

void deleteAtPos2(Node* &head, int index){
    Node* temp = head;
    
    for (int i = 1; i <= index-1; i++)
    {   
        temp = temp -> next;
    }

    Node* delNode = temp -> next;
    temp -> next = delNode -> next;

    delete delNode;

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
    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        cout << "Option 1: Insert at Tail" << endl;
        cout << "Option 2: Insert at Head" << endl;
        cout << "Option 3: Insert at any Position" << endl << endl;
        cout << "Option 4: Delete at Tail" << endl;
        cout << "Option 5: Delete at Head" << endl;
        cout << "Option 6: Delete at any Position" << endl << endl;
        cout << "Option 7: Print Linked List" << endl;
        cout << "Option 8: Terminate" << endl << endl;        
        
        int op;
        cin >> op;

        if(op == 1){
            int v;
            cin >> v;
            // Insertion at tail using this function will give final complexity O(N^2)
            // insertAtTail(head, v);

            insertAtTail2(head, tail, v);
            // Insertion at tail using this function will give final complexity O(N)
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
            deleteAtTail(head);
        }

        else if(op == 5){
            deleteAtHead(head);
        }

        else if(op == 6){
            int pos;
            cin >> pos;
            if(pos == 1) deleteAtHead(head);
            else if(pos-1 >= size(head)){
                cout << "Invalid Position !" << endl;
            }
            else deleteAtPos(head, pos-1); 
        }

        else if(op == 7){
            cout << "Your Linked List: ";
            printLinkedList(head);
        }
          
        else if(op == 8){
            break;
        }
    
    }
    return 0;
}