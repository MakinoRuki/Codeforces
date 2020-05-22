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
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int cnt[26];
int main() {
  cin>>n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    cnt[s[0]-'a']++;
  }
  int ans=0;
  for (int i = 0; i < 26; ++i) {
    int num = cnt[i];
    if (num % 2) {
      int n1 = num/2;
      int n2 = num/2+1;
      if (n1) ans += n1*(n1-1)/2;
      if (n2) ans += n2*(n2-1)/2;
    } else {
      int n1 = num/2;
      if (n1) ans += n1*(n1-1)/2*2;
    }
  }
  cout<<ans<<endl;
  return 0;
}
