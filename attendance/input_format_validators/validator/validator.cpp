#include "validator.h"

constexpr int MAX_N = 3e5;

void run() {
  int n = Int(1, MAX_N);
  Space();
  int m = Int(1, MAX_N);
  Endl();
  for (int i = 0; i < m; ++i) {
    Int(1, n);
    i + 1 == m ? Endl() : Space();
  }
  for (int i = 0; i < n; ++i) {
    Int(1, n);
    i + 1 == n ? Endl() : Space();
  }

  Eof();
}
