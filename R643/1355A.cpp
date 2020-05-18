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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll a1, k;
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%lld%lld", &a1, &k);
    for (int i = 1; i < k; ++i) {
      ll x= a1;
      vector<int> ds;
      ds.clear();
      while(x) {
        ds.push_back(x%10);
        x/=10;
      }
      sort(ds.begin(), ds.end());
      if (ds[0] == 0) break;
      a1 += (ll)ds[0]*(ll)ds.back();
    }
    cout<<a1<<endl;
  }
  return 0;
}
