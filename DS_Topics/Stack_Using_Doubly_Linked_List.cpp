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

class Stack{
    Node* head=NULL;
    Node* tail=NULL;
    int sz=0;
    public:
        void push(int val){
            sz++;
            Node* newNode = new Node(val);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next=newNode;
            newNode->prev=tail;
            tail = tail->next;
        }
        bool empty(){
            if(sz == 0) return true;
            else return false;
        }
        void pop(){
            sz--;
            Node* delNode = tail;
            tail = tail -> prev;
            if(tail==NULL){
                head=NULL;
                return;
            }   
            tail -> next = NULL;
            delete delNode;
        }
        int top(){
            return tail->val;
        }
        int size(){
            return sz;
        }
};

int main(){
    Stack s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}