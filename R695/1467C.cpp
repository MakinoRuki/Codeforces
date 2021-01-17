#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 300002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n1,n2,n3;
vector<vector<int>> bs;
int main() {
  cin>>n1>>n2>>n3;
  bs.clear();
  ll s1=0,s2=0,s3=0;
  ll tot=0LL;
  vector<int> tmp;
  tmp.clear();
  for (int i = 1; i <= n1; ++i) {
    int x;
    scanf("%d", &x);
    tmp.push_back(x);
    tot += x;
    s1+=x;
  }
  bs.push_back(tmp);
  tmp.clear();
  for (int i = 1; i <= n2; ++i) {
    int x;
    scanf("%d", &x);
    tmp.push_back(x);
    tot += x;
    s2+=x;
  }
  bs.push_back(tmp);
  tmp.clear();
  for (int i = 1; i <= n3; ++i) {
    int x;
    scanf("%d", &x);
    tmp.push_back(x);
    tot += x;
    s3 += x;
  }
  bs.push_back(tmp);
  for (int i = 0; i < 3; ++i) {
    sort(bs[i].begin(), bs[i].end());
  }
  ll ans = tot - 2LL*s1;
//  cout<<ans<<endl;
  ans = max(ans, tot-2LL*s2);
  //cout<<ans<<endl;
  ans = max(ans, tot-2LL*s3);
 // cout<<ans<<endl;
 // cout<<"x="<<bs[0][0]<<" "<<bs[1][0]<<endl;
  for (int i = 0; i < 3; ++i) {
    ll cur=(ll)bs[i][0]+(ll)bs[(i+1)%3][0];
    ans=max(ans, tot-2LL*cur);
   // cout<<i<<" "<<ans<<endl;
  }
  printf("%lld\n", ans);
  return 0;
}
