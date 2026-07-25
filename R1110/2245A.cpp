
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
const int base=337;

int n, m, q;
int k, w;
int t;
ll a[N];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    int cnt=0;
    int ans=0;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == 'L') cnt++;
      else {
        if (cnt >= k) break;
        else {
          s[i] = 'L';
          ans++;
          cnt++;
        }
      }
    }
    cnt=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'R') cnt++;
      else {
        if (cnt >= k) break;
        else {
          s[i] = 'R';
          ans++;
          cnt++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        cnt=0;
        for (int j = 0; j < i; ++j) if (s[j] == 'R')cnt++;
        if (cnt < k) {
          ans=-1;
          break;
        }
      } else {
        cnt=0;
        for (int j = i+1; j < n; ++j) if (s[j] == 'L') cnt++;
        if (cnt < k) {
          ans=-1;
          break;
        }
      }
      if (ans<0) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
