#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll n, m;
vvl X, dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  X = vvl(n + 1, vl(m + 1, 0));
  for (auto i = 1; i <= n; ++i) {
    string x;
    cin >> x;
    for (auto j = 1; j <= m; ++j) {
      X[i][j] = x[j - 1] - '0';
    }
  }

  dp = vvl(n + 1, vl(m + 1, 0));
  ll ans = 0;
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      if (X[i][j] == 1) {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        if (ans < dp[i][j]) {
          ans = dp[i][j];
        }
      }
    }
  }
  cout << ans * ans;

  return 0;
}