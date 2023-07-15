#include<bits/stdc++.h>
using namespace std;

int main(){
    list <int> l1;
    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        l1.push_back(v);
    }
    
    list <int> l2;
    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        l2.push_back(v);
    }

    if(l1 == l2) cout << "YES";
    else cout << "NO";


    return 0;
}