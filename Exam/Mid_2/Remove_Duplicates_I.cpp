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

void sortList(Node* &head){
    for(Node* i = head; i -> next != NULL; i=i->next){
        for(Node* j = i->next; j != NULL; j=j->next){
            if(i->val > j->val){
                swap(i->val, j->val);
            }
        }
    }
}

void removeDuplicates(Node* &head){
    Node* i = head;
    while(i!=NULL && i->next!=NULL){
        if(i->val == i->next->val){
            Node* delNode = i->next;
            Node* nextNode = delNode->next;
            i -> next = nextNode;
            delete delNode;
        }
        else{
            i = i -> next;
        }
    }

}

void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
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

    sortList(head);
    removeDuplicates(head);
    printList(head);
    
    return 0;
}