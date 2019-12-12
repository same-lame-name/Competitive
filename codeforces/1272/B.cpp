#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	int Q; cin >> Q;
        while(Q--){
            string S; cin >> S;
            unordered_map<char, ll> charC;
            for(char c : S) charC[c]++;
            ll LR = min(charC['L'], charC['R']);
            ll UD = min(charC['U'], charC['D']);
            if(LR == 0 || UD == 0){
                if(LR){
                    cout << 2 << endl << "LR" << endl;
                }
                else if(UD){
                    cout << 2 << endl << "UD" << endl;
                }
                else{
                    cout << 0 << endl << endl;
                }
            }
            else{
            	string o;
                for(ll itr = 0; itr < LR; ++itr){
                    o += "R";
                }
                for(ll itr = 0; itr < UD; ++itr){
                    o += "D";
                }
                for(ll itr = 0; itr < LR; ++itr){
                    o += "L";
                }
                for(ll itr = 0; itr < UD; ++itr){
                    o += "U";
                }
             
                cout << 2* (LR + UD) << endl;
                cout << o << endl;
            }
        }
        
    return 0;
}