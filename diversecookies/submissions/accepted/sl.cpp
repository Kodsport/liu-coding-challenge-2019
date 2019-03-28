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
	ll N, A, B, C;
	cin >> N >> A >> B >> C;
	if (A > B) swap(A, B);
	if (B > C) swap(B, C);
	if (A > B) swap(A, B);
	assert(A <= B);
	assert(B <= C);

	if (C <= N) {
		cout << A + B + C << endl;
		return 0;
	}
	cout << A + B + min(C, A + B + N) << endl;
}
