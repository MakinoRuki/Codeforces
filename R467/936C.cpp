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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s,t;
int cnt[26];
int main() {
  cin>>n>>s>>t;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) {
    cnt[s[i]-'a']++;
  }
  for (int i = 0; i < n; ++i) {
    cnt[t[i]-'a']--;
    if (cnt[t[i]-'a']<0) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]!=0) {
      puts("-1");
      return 0;
    }
  }
  vector<int> ans;
  ans.clear();
  int id=0;
  int cur=n/2+1;
  for (int i = n; i >= 1; --i) {
    if (s[i-1]==t[cur-1]) {
      id = i;
      break;
    }
  }
  if (id != n) {
    ans.push_back(n-id);
    string ts= s.substr(id);
    reverse(ts.begin(), ts.end());
    s = ts+s.substr(0, id);
  }
  for (int d = 1; d < n; ++d) {
    if (d%2) cur -= d;
    else cur += d;
    int i;
    for (i = n-d; i >= 1; --i) {
      if (s[i-1]==t[cur-1]) {
        break;
      }
    }
    ans.push_back(n-i);
    string ts=s.substr(i);
    reverse(ts.begin(), ts.end());
    s = ts+s.substr(0, i);
    ans.push_back(1);
    s = s.substr(n-1) + s.substr(0, n-1);
    if (n-(d+1) > 0) {
      ans.push_back(n-(d+1));
      ts = s.substr(d+1);
      reverse(ts.begin(), ts.end());
      s = ts+s.substr(0,d+1);
    }
  }
  if (s != t) {
    ans.push_back(n);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i<ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
