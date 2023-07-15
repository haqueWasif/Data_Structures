#include<bits/stdc++.h>
using namespace std;

/*

Major problems with static linked list:

-> If we declare a node in a function and we linked the node with other nodes and we do not return the node from the function then when the function returns the node is deleted from the memory

-> Another problem is it takes up extra space as it will not be deleted until the function return but using dynamic object we can delete it any time.

-> So 100% time we work with dynamic object

*/

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
    // Node head(10);
    Node* head = new Node(10);
    Node* a = new Node(20);

    head -> next = a;
    a -> next = NULL;

    cout << head -> val << endl;
    cout << a -> val << endl;
    cout << head -> next -> val << endl;
    
    return 0;
}