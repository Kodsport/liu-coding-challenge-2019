/*
 * usage:
 *  cat /path/to/input /path/to/judge/answer /path/to/participant/answer | \
 * ./a.out
 */

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()
#define re return
using namespace std;
const int CMAX = int(1e9), MAXN = int(3e5);
string s;
int n, m;
vector<int> a, b;

struct node {
  node *l, *r;
  int key, pr;
  int cnt = 0;
  node() {
    key = pr = 0;
    cnt = 0;
    l = r = NULL;
  }
  node(int k1) {
    key = k1;
    cnt = 1;
    l = r = NULL;
    pr = rand();
  }
};

typedef node *qnode;

int get_cnt(qnode a) {
  if (a == NULL)
    re 0;
  re(a->cnt);
}

void upd_cnt(qnode &a) {
  if (a == NULL)
    re;
  a->cnt = get_cnt(a->l) + 1 + get_cnt(a->r);
}

void split(qnode &l, qnode &r, qnode t, int key) {
  if (t == NULL) {
    l = r = NULL;
    re;
  }
  if (get_cnt(t->l) + 1 < key) {
    split(t->r, r, t->r, key - get_cnt(t->l) - 1);
    l = t;
  } else {
    split(l, t->l, t->l, key);
    r = t;
  }
  upd_cnt(l);
  upd_cnt(r);
  upd_cnt(t);
}

void insert(qnode &a, qnode c, int key) {
  if (a == NULL) {
    a = c;
    upd_cnt(a);
    re;
  }
  // cout << (a->key) << " koh " << key << "\n";
  if ((a->pr) > (c->pr)) {
    split(c->l, c->r, a, key);
    a = c;
  } else {
    if (get_cnt(a->l) + 1 < key)
      insert(a->r, c, key - (get_cnt(a->l) + 1));
    else
      insert(a->l, c, key);
  }
  upd_cnt(a);
}

void merge(qnode &a, qnode l, qnode r) {
  if (l == NULL) {
    a = r;
    upd_cnt(a);
    re;
  }
  if (r == NULL) {
    a = l;
    upd_cnt(a);
    re;
  }
  if ((l->pr) < (r->pr)) {
    merge(l->r, l->r, r);
    a = l;
  } else {
    merge(r->l, l, r->l);
    a = r;
  }
  upd_cnt(l);
  upd_cnt(r);
  upd_cnt(a);
}

int delete1(qnode &a, int key) {
  if (a == NULL)
    re 0;
  int c = 0;
  if (get_cnt(a->l) >= key) {
    c = delete1(a->l, key);
  } else {
    if (key == get_cnt(a->l) + 1) {
      c = (a->key);
      merge(a, a->l, a->r);
    } else {
      c = delete1(a->r, key - get_cnt(a->l) - 1);
    }
  }
  upd_cnt(a);
  re c;
}

void out_tree(qnode a) {
  if (a == NULL)
    return;
  out_tree(a->l);
  cout << (a->key) << " ";
  out_tree(a->r);
}

bool readAns(istream &in, int &k) {
  cin >> k;

  if (k < 1 || k > 1e9) {
    cout << "WA: k must be 1 <= k <= 1e9" << endl;
    return false;
  }

  int pos = 0;
  qnode root = NULL;
  forn(i, n) insert(root, new node(b[i]), i + 1);
  forn(i, k) {
    if (pos >= m) {
      cout << "WA: interactions after all names have been crossed off" << endl;
      return false;
    }
    int c;
    if (!(in >> c)) {
      cout << "WA: invalid number of names" << endl;
      return false;
    }

    if (c < 1 || c > n) {
      cout << "WA: c must be 1 <= c <= n" << endl;
      return false;
    }

    int we = delete1(root, 1);
    if (we == a[pos]) {
      pos++;
    }
    insert(root, new node(we), c);
  }
  if (pos < m) {
    cout << "WA: not all names are crossed off" << endl;
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  b.resize(n);
  a.resize(m);
  forn(i, m) cin >> a[i];
  forn(i, n) cin >> b[i];
  int k, kk;
  readAns(cin, k);

  if (readAns(cin, kk)) {
    if (k < kk) {
      cout << "WA: too many interactions" << endl;
      return 43;
    } else if (k > kk) {
      cout << "woops, participant answer is better" << endl;
      abort();
    } else {
      cout << k << " intractions" << endl;
      return 42;
    }
  }
  return 43;
}
