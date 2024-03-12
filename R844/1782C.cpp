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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      string s;
      cin>>s;
      for (int i = 0; i <= 26; ++i) {
          cnt[i] = 0;
      }
      for (int i = 0; i < n; ++i) {
          cnt[s[i]-'a']++;
      }
      vector<pair<int,int>> v;
      v.clear();
      for (int i = 0; i < 26; ++i) {
          if (cnt[i]) {
              v.push_back(make_pair(cnt[i], i));
          }
      }
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      int ans=inf;
      int num=-1;
      for (int i = 1; i <= 26; ++i) {
          if (n % i) continue;
          if (n < i) continue;
          int x = n/i;
          int tot=0;
          for (int j = 0; j < min(i, (int)v.size()); ++j) {
              tot += min(x, v[j].first);
          }
          if (n-tot<ans) {
              ans=n-tot;
              num=i;
          }
      }
      for (int i = 0; i <= 26; ++i) {
          cnt[i]=0;
      }
      set<int> ss;
      ss.clear();
      for (int j = 0; j < min(num, (int)v.size()); ++j) {
          ss.insert(v[j].second);
      }
      for (int i = 0; i < 26; ++i) {
          if (ss.size() >= num) break;
          if (ss.find(i) == ss.end()) {
              ss.insert(i);
          }
      }
      vector<int> ids;
      ids.clear();
      for (int i = 0; i < n; ++i) {
          int c=s[i]-'a';
          if (ss.find(c) == ss.end() || cnt[c] >= n/num) {
              ids.push_back(i);
          } else {
              cnt[c]++;
          }
      }
      for (auto id : ids) {
          for (auto c : ss) {
              if (cnt[c] < n/num) {
                  s[id] = 'a'+c;
                  cnt[c]++;
                  break;
              }
          }
      }
      printf("%d\n", ans);
      cout<<s<<endl;
  }
  return 0;
}
