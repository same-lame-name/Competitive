#include <bits/stdc++.h>
using namespace std;

int main(){
	long long length, breadth, side;
	cin >> length >> breadth >> side;
	long long rowN = (length / side) + (length % side > 0);
	long long colN = (breadth / side) + (breadth % side > 0);
	long long result = rowN * colN;
	cout << result << endl;
	return 0;
}