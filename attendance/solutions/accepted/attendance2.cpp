#include <bits/stdc++.h>

using namespace std;

struct once {
  bool flag = false;

  bool operator()() {
    if (!flag) {
      return flag = true;
    }
    return false;
  }
};

struct segtree {
  vector<int> tree;
  int N;

  segtree(int n) {
    tree.resize(4 * n);
    N = n;
  }

  void add(int v, int tl, int tr, int pos, int val) {
    tree[v] += val;
    if (tl < tr) {
      int m = (tl + tr) / 2;
      if (pos <= m) {
        add(v * 2, tl, m, pos, val);
      } else {
        add(v * 2 + 1, m + 1, tr, pos, val);
      }
    }
  }

  int sum(int v, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r) {
      return tree[v];
    }
    if (tl > r || tr < l) {
      return 0;
    }
    int m = (tl + tr) / 2;
    return sum(v * 2, tl, m, l, r) + sum(v * 2 + 1, m + 1, tr, l, r);
  }

  void add(int pos, int val) { add(1, 0, N - 1, pos, val); }

  int sum(int l, int r) { return sum(1, 0, N - 1, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> items(m);
  queue<int> keys;
  for (auto &x : items) {
    cin >> x;
    x--;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    keys.push(x);
  }
  vector<int> order;
  vector<char> free(n);
  for (auto item : items) {
    if (!free[item]) {
      while (true) {
        bool end = keys.front() == item;
        order.push_back(keys.front());
        free[keys.front()] = true;
        keys.pop();
        if (end) {
          break;
        }
      }
    } else {
      order.push_back(item);
    }
  }
  vector<int> last(n, -1);
  vector<int> next(order.size(), -1);
  segtree tree(order.size());

  for (int i = 0; i < order.size(); i++) {
    if (last[order[i]] >= 0) {
      next[last[order[i]]] = i;
    } else {
      tree.add(i, 1);
    }
    last[order[i]] = i;
  }
  vector<int> ans;

  for (int i = 0; i < order.size(); i++) {
    if (next[i] == -1) {
      ans.push_back(n - 1);
    } else {
      ans.push_back(tree.sum(i, next[i]) - 1);
      tree.add(next[i], 1);
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x + 1 << ' ';
  }
  return 0;
}
