#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

// Complexity of the Binary Search is logN and complexity of sort is NlogN

// outer while loop have complexity of N and the binary search have complexity of logN so final complexity of the loop is NlogN

// Final complexity of code is N + NlogN -> N

// but if we had used linear search then complexity of outer while loop is N and the linear search is also N so final complexity of the loop would be N^2

// Final complexity of code would be N + N^2 -> N^2

    while(q--){
        int x;
        cin >> x;

        int l=0, r=n-1, mid;

        int isFound = 0;
        while(l<=r){
            mid = (l + r) / 2;
            if(x == v[mid]){
                isFound = 1;
                break;
            }
            else if ( x < v[mid]) {
                r = mid - 1;
            }
            else l = mid + 1;
        }

        if(isFound) cout << "found" << endl;
        else cout << "not found" << endl;

    }

    return 0;
}