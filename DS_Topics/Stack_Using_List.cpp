#include<bits/stdc++.h>
using namespace std;

/*

Stack -> A data structure but not a fundamental one as the fundamental data structures are array, linked list. It is implemented using these fundamental data strucutures

-> Follows LIFO discipline (Last In First Out)

Defination: Stack is a data structure that follows LIFO discipline which means insertion and deletion happens at top

-> It is an ADT (Abstract Data Structure) or higher level data structure
-> Array, Linked List are also called lower level data structure or container

# Whenever we have something to do with last in first out then we use stack

-> Stack is not a new data structure it is just an abstract data structure whose implementation are done by array or linked list which are also called containers 

*/

class Stack{
    list <int> l;
    public:
        void push(int val){
            l.push_back(val);
        }
        bool empty(){
            if(l.empty()) return true;
            else return false;
        }
        void pop(){
            l.pop_back();
        }
        int top(){
            return l.back();
        }
        int size(){
            return l.size();
            // size is internally kept tracked by list so O(1)
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