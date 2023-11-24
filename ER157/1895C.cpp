#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
ll ans;
int cnt[12][100];
int main() {
  cin>>n;
  vector<string> sv;
  sv.clear();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    sv.push_back(s);
    int len = (int)s.size();
    int sum=0;
    for (int j = 0; j < len; ++j) {
      sum += s[j]-'0';
    }
    cnt[len][sum]++;
  }
  ll ans = 0LL;
  for (int i = 2; i <= 10; i += 2) {
    for (int j = 0; j < sv.size(); ++j) {
      int len = sv[j].size();
      if (len >= i/2 && len < i) {
        int sum = 0;
        int sum2 = 0;
        for (int k = 0; k < i/2; ++k) {
          sum += sv[j][k]-'0';
        }
        for (int k = i/2; k < sv[j].size(); ++k) {
          sum2 += sv[j][k] - '0';
        }
        if (sum - sum2 >= 0) ans += cnt[i-len][sum-sum2];
      }
      if (len > i/2 && len < i) {
        int sum=0;
        int sum2=0;
        for (int k = 0; k < len - i/2; ++k) {
          sum2 += sv[j][k]-'0';
        }
        for (int k = len-i/2; k < len; ++k) {
          sum += sv[j][k]-'0';
        }
        if (sum-sum2 >= 0) ans += cnt[i-len][sum-sum2];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
