#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack <int> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }    

    stack <int> newS;

    while(!s.empty()){
        newS.push(s.top());
        s.pop();
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << newS.top() << " ";
        newS.pop();
    } 

    return 0;
}