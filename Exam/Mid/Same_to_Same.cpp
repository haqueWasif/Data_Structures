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

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail -> next = newNode;
    tail = newNode;

}

int size(Node* head){
    int n=0;
    while(head!=NULL){
        n+=1;
        head = head -> next;
    }
    return n;
}

int checkSame(Node* head1, Node* head2){
    int n1 = size(head1), n2 = size(head2);
    if(n1 != n2) return 0;

    while(head1 != NULL){
        if(head1 -> val != head2 -> val){
            return 0;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    return 1;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail(head1, tail1, v);
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail(head2, tail2, v);
    }

    int isSame = checkSame(head1, head2);

    if(isSame == 1) cout << "YES";
    else cout << "NO";
    
    return 0;
}