#include<bits/stdc++.h>
using namespace std;

int main(){
    list <string> l;

    string s;
    getline(cin, s);

    stringstream ss(s);

    string word;
    while(ss >> word){
        l.push_back(word);
    }

    int q;
    cin >> q;
    cin.ignore();

    int i=0;
    while(q--){
        string command;
        cin >> command;

        if(command == "visit"){
            string website;
            cin >> website;
            int temp = i;
            i = 0;
            for(string val : l){
                if(website == val){
                    cout << val << endl;
                    break;
                }
                else if(val == "end"){
                    cout << "Not Available" << endl;
                    i = temp;
                    break;
                }
                i++;
            }
        }
        else if(command == "prev"){
            if(i > 0){
                i--;
                string prev = *next(l.begin(), i);
                cout << prev << endl;
            }
            else{
                 cout << "Not Available" << endl;
            }
        }
        else if(command == "next"){
            if(i < l.size() - 2){
                i++;
                string nxt = *next(l.begin(), i);
                cout << nxt << endl;
            }
            else{
                 cout << "Not Available" << endl;
            }
        }
    }
    

    return 0;
}