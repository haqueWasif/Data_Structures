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

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

int checkDublicate(Node* head){
    Node* i = head;
    Node* j = head->next;

    while(i -> next != NULL){
        while(j != NULL){
            if(i->val == j->val){
                return 1;
            }
            j = j -> next;
        }
        i = i->next;
        j = i->next;
    }

    return 0;
}

void checkDublicate2(Node* head){
    int freq[100] = {0};
    while(head != NULL){
        freq[head->val]++;
        head = head -> next;
    }
    
    for (int i = 0; i < 100; i++)
    {
        if(freq[i] > 1){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
    
}
int main(){
    Node* head = NULL;
    
    while(true){
        int v;
        cin >> v;
        if(v == -1) break;
        insertAtTail(head, v);
    }

    // int isdublicate = checkDublicate(head);

    // if(isdublicate == 1) cout << "YES";
    // else cout << "NO";

    checkDublicate2(head);

    return 0;
}