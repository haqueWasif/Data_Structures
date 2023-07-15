#include<bits/stdc++.h>
using namespace std;

/*
-> This works internally like doubly linked list as like vector worked internally like dynamic array

-> Capacity function which is present in vector is not present here since as in array it is required to allocate memory initially for contigous allocation which is not required in list

*/

int main(){
    // list <int> myList;
    // list <int> list2 = {1,2,3,4,5};
    // int arr[] = {1,2,3,4,5};
    vector <int> v = {1,2,3,4,5};

    // list <int> myList(10, 5);

    // list <int> myList(list2);
    // list <int> myList(a, a+5);
    list <int> myList(v.begin(), v.end());

    // for(auto itr = myList.begin(); itr!=myList.end(); itr++)
    // {
    //     cout << *itr << " ";
    // }

    /* Capacity Functions */

    // myList.clear();
    myList.resize(2);
    myList.resize(5, 100);
    for (int val : myList)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << myList.size() << endl;

    cout << myList.max_size() << endl;

    /* Modifiers Functions */

    list <int> myList2 = {10,20,30};
    list <int> newList;
    
    // newList.assign(myList2.begin(), myList2.end());
    // In vector -> newVec.assign(myVec)
    newList = myList2;
    
    for (int val : myList2)
    {
        cout << val << " ";
    }
    cout << endl;

    myList2.push_front(110); // Insertion at head
    myList2.push_front(210); // Insertion at head
    myList2.push_front(310); // Insertion at head

    myList2.push_back(410); // Insertion at tail
    myList2.push_back(510); // Insertion at tail
    myList2.push_back(610); // Insertion at tail

    myList2.pop_front(); // Deletion at head
    myList2.pop_back(); // Deletion at tail

   
    for (int val : myList2)
    {
        cout << val << " ";
    }
    cout << endl;

    myList2.insert(next(myList2.begin(), 2), 100);
    // myList2.insert(next(myList2.begin(), 2), {100, 200, 300});
    // myList2.insert(next(myList2.begin(), 2), myList.begin(), myList.end());
    // myList2.insert(next(myList2.begin(), 2), v.begin(), v.end());
    // myList2.insert(next(myList2.begin(), 2), arr, arr + sizeof(arr)/4);

    // In Vector we can use insert(myVec.begin()+2, 100) but in list this cannot be used like this as this tries to access the index with O(1) but in list we cannot directly have access to a particular node with O(1)
    // So we have to use the next function which takes 2 arguments the first one indicates the starting iterator and the last one indicates how many places to go after the starting pointer
    // Complexity of insertion is O(N) for both vector and list
    // It is also important to note that giving the last argument more than the size this starts to count again from start so it works like a cycle for example if the last argument is 1 more than the size then it inserts at head

    for (int val : myList2)
    {
        cout << val << " ";
    }
    cout << endl;

    myList2.erase(next(myList2.begin(), 2));
    // myList2.erase(next(myList2.begin(), 2), next(myList2.begin(), 5));
    // Erases starting from element at index 2 till the element at index 5 but not the element at index 5 itself

    for (int val : myList2)
    {
        cout << val << " ";
    }
    cout << endl;

    replace(myList2.begin(), myList2.end(), 10, 500);
    
    for (int val : myList2)
    {
        cout << val << " ";
    }
    cout << endl;

    auto itr = find(myList2.begin(), myList2.end(), 20);
    if(itr != myList2.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }


    /* Operations and Access Related Functions */
    list <int> myList3 = {20, 40, 30, 10, 50, 10, 10};
    
    // myList3.remove(10);
    // myList3.sort();
    myList3.sort(greater<int>());
    for (int val : myList3)
    {
        cout << val << " ";
    }
    cout << endl;

    myList3.unique();
    // Needs to be sorted before use otherwise it will not correctly remove 
    for (int val : myList3)
    {
        cout << val << " ";
    }
    cout << endl;

    myList3.reverse();

    for (int val : myList3)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << myList3.front() << " " << myList3.back() << endl;

    cout << *next(myList3.begin(), 2) << endl;

    return 0;
}