#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    stack <int> s;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        s.push(v);
    }
    
    queue <int> q;
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v;
        q.push(v);
    }  
    
    int isSame=1;

    if(n != m) isSame=0;
    else{
        while(!s.empty()){
            if(s.top() == q.front()){
                s.pop();
                q.pop();
            }
            else{
                isSame=0;
                break;
            }
        }
    }

    if(isSame) cout << "YES";
    else cout << "NO";
    
    return 0;
}