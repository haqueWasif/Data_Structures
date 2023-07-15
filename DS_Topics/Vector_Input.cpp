#include<bits/stdc++.h>
using namespace std;

int main(){
    /*

    vector <int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    This will not work as when we declared the vector as v we didn't include its size

    So there is no guarrante that the indices are available

    */

   /* 1st Method */

    // vector <int> v;
    // int n;
    // cin >> n;
    
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }

    /* 2nd Method */

    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for (int val:v)
    {
        cout << val << " ";
    }
    
    

    
    return 0;
}