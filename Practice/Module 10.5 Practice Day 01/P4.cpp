#include<bits/stdc++.h>
using namespace std;

int main(){
    list <int> l;
    
    int q;
    cin >> q;
    while(q--){
        int x, v;
        cin >> x >> v;

        if(x > l.size()) cout << "Invalid" << endl;
        
        else{
            l.insert(next(l.begin(), x), v);
    
            for (int val : l) cout << val << " ";
            cout << endl;  
    
            for (int i = l.size()-1; i >= 0 ; i--)
            {
                cout << *(next(l.begin(), i)) << " ";
            }
            cout << endl; 
        }
         
    }

    return 0;
}