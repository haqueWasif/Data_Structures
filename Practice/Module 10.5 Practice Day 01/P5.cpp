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

    l.sort();

    for (int val : l) cout << val << " ";
    
    return 0;
}