#include<bits/stdc++.h>
using namespace std;

// O(Nlog(N)) is worser than O(N) and better than O(N^2)

/*
N = 10^6

NlogN = 20 * 10^6 = 2 * 10^7 = 2s

N = 10^5
NlogN = 16 * 10^5 = 1.6 * 10^6 ~ 1s

*/
int main(){
    int n;
    cin >> n;

    // O(Nlog(N))
    for (int i = 1; i <= n; i++)
    { // O(N)
        int x = i;
        while (x > 0) // O(log(N))
        {
            int digit = x%10;
            cout << digit << " ";
            x /= 10;
        }
        cout << endl;
        
    }
    
    return 0;
}