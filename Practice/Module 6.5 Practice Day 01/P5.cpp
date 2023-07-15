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

void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

int isSorted(Node* head){
    Node* i = head;
    Node* j = head -> next;

    while(i -> next != NULL){
        while(j != NULL){
            if(i->val > j->val){
                return 0;
            }
            j = j->next;
        }
        i = i->next;
        j = i->next;
    }

    return 1;
}

void isSorted2(Node* head){
    while(head -> next != NULL){
        if(head->val > head->next->val){
            cout << "NO" << endl;
            return;
        }
        head = head -> next;
    }
    cout << "YES" << endl;
}

void sortLinkedList(Node* head){
    Node* i = head;
    Node* j = head -> next;

    while(i -> next != NULL){
        while(j != NULL){
            if(i->val > j->val){
                swap(i->val, j->val);
            }
            j = j->next;
        }
        i = i->next;
        j = i->next;
    }

    printLinkedList(head);
}

int main(){
    Node* head = NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail(head, v);
    }

    // int checkSorted = isSorted(head);
    // if(checkSorted != 0) cout << "YES" << endl;
    // else cout << "NO" << endl;

    isSorted2(head);
    sortLinkedList(head);

    return 0;
}