#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define sz(x) ((int)(x).size())
#define EPS (1e-9)
#define INF ((int)1e9)
#define mp make_pair
#define pb push_back

const int maxn = 100;
char s[maxn + 1];

int n;

struct pt {
  int a[maxn];

  inline bool operator<(const pt &p) const {
    for (int i = 0; i < n; i++)
      if (a[i] != p.a[i])
        return a[i] < p.a[i];
    return 0;
  }
};

pt id[maxn * maxn];

int main() {
  int h, w;
  while (scanf("%d%d%d", &n, &h, &w) >= 1) {
    for (int iter = 0; iter < n; iter++) {
      for (int i = 0; i < h; i++) {
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
          id[w * i + j].a[iter] = (s[j] == '*');
        }
      }
    }

    sort(id, id + h * w);

    int ans = 0;
    for (int i = 0; i < h * w;) {
      int i0 = i;
      while (i < h * w && !(id[i0] < id[i]))
        i++;
      ans++;
    }

    printf("%d\n", ans);
  }

  return 0;
}
