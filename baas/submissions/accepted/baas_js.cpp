#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi T;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
  int N;
  cin >> N;
  T.resize(N);
  rep(i,0,N) cin >> T[i];
  vector<vi> DP(N);
  rep(i,0,N) {
    vi& ans = DP[i];
    ans.resize(N);
    int M;
    cin >> M;
    rep(j,0,M) {
      int c;
      cin >> c;
      rep(k,0,N) ans[k] = max(ans[k], DP[c - 1][k]);
    }
    rep(j,0,N) if (i != j) ans[j] += T[i];
  }
  cout << *min_element(all(DP.back())) << endl;
}
