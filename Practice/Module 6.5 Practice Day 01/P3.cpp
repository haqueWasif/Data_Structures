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

int getSize(Node* head){
    int size=0;
    while(head != NULL){
        head = head -> next;
        size++;
    }
    return size;
}

void printMiddle(Node* head){
    int n = getSize(head);

    for (int i = 1; i < ceil(n/2.0); i++)
    {      
        head = head -> next;
    }

    if(n%2 == 0){
        cout << head -> val << " " << head->next->val << endl;
    }
    else{
        cout << head -> val << endl;
    }
}

int main(){
    Node* head = NULL;

    cout << "Enter values: ";
    while(true){
        int v;
        cin >> v;
        if(v == -1) break;
        insertAtTail(head, v);
    }

    printMiddle(head);

    return 0;
}