
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
int a[N];

vector<pair<int, int> > v;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    int m = k/2+1+k/2+1;
    string ans="";
    if (k == 0) {
      for (int i = 0; i < n; ++i) {
        if (i&1) ans += "0";
        else ans += "1";
      }
      cout<<ans<<endl;
      continue;
    }
    if (k == 1) {
      if (n <= 2) puts("-1");
      else {
        ans += "00";
        if (n >= 3) {
          ans = "1" + ans;
        }
        for (int i = 3; i < n; ++i) {
          if ((i&1)) ans += "1";
          else ans += "0";
        }
        cout<<ans<<endl;
      }
      continue;
    }
    if (k%2) m++;
    if (m > n) {
      puts("-1");
      continue;
    }
    for (int i = 0; i <= k/2; ++i) {
      ans.push_back('0');
    }
    for (int i = 0; i <= k/2; ++i) {
      ans.push_back('1');
    }
    if (k%2) ans += "1";
    int dt = n-m;
    for (int i = 1; i <= dt; ++i) {
      if (i&1) ans += "0";
      else ans += "1"; 
    }
    cout<<ans<<endl;
  }

  return 0;
}
