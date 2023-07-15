#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> freq(26, 0);
    char c;
    while(cin >> c) freq[c-'a']++;
    for (int i=0; i<26; i++)
    {
        if(freq[i] > 0) 
        cout << (char)(i+'a') << " : " << freq[i] << endl; 
    }
    return 0;
}