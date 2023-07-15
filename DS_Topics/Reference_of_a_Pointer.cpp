#include<bits/stdc++.h>
using namespace std;

/*

void fun(int* p)
{
    p = NULL;
    cout << &p << endl;
}

// This will not change ptr to NULL but by deferencing it the val can be changed

*/

void fun(int* &p)
{
    p = NULL;
    cout << &p << endl;
}

int main(){
    int val = 10;
    int *ptr = &val;

    fun(ptr);
    cout << &ptr << endl;

    return 0;
}