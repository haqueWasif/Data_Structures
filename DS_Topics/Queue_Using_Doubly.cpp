#include<bits/stdc++.h>
using namespace std;

/*

Queue:
-> Operations are performed in FIFO order (first in first out)
-> Insertion and Deletion occurs at different ends
-> Insertion at end and Deletion at beginning
(Ex: Ticket Counter)

// Note: Not only limited to concept of counters

Implementation:
-> Can be implemented in various ways
-> Using arrays or linked list or other ADTs (like: Stack)

Arrays -> Insertion O(1) and Deletion O(n)
Singly -> Insertion O(1) and Deletion O(1)
Doubly -> Insertion O(1) and Deletion O(1)

Queue ADT:
Data:
-> Storage
-> Insertion End pointer
-> Deletion End pointer

Methods:
-> enqueue (insertion)
-> dequeue (deletion)
-> firstVal
-> lastVal
-> peek(pos)
-> isEmpty
-> isFull

enqueue:
-> insert element at back(index n) which is maintained by the back/rear pointer( not necessarily a pointer it can also store index)
-> Complexity O(1)

dequeue:
-> remove element at front+1(index 0)
-> shift all elements which results in Complexity O(n) so we have to maintain front pointer( not necessarily a pointer it can also store index ) so that this operation can be done with Complexity O(1)

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

class myQueue{
    Node* head = NULL;
    Node* tail = NULL;
    int sz=0;
    public:
        void push(int v){
            sz++;
            Node* newNode = new Node(v);
            if(tail == NULL){
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
            if(head == NULL) {
                tail = NULL;
                delete delNode;
                return;

            }
            head -> prev = NULL;
            delete delNode;
        }
        bool empty(){
            if(sz==0) return true;
            return false;
        }
        int front(){
            return head->val;
        }
        int size(){
            return sz;
        }

};

int main(){
    myQueue q;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        q.push(v);
    }

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    
    return 0;
}