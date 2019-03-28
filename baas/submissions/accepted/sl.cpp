#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<vi> deps(N);
	vector<ll> times(N);
	rep(i,0,N) cin >> times[i];
	rep(i,0,N) {
		int count;
		cin >> count;
		deps[i].resize(count);
		rep(j,0,count) {
			cin >> deps[i][j];
			--deps[i][j];
			assert(deps[i][j] < i);
		}
	}

	ll res = LLONG_MAX;
	rep(elim,0,N) {
		vector<ll> dp(N);
		rep(i,0,N) {
			ll start = 0;
			trav(x, deps[i]) start = max(start, dp[x]);
			dp[i] = start + (elim == i ? 0 : times[i]);
		}
		res = min(res, dp.back());
	}
	cout << res << endl;
}
