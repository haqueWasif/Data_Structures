#include<bits/stdc++.h>
using namespace std;

int main(){
    list <int> l;
    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        l.push_back(v);
    }

    list <int> l1(l);
    l.reverse();

    if(l1 == l) cout << "YES";
    else cout << "NO";


    return 0;
}