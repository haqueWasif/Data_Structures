#include<bits/stdc++.h>
using namespace std;

// At first we tried to solve it using bruteforce approach 

/*
    BruteForce Approach : We just try to solve the problem we do not care about time complexity or efficiency of algorithm
*/

// We use prefix sum when we have something related with range sum

int main(){
    int n, q;
    cin >> n >> q;

    vector <long long int> v(n);
    vector <long long int> Psum(n); 

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        if(i==0) Psum[i] = v[i];
        else Psum[i] = v[i] + Psum[i-1]; 
    }

    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        long long int sum  = Psum[r-1] - Psum[l-1] + v[l-1];
        printf("%lld\n", sum);
    }

    return 0;
}