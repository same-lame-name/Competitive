#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO

	int N, current = 0;
	vector<pair<int, int>> choices;

	cin >> N;
	for(int rep = 0, a, b; rep < N; ++rep){
		cin >> a >> b;
		choices.push_back(make_pair(a, b));
	}

	sort(choices.begin(), choices.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.first != b.first) return a.first < b.first;
		return a.second < b.second;
	});

	for(pair<int, int> choice : choices){
		if(choice.second >= current) current = choice.second;
		else current = choice.first;
	}


	cout << current << '\n';
	return 0;
}
