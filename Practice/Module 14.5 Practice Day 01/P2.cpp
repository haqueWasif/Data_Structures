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

    int m;
    cin >> m;

    queue <int> q;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    } 

    stack <int> tempS = s;
    queue <int> tempQ = q;

    if(n != m) cout << "NO";
    else{
        int isSame=1;
        while(!tempS.empty()){
            if(tempS.top() != tempQ.front()){
                isSame=0;
                break;
            }
            tempS.pop();
            tempQ.pop();
        }
        if(isSame) cout << "YES";
        else cout << "NO";
    }
    return 0;
}