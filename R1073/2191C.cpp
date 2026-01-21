

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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 1000005
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<vector<int>> v;
    v.clear();
    vector<int> ids;
    ids.clear();
    int cc=0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        cc = s[i]-'0';
        if (i == 0) ids.push_back(cc);
        ids.push_back(i);
      } else {
        v.push_back(ids);
        cc = s[i]-'0';
        ids.clear();
        ids.push_back(cc);
        ids.push_back(i);
      }
    }
    if (!ids.empty()) v.push_back(ids);
    int sz=(int)v.size();
    if (sz == 1) {
      puts("Bob");
      continue;
    }
    if (sz == 2) {
      if (v[0][0] == 0) {
        puts("Bob");
      } else {
        puts("Alice");
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i) {
          printf("%d ", i);
        }
        cout<<endl;
      }
    } else {
      puts("Alice");
      int tot=0;
      vector<int> ans;
      ans.clear();
      string s2= s;
      sort(s2.begin(), s2.end());
      for (int i = 0; i < n; ++i) {
        if (s[i] != s2[i]) {
          ans.push_back(i+1);
        }
      }
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    }
  }
  
  return 0;
}

