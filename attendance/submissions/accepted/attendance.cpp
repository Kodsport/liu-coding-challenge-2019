// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::array;
using std::map;
using std::set;
using std::string;
using std::vector;

using std::make_pair;
using std::pair;

using std::get;
using std::make_tuple;
using std::tuple;

using std::abs;
using std::max;
using std::min;

using std::generate;
using std::max_element;
using std::min_element;
using std::reverse;
using std::sort;
using std::unique;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X)                                                             \
  {}
#endif

template <typename T> T input() {
  T res;
  cin >> res;
  LASSERT(cin);
  return res;
}

template <typename IT> void input_seq(IT b, IT e) {
  std::generate(b, e,
                input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec) int((vec).size())
#define ALL(data) data.begin(), data.end()
#define RALL(data) data.rbegin(), data.rend()
#define TYPEMAX(type) std::numeric_limits<type>::max()
#define TYPEMIN(type) std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // code here
  int n = input<int>();
  int m = input<int>();

  vector<int> lst(m);
  for (int &elem : lst)
    elem = input<int>() - 1;

  vector<int> order(n);
  for (int &elem : order)
    elem = input<int>() - 1;

  int ptr = 0;
  vector<char> mark(n + 228);

  vector<int> z;

  for (int el : lst)
    if (mark[el])
      z.push_back(el);
    else
      while (not mark[el]) {
        z.push_back(order[ptr]);
        mark[order[ptr++]] = 1;
      }

  cout << SZ(z) << "\n";

  vector<vector<int>> by_ind(n);
  for (int i = 0; i < SZ(z); ++i)
    by_ind[z[i]].push_back(i);

  for (int i = 0; i < n; ++i)
    by_ind[i].push_back(TYPEMAX(int) - i);

  vector<int> fenw(SZ(z));
  vector<char> on_and_on(SZ(z), 0);
  auto kek_it = [&](int i, int val) {
    if (i >= SZ(z))
      return;

    on_and_on[i] += val;
    for (; i < SZ(fenw); i = i | (i + 1))
      fenw[i] += val;
  };

  auto kukarek = [&](int i) {
    if (i >= SZ(z))
      i = SZ(z) - 1;

    int res = 0;
    for (; i != -1; i = (i & (i + 1)) - 1)
      res += fenw[i];
    return res;
  };

  for (int i = 0; i < n; ++i)
    kek_it(by_ind[i][0], 1);

  int pptr = 0;
  for (int iter = 0; iter != SZ(z); ++iter) {
    while (on_and_on[pptr] == 0)
      ++pptr;
    int cur = pptr;
    int next = *std::upper_bound(ALL(by_ind[z[cur]]), cur);

    kek_it(cur, -1);
    cout << 1 + kukarek(next) << " ";
    kek_it(next, +1);
  }

  cout << "\n";

  return 0;
}
