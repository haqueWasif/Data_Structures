#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> next = next;
        }

};

int main(){
    Node a(10);
    Node b(20);

    a.next = &b;

    return 0;
}