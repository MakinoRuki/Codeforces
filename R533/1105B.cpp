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
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,k;
string s;
int main() {
  cin>>n>>k;
  cin>>s;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  int sum=0;
  for (int i = 0; i < n; ++i) {
    if (i==0 || s[i]==s[i-1]) sum++;
    else {
      cnt[s[i-1]-'a']+=sum/k;
      sum = 1;
    }
  }
  cnt[s.back()-'a']+=sum/k;
  int ans=0;
  for (int i = 0; i < 26; ++i) {
    ans = max(ans, cnt[i]);
  }
  cout<<ans<<endl;
  return 0;
}
