#include<bits/stdc++.h>
using namespace std;

// better than O(N) but worser  than O(logN) 

int main(){
    int n;
    cin >> n;

    // Method 1
    // for (int i = 1; i <= sqrt(n); i++)
    // // O(sqrt(N))
    // {
    //     if(n%i == 0){
    //         cout << i << " ";
    //         if(n/i != i){
    //           cout << n/i << endl;
    //         }   
    //     }
    // }

    // Method 2
    for (int i = 1; i * i <= n; i++)
    // O(sqrt(N))
    {
        if(n%i == 0){
            cout << i << " ";
            if(n/i != i){
              cout << n/i << endl;
            }   
        }
    }
    
    return 0;
}