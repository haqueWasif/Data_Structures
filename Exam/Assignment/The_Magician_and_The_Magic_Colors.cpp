#include<bits/stdc++.h>
using namespace std;

void mixColor(stack <char> &colorS, char prevColor, char color){
    if(prevColor == color){
        colorS.pop();
    }
    else if(prevColor == 'R' && color == 'G' || prevColor == 'G' && color == 'R'){
        colorS.pop();

        if(!colorS.empty()){
            prevColor = colorS.top();
            color = 'Y';

            if(prevColor == color){
                colorS.pop();
                return;
            }
        }
        
        colorS.push('Y');
    }
    else if(prevColor == 'G' && color == 'B' || prevColor == 'B' && color == 'G'){
        colorS.pop();

        if(!colorS.empty()){
            prevColor = colorS.top();
            color = 'C';

            if(prevColor == color){
                colorS.pop();
                return;
            }
        }

        colorS.push('C');
    }
    else if(prevColor == 'R' && color == 'B' || prevColor == 'B' && color == 'R'){
        colorS.pop();

        if(!colorS.empty()){
            prevColor = colorS.top();
            color = 'P';

            if(prevColor == color){
                colorS.pop();
                return;
            }
        }

        colorS.push('P');
    }
    else{
        colorS.push(color);
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        stack <char> colorS;

        int n;
        cin >> n;    

        char prevColor;
        while(n--)
        {
            char color;
            cin >> color;

            if(colorS.empty()){
                colorS.push(color);
            }
            else{
                prevColor = colorS.top();
                mixColor(colorS, prevColor, color);
            }
            
        }

        stack <char> newColorS;
        while(!colorS.empty()){
            newColorS.push(colorS.top());
            colorS.pop();
        }

        while(!newColorS.empty()){
            cout << newColorS.top();
            newColorS.pop();
        }
        cout << endl;
        
    }

    return 0;
}