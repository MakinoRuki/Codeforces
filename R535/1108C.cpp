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
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
int solve(string& t, char a, char b, char c) {
  int tot=0;
  for (int i = 0; i < n; ++i) {
    if (i%3==0 && t[i] != a) {
      tot++;
      t[i]=a;
    } else if (i%3==1 && t[i] != b) {
      tot++;
      t[i]=b;
    } else if (i%3==2 && t[i] != c) {
      tot++;
      t[i] = c;
    }
  }
  return tot;
}
int main() {
  cin>>n>>s;
  if (n==1) {
    cout<<0<<endl;
    cout<<s<<endl;
    return 0;
  }
  if (n==2) {
    if (s[0]==s[1]) {
      cout<<1<<endl;
      if (s[0]=='R') s[1] = 'G';
      else if (s[0] == 'G') s[1] = 'B';
      else s[1] = 'R';
      cout<<s<<endl;
    } else {
      cout<<0<<endl;
      cout<<s<<endl;
    }
    return 0;
  }
  string ans;
  string t = s;
  int res = solve(t, 'R', 'G', 'B');
  ans=t;
  t = s;
  int res2 = solve(t, 'R', 'B', 'G');
  if (res2<res) {
    res=res2;
    ans=t;
  }
  t = s;
  res2 = solve(t, 'B', 'R', 'G');
  if (res2<res) {
    res=res2;
    ans=t;
  }
  t=s;
  res2=solve(t, 'B', 'G', 'R');
  if (res2<res) {
    res=res2;
    ans=t;
  }
  t=s;
  res2=solve(t, 'G', 'R', 'B');
  if (res2<res){
    res=res2;
    ans=t;
  }
  t=s;
  res2=solve(t, 'G', 'B', 'R');
  if (res2<res) {
    res=res2;
    ans=t;
  }
  cout<<res<<endl;
  cout<<ans<<endl;
  return 0;
}
