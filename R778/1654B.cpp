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
#include <random>
#include <ctime>
#define M 10000002
#define N 1002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int cnt[26];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i]-'a']++;
    }
    int id = 0;
    while(id < s.size()) {
      if (cnt[s[id]-'a'] > 1) {
        cnt[s[id]-'a']--;
        id++;
      } else {
        break;
      }
    }
    string ans = s.substr(id);
    cout<<ans<<endl;
  }
  return 0;
}
