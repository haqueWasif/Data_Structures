#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;

    queue <string> ticketQ;
    while(q--){
        int command;
        cin >> command;
        if(command == 0){
            string name;
            cin >> name;
            ticketQ.push(name);
        }
        else{
            if(ticketQ.empty()){
                cout << "Invalid" << endl;
            }
            else {
                cout << ticketQ.front() << endl;
                ticketQ.pop();
            }
        }
    }
    
    
    return 0;
}