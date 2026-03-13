
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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
bool check(string& s, int st) {
  for (int i = st; i < n; i += 2) {
    if (s[i] == 'a') {
      if (s[i+1] == 'a') return false;
    } else if (s[i] == 'b') {
      if (s[i+1] == 'b') return false;
    }
  }
  return true;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    int x,y;
    scanf("%d", &n);
    string s;
    cin>>s;
    bool ok = true;
    if (n%2) {
      if (s[0] == 'b') {
        ok=false;
      } else {
        ok=check(s, 1);
      }
    } else {
      ok = check(s, 0);
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}

