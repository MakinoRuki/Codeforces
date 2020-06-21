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
#define N 200005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
string s,t;
int main() {
  cin>>n>>s>>t;
  int tot=0;
  int maxv = 0, minv = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i]=='0' && t[i]=='1') {
      tot++;
    } else if (s[i]=='1' && t[i]=='0') {
      tot--;
    }
    if (tot>0) maxv=max(maxv, tot);
    else minv = min(minv, tot);
  }
  if (tot != 0) {
    cout<<-1<<endl;
  } else {
    int ans=abs(maxv)+abs(minv);
    cout<<ans<<endl;
  }
  return 0;
}
