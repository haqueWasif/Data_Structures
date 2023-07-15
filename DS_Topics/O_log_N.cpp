#include<bits/stdc++.h>
using namespace std;

/*
N = 1000

1000 -> 500 -> 250 -> 125 -> 62 -> 31 -> 15 -> 7 -> 3 -> 1

1000/1 -> 1000/2^1 -> 1000/2^2 -> 1000 / 2^3 -> ....

let k be the steps to reduce n to 1

N / 2^k = 1
-> 2^k = N

so, k = logN

example:
for(int i=1; i<=N; i*=2){

}

for(int i=N; i>=1; i/=2){

}


So

O(N) -> 10^7
O(logN) -> 10^18 ( not maximum but to specify that this much more steps can be done using O(logN))

*/

int main(){
    int n;
    cin >> n;

    while(n>0){ // O(logN)
        int digit = n%10;
        cout << digit << endl;
        n/=10;
    }

    for (int i = 1; i <= n; i*=2) // O(logN)
    {
        cout << i << endl;
    }
    
    return 0;
}