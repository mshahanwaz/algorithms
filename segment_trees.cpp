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

class SegmentTree {
private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) {
		if(L == R) st[p] = L;
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}
	int rmq(int p, int L, int R, int i, int j) {
		if(i > R || j < L) return -1;
		if(L <= i && R <= j) return st[p];
		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (A[p1] <= A[p2]) ? p1 : p2;
	}
public:
	SegmentTree(const vi &_A) {
		A = _A;
		n = sz(A);
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int RMQ(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
	}
};

void solve() {
	int n; cin >> n;
	vi a(n);
	rep(n) cin >> a[i];
	SegmentTree st(a);
	int q; cin >> q;
	rep(q) {
		int l, r; cin >> l >> r;
		cout << "RMQ(" << l << ", " << r << ") = " << st.RMQ(l, r) << endl;
	}
}

int main() {
	setIO();
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

