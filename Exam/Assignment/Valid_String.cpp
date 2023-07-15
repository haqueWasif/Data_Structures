#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    
    while(t--){
        stack <char> charS;
        
        string s;
        cin >> s;

        char prevChar;
        for (char ch : s)
        {
            if(!charS.empty()){
                prevChar = charS.top();
                if(prevChar != ch){
                    charS.pop();
                    continue;
                }
            }
            charS.push(ch);
        }

        if(charS.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
        
        
    }

    return 0;
}