#include<bits/stdc++.h>
using namespace std;

/*

// Difference between Singly and Doubly linked list
-> Doubly is always better


// Array vs Singly vs Doubly
-> Insert head [ O(N),  O(1),  O(1) ] 
-> Insert tail [ O(1),  O(1),  O(1) ] 
-> Insert pos [ O(N),  O(N),  O(N) ]

-> Delete head [ O(N),  O(1),  O(1) ] 
-> Delete tail [ O(1),  O(N),  O(1) ] 
-> Delete pos [ O(N),  O(N),  O(N) ] 

Order of complexity for singly, doubly and array
-> Doubly
-> Array
-> Singly


// As head can be deleted in singly with 
O(1) but in array it is O(N) and tail can be deleted in array with O(1) but in singly it is O(N)
// So we normally use doubly when we have to delete head and tail. 

*/

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> prev = NULL;
            this -> next = NULL;
        }

};

void insertAtHead(Node* &head, Node* &tail, int val){ //O(1)
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;

}

void insertAtTail(Node* &head, Node* &tail, int val){ //O(1)
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertAtPos(Node* &head, int index, int val){ //O(N)
    Node* newNode = new Node(val);
    
    Node* prevNode = head;

    for (int i = 1; i <= index-1; i++)
    {
        prevNode = prevNode -> next;
    }

    Node* nextNode = prevNode -> next;

    newNode -> next = nextNode;
    newNode -> prev = prevNode;
    prevNode -> next = newNode;
    nextNode -> prev = newNode;

}

void deleteAtHead(Node* &head, Node* &tail){
    Node* prevNode = head;
    head = head -> next;
    delete prevNode;
    if(head != NULL){
        head -> prev = NULL;
    }
    else{
        tail = NULL;
    }
}


void deleteAtTail(Node* &head, Node* &tail){
    Node* delNode = tail;
    tail = tail -> prev;
    delete delNode;
    if(tail != NULL){
        tail -> next = NULL;
    }
    else{
        head = NULL;
    }
}

void deleteAtPos(Node* head, int index){
    Node* prevNode = head;

    for (int i = 1; i <= index-1; i++)
    {
        prevNode = prevNode -> next;
    }
    
    Node* delNode = prevNode -> next;
    Node* nextNode = delNode -> next;

    prevNode -> next = nextNode;
    nextNode -> prev = prevNode;

    delete delNode;

}

int size(Node* head){ //O(N)
    int n=0;
    while(head != NULL){
        n++;
        head = head -> next;
    }
    return n;
}

void printNormal(Node* head){ //O(N)
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
}

void printReverse(Node* tail){ //O(N)
    while(tail != NULL){
        cout << tail -> val << " ";
        tail = tail -> prev;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    while(true){
        cout << "Choose Option: " << endl;
        cout << "1. Insert At Head" << endl;
        cout << "2. Insert At Tail" << endl;
        cout << "3. Insert At Position" << endl;
        cout << "4. Print Normal " << endl;
        cout << "5. Print Reverse " << endl;
        cout << "6. Delete At Head " << endl;
        cout << "7. Delete At Tail " << endl;
        cout << "8. Delete At Position " << endl;
        cout << "9. Stop" << endl;
        int op;
        cin >> op;
        if(op == 1){
            int v;
            cin >> v;
            insertAtHead(head, tail, v);
        }
        else if(op == 2){
            int v;
            cin >> v;
            insertAtTail(head, tail, v);
        }
        else if(op == 3){
            int pos, v;
            cout << "Enter Position: ";
            cin >> pos >> v;
            if(pos == 1){
                insertAtHead(head, tail, v);
            }
            else if(pos-1 == size(head)){
                insertAtTail(head, tail, v);
            }
            else if(pos > size(head)){
                cout << "Invalid Position !" << endl;
            }
            else{
                insertAtPos(head, pos-1, v);
            }
        }
        else if(op == 4){
            cout << "Your Linked List: ";
            printNormal(head);
            cout << endl;
        }
        else if(op == 5){
            cout << "Your Linked List: ";
            printReverse(tail);
            cout << endl;
        }
        else if(op == 6){
            if(head == NULL){
                cout << "Already Empty !" << endl;
            }
            else{
                deleteAtHead(head, tail);
            }   
        }
        else if(op == 7){
            if(tail == NULL){
                cout << "Already Empty !" << endl;
            }
            else{
                deleteAtTail(head, tail);
            }
        }
        else if(op == 8){
            int pos;
            cout << "Enter Position: ";
            cin >> pos;
            if(pos == 1){
                if(head == NULL){
                    cout << "Already Empty !" << endl;
                }
                else{
                    deleteAtHead(head, tail);
                }       
            }
            else if(pos == size(head)){
                if(tail == NULL){
                    cout << "Already Empty !" << endl;
                }
                else{
                    deleteAtTail(head, tail);
                }
                
            }
            else if(pos > size(head)){
                cout << "Invalid Position !" << endl;
            }
            else{
                deleteAtPos(head, pos-1);
            }
        }
        else if(op == 9){
            cout << "Operations Ended Successfully !" << endl;
            break;
        }      
    }

    return 0;
}