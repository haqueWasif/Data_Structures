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
    int sz;
    public:
        myStack(int size){
            sz = size;
        }
        void push(int val){
            Node* newNode = new Node(val);
            if(tail == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = tail->next;
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
        bool empty(){
            if(sz==0) return true;
            else return false;
        }
        int top(){
            return tail->val;
        }
};

int main(){
    int n;
    cin >> n;

    myStack s1(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    
    int m;
    cin >> m;

    myStack s2(m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        s2.push(x);
    }

    if(n != m) cout << "NO";
    else{
        myStack tempS1 = s1, tempS2 = s2;

        int flag=1;
        while(!tempS1.empty()){
            if(tempS1.top() == tempS2.top()){
                
                tempS1.pop();
                tempS2.pop();
            }
            else{
                flag = 0;
                break;
            }   
        }
        if(flag == 1) cout << "YES";
        else cout << "NO";
    }
    
    return 0;
}