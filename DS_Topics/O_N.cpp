#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; // O(1)
    cin >> n; // O(1)

    int a[n]; // O(1)
    for (int i = 0; i < n; i++) 
    // O(n)
    {
        cin >> a[i];  
    }
    
    int s=0; // O(1)
    for (int i = 0; i < n; i++)
    // O(n)
    {
        s+=a[i];
    }
    
    cout << s << endl; // O(1)

    // Complexity is O(n)
    return 0;
}