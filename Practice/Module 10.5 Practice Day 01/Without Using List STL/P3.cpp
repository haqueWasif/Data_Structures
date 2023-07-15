#include<bits/stdc++.h>
using namespace std;

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

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = newNode;
        tail = newNode;        
        return;
    }

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode; 
}

int size(Node* head){
    int n=0;
    while(head!=NULL){
        n++;
        head = head -> next;
    }
    return n;
}

int checkPalindrome(Node* head, Node* tail){
    while(head != tail){
        if(head -> val != tail -> val) return 0;
        
        if(head -> next == tail){
            return 1;
        }
        head = head -> next;
        tail = tail -> prev;
    }
    return 1;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        insertAtTail(head, tail, v);
    }

    int isPalindrome =  checkPalindrome(head, tail);
    if(isPalindrome) cout << "YES";
    else cout << "NO";
    
    
    return 0;
}