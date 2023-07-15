#include<bits/stdc++.h>
using namespace std;

/*

Disadvantages in Array:

1. Memory is available but not sequencially so it cannot allocate

For example,

int x = 10; -> 4 byte
int a[20]; -> 80 byte

if we have 100 byte in memory which starts from 200 byte and ends at 300 byte.

if the variable x takes memory at 250 byte then while declaring the array 80 byte will take 200 to 280 but 250 is not available so it fails similarly if it starts from 250 then 80 bytes will end at 330 byte but we have memory from 200 to 300 byte so this fails as well

Therefore, array will fail to allocate memory even if we have 96 bytes available

2. Size of a static array is fixed whereas linked list doesn't have a fixed size when a new memory is allocated it is linked with the previous

Why Linked list ?
-> Because of disadvantages in array

Singly Linked List
-> A variable is linked with another variable in one way

*/


class Node{
    public:
        int val;
        Node* next;

};

int main(){
    Node a, b;

    a.val = 10;
    b.val = 20;
    
    a.next = &b;
    b.next = NULL;

    cout << a.val << endl;
    cout << b.val << endl;
    //cout << a.next -> val << endl;

    return 0;
}