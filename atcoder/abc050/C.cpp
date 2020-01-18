#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin, (X).rend()
#define DRI(X) int (X); cin >> X
#define DRII(X, Y) int X, Y; cin >> X >> Y
#define DRIII(X, Y, Z) int X, Y, Z; cin >> X >> Y >> Z
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define readV(X) for(int &ele : (X)) cin >> ele
#define readVI(X) for(int idx = 1; idx < SZ((X)); ++idx) cin >> (X)[idx]
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MP make_pair
#define PB push_back
#define F first
#define S second
 
using namespace std;
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
//     cerr << *it << " = " << a << endl;
//     err(++it, args...);
// }
// template<typename... Args>
// void read(Args&... args)
// {
//     ((cin >> args), ...);
// }
 
// template<typename... Args>
// void write(Args... args)
// {
//     ((cout << args), ...);
// }
typedef long long LL;
const int INF = 1<<29;
 
 
int main(){
    FAST_IO
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int N, ok = true, n, M = 1e9 + 7; cin >> N;
    vector<int> d(N, 0);

    auto two = [&](int m){
        LL cur = 1;
        while(m){
            cur = cur * 2;
            if(cur >= M) cur -= M;
            m--;
        }
        return cur;
    };

    REP(rep, 0, N){
        cin >> n;
        if(n % 2 == N % 2){
            ok = false;
            break;
        }
        d[n]++;
    }
    // for(int idx = 0; idx < N; ++idx){
    //     cerr << idx << " ----->  " << d[idx] << endl;
    // }
    for(int s = 1 - (N % 2); s < N && ok; s += 2){
        // cerr << s << " ----->  ";
        // cerr << d[s] << endl;
        if(d[s] != 1 + (s > 0)){
            ok = false;
            break;
        }
    }
    if(!ok) cout << "0\n";
    else cout << two(N / 2);
}    