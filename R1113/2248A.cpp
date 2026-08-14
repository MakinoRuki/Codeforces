
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base = 337;

int n, m, q;
int k, w;
int t;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
//    scanf("%d", &n);

    string s;
    cin >> s;
    n = (int)s.size();

    string ans = "";

    bool deleted0 = false;
    bool deleted1 = false;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '0' && !deleted0) {
        deleted0 = true;
        continue;
      }

      if (s[i] == '1' && !deleted1) {
        deleted1 = true;
        continue;
      }

      ans.push_back(s[i]);
    }

    cout << ans << endl;
  }

  return 0;
}
