#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using vb = vector<bool>;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define eb emplace_back
#define ins insert
#define mp make_pair
#define mt make_tuple
#define rev reverse
#define precise(x) cout << fixed << setprecision(x)
#define accum(x, y) accumulate(all(x), y)
#define rep(x) for(int i = 0; i < x; i++)
#define rep2(x, y) for(int i = x; i < y; i++)
#define rep3(x, y, z) for(int i = x; j < y; i += z)
#define per(x) for(int i = x; i >= 0; i--)
#define per2(x, y) for(int i = x; i >= y; i--)
#define per3(x, y, z) for(int i = x; i >= y; i -= z)
#define repa(x, y) for(auto x : y)
#define repr(x, y) for(auto &x : y)
#define krep(i, x) for(int i = 0; i < x; i++)
#define krep2(i, x, y) for(int i = x; i < y; i++)
#define krep3(i, x, y, z) for(int i = x; i < y; i += z)
#define debug(x) cout << #x << " = " << x << endl
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
#define len(x) (int)x.length()

const int dr4[] = {0, 1, 0, -1};
const int dc4[] = {1, 0, -1, 0};

const int dr8[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int dc8[] = {1, 0, -1, 0, -1, -1, 1, 1};

void setIO(str name = "") {
	cin.tie(0) -> sync_with_stdio(0);
	if(sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

template<typename T>
bool ckmax(T &a, T b) { return b > a ? a = b, 1 : 0; };
template<typename T>
bool ckmin(T &a, T b) { return b < a ? a = b, 1 : 0; };

/* Main Code */

template<typename T>
int LIS(const vector<T> &a) {
	vector<T> u;
	for(const T &x: a) {
		auto it = upper_bound(all(u), x);
		if(it == u.end()) u.pb(x);
		else *it = x;
	}
	return sz(u);
}

void solve() {
	int n; cin >> n;
	vi a(n);
	rep(n) cin >> a[i];
	cout << LIS(a) << endl;
}

int main() {
	setIO();
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

