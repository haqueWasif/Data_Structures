#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    // cout << v.max_size() << endl;
    
    // cout << v.capacity() << endl;

    // v.push_back(5);
    // cout << v.capacity() << endl;
    // v.push_back(10);
    // cout << v.capacity() << endl;
    // v.push_back(15);
    // cout << v.capacity() << endl;
    // v.push_back(20);
    // cout << v.capacity() << endl;
    // v.push_back(25);
    // cout << v.capacity() << endl;

    // if number of elements is more than size then capacity is doubled that of size

    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // v.push_back(50);
    // v.clear();
    // cout << v.size() << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << v[0] << endl;

    // So after using clear() size becomes 0 but memory still remains

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    v.resize(2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.resize(7, 100);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;




    return 0;
}