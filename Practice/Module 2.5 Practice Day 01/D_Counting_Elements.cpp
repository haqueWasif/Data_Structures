#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int count=0;
    for (int val : v)
    {
        auto it = find(v.begin(), v.end(), val+1);
        if(it != v.end()) count++;
    }
    cout << count;
    
    return 0;
}