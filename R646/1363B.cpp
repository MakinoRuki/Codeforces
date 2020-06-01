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
#define N 1002
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    int zn = 0, on = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') zn++;
      else on++;
    }
    int ans=min(on, zn);
    int zc=0, oc=0;
    for (int i = 0; i < n-1; ++i) {
      if (s[i]=='0')zc++;
      else oc++;
      ans = min(ans, oc+zn-zc);
      ans = min(ans, zc+on-oc);
    }
    cout<<ans<<endl;
  }
  return 0;
}
