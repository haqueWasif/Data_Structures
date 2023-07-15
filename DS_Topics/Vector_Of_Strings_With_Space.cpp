#include<bits/stdc++.h>
using namespace std;

// When we want to use different strings then we can use vector which works like 2d array 

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector <string> v(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, v[i]);
    }

    for (string val : v)
    {
        cout << val << endl;
    }
        
    

    return 0;
}