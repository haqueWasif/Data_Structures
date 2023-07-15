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

class myStack{
    Node* head = NULL;
    Node* tail = NULL;
    int sz=0;
    public:
        bool empty(){
            if(head == NULL) return true;
            else return false;
        }
        void push(int v){
            sz++;
            Node* newNode = new Node(v);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        void pop(){
            sz--;
            Node* delNode = tail;

            tail = tail -> prev;
            if(tail == NULL){
                head = NULL;
                delete delNode;
                return;
            }
            tail -> next = NULL;

            delete delNode;
        }
        int size(){
            return sz;
        }
        int top(){
            return tail->val;
        }

};


class myQueue{
    Node* head = NULL;
    Node* tail = NULL;
    int sz=0;
    public:
        bool empty(){
            if(head == NULL) return true;
            else return false;
        }
        void push(int v){
            sz++;
            Node* newNode = new Node(v);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        void pop(){
            sz--;
            Node* delNode = head;

            head = head -> next;
            if(head == NULL){
                tail = NULL;
                delete delNode;
                return;
            }
            head -> prev = NULL;
            
            delete delNode;
        }
        int size(){
            return sz;
        }
        int front(){
            return head->val;
        }
};

int main(){
    int n, m;
    cin >> n >> m;

    myStack s;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        s.push(v);
    }
    
    myQueue q;
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v;
        q.push(v);
    }
    
    int isSame=1;

    if(n != m) isSame=0;
    else{
        while(!s.empty()){
            if(s.top() == q.front()){
                s.pop();
                q.pop();
            }
            else{
                isSame=0;
                break;
            }
        }
    }

    if(isSame) cout << "YES";
    else cout << "NO";
    
    return 0;
}