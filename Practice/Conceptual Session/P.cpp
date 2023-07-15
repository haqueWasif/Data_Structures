class Solution {
public:
    int findTheWinner(int n, int k) {
        bool winner[n];
        for (int i = 0; i < n; i++)
        {
            winner[i] = true;
        }
        
        for(int i=0; i<=n-1; i++){
            i += k;
            if(i > n){
                i -= n;
            }
            if(winner[i-1] == false){
                break;
            }
            winner[i-1] = false;
        }
        for(int i=0; i<n; i++){
            if(winner[i] == true){
                return i+1;
            }
        }
    }
};