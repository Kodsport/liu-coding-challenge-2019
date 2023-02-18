#include "validator.h"

const int MAX_N = 400;
const int MAX_AI = 100000;

bool is_unique(const vector<int>& v) {
  set<int> a(v.begin(), v.end());
  return v.size() == a.size();
}

void run() {
	int n = Int(1, MAX_N); Endl();

  SpacedInts(n, 1, MAX_AI); 

  vector<set<int>> reachable(n);

  for (int i = 0; i < n; i++) {
    int ci = Int(0, n - 1);
    if (ci) Space();
    vector<int> adj = SpacedInts(ci, 1, i);
    assert(is_unique(adj));
    for (int dep : adj) {
      reachable[i].insert(reachable[dep - 1].begin(), reachable[dep - 1].end());
    }
    reachable[i].insert(i + 1);
    assert(reachable[i].count(1));
  }
  assert(reachable.back().size() == n);
}
