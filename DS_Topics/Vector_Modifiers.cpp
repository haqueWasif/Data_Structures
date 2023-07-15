#include<bits/stdc++.h>
using namespace std;

int main(){
    /* 
    
    // 1
    
    vector <int> x = {10, 20, 30};
    vector <int> v = {1, 2, 3};
    v=x; // O(1)

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    */

    /*
     
    // 2

    vector <int> x = {10, 20, 30, 40, 50};
    vector <int> v = {1, 2, 3};
    v=x; // O(N)

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    */

    /*

    // 3 
    
    vector <int> x = {10, 20, 30, 40, 50};
    x.pop_back();
    x.pop_back();
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
   
   */
    

    /*

    // 4

    vector <int> v = {1,2,3,4,5};
    
    // v.insert(v.begin()+2, 10);
    // for(int x: v){
    //     cout << x << " ";
    // }

    vector <int> v2 = {100,101,102,103};
    v.insert(v.begin()+2, v2.begin(), v2.end());
    for (int x: v)
    {
        cout << x << " ";
    }
    
    */

    /*

    // 5

    vector <int> v = {1,2,3,4,5};
    
    // v.erase(v.begin()+3);
    // v.erase(v.begin()+1, v.begin()+4);
    v.erase(v.begin()+1, v.end()-1);

    for (int x:v)
    {
        cout << x << " ";
    }

    */  


    /*
    
    // 6

    vector <int> v = {1,2,3,4,5,1,3,2,1,2,5,6,2,1,9};
    replace(v.begin(), v.end(), 2, 100);
    for (int x:v)
    {
        cout << x << " ";
    }
    
    */

    vector <int> v = {1,2,3,4,5,1,3,2,1,2,5,6,2,1,9};

    // vector<int> :: iterator it;
    // it = find(v.begin(), v.end(), 3);
    
    auto it = find(v.begin(), v.end(), 3);

    if(it == v.end()) cout << "Not Present";
    else cout << "Present"; 
    
    return 0;
}