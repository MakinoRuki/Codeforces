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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<pair<int,int>> ab;
int main() {
  cin>>n;
  ab.clear();
  ab.push_back(make_pair(0,0));
  ll ans=1LL;
  for (int i = 1; i <= n; ++i) {
    int a,b;
    scanf("%d%d", &a,&b);
    ab.push_back(make_pair(a,b));
  }
  for (int i = 1; i <= n; ++i) {
    if (ab[i-1].first==ab[i-1].second) {
      ans += min(ab[i].first, ab[i].second)-ab[i-1].first;
    } else {
      if (min(ab[i].first, ab[i].second) >= max(ab[i-1].first, ab[i-1].second)) {
        ans += min(ab[i].first, ab[i].second)-max(ab[i-1].first,ab[i-1].second)+1;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
