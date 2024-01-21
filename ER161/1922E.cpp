#include <iostream>
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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll x;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld", &x);
    int pw = 0;
    while((1LL<<pw) <= x) {
      pw++;
    }
    pw--;
    vector<int> ans;
    ans.clear();
    for (int i = 0; i < pw; ++i) {
      ans.push_back(i);
    }
    x -= (1LL<<pw);
    for (int i = 60; i >= 0; --i) {
      if ((1LL<<i) & x) {
        ans.push_back(i);
      }
    }
    int sz=(int)ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
