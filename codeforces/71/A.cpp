#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    string curS;
    for(int itr = 0; itr < N; ++itr){
        cin >> curS;
        int M = curS.size();
        if(M <= 10) cout << curS << endl;
        else{
            string abbr;
            abbr.push_back(curS[0]);
            abbr += to_string(M - 2);
            abbr.push_back(curS.back());
            cout << abbr << endl;
        }
    }
    return 0;
}