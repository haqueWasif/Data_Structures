#include<bits/stdc++.h>
using namespace std;

/*

Nested loop:
O(N^2) or O(N * M)

O(N^2) -> Maximum value of N can be 1000

*/

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) // O(N*N)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "hello" << endl;
        }
        
    }

    // Selection Sort
    for (int i = 0; i <= n-1; i++) // O(N*N)
    {
        for (int j = i+1; j < n; j++)
        {
            /* code */
        }
        
    }
    
    // sum of n terms 

    
    return 0;
}