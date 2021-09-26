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
#define M 30
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
string s;
int main() {
  cin>>n;
  cin>>s;
  int det = 0;
  int x=0,y=0;
  int ans=0;
  vector<int> v;
  v.clear();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      y++;
    } else {
      x++;
    }
    v.push_back(x-y);
  }
  for (int i = 1; i < v.size(); ++i) {
    if (i-1>=0 && i+1<v.size()) {
      if (v[i-1]<0 && v[i+1]>0) {
        ans++;
      } else if (v[i-1]>0 && v[i+1]<0) {
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
