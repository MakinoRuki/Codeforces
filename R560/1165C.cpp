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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
int idx[N];
int main() {
  cin>>n>>s;
  int ans=0;
  string res ="";
  for (int i = n-1; i >= 0; --i) {
    if (i == n-1) idx[i] = n;
    else {
      if (s[i] != s[i+1]) idx[i] = i+1;
      else idx[i] = idx[i+1];
    }
  }
  int i = 0;
  while(i < n) {
    if (idx[i] < n) {
      ans += idx[i]-i-1;
      res.push_back(s[i]);
      res.push_back(s[idx[i]]);
      i = idx[i]+1;
    } else {
      ans += n-i;
      break;
    }
  }
  cout<<ans<<endl;
  cout<<res<<endl;
  return 0;
}
