#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    queue <int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }    

    stack <int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    queue <int> newQ;
    while(!s.empty()){
        newQ.push(s.top());
        s.pop();
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << newQ.front() << " ";
        newQ.pop();
    } 

    return 0;
}