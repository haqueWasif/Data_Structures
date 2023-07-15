#include<bits/stdc++.h>
using namespace std;


class myQueue{
    list <int> l;
    public:
        void push(int v){
            l.push_back(v);
        }
        void pop(){
            l.pop_front();
        }
        bool empty(){
            return l.empty();
        }
        int front(){
            return l.front();
        }
        int size(){
            return l.size();
        }

};

int main(){
    myQueue q;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        q.push(v);
    }

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    
    return 0;
}