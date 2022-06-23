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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
vector<string> ss;
int cnt[26];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < 26; ++i) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= 2*n+1; ++i) {
      string s;
      cin>>s;
      for (int j = 0; j < s.size(); ++j) {
        cnt[s[j]-'a']++;
      }
    }
    string ans="";
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2) {
        ans.push_back('a'+i);
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
