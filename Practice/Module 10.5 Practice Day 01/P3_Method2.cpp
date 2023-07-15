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

    int isPalindrome=1;
    while(l.size() > 1){
        if(l.front() == l.back()){
            l.pop_front();
            l.pop_back();
        }
        else{
            isPalindrome=0;
            break;
        }
    }
    
    if(isPalindrome) cout << "YES";
    else cout << "NO";


    return 0;
}