#include <bits/stdc++.h>
using namespace std;

int main(){
	int lenS, charC; cin >> lenS >> charC;
        string S; cin >> S;
        unordered_map<char, bool> isPresent;
        for(int itr = 0; itr < charC; ++itr){
            char curChar; cin >> curChar;
            isPresent[curChar] = true;
        }
        long long totalSubS = 0;
        long long curLen = 0, rightIdx = 0;
        while(rightIdx <= lenS){
            if(rightIdx == lenS){
            	totalSubS += (curLen * (curLen + 1)) / 2;
                rightIdx++;
                continue;
            }
            char curChar = S[rightIdx];
            if(isPresent.count(curChar)){
                curLen++;
            }
            else{
                totalSubS += (curLen * (curLen + 1)) / 2;
                curLen = 0;
            }
            rightIdx++;
        }
        cout << totalSubS << endl;
    return 0;
}