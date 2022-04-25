#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <set>
#include <list>
#include <random>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    vector<int> id0, id1;
    id0.clear();
    id1.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        id0.push_back(i);
      } else {
        id1.push_back(i);
      }
    }
    string ans="";
    int n0 = (int)id0.size();
    int n1 = (int)id1.size();
    vector<int> ops(n, 0);
    if (k % 2) {
      if (k <= n1) {
        for (int i = 0; i < n; ++i) {
          if (s[i] == '0') {
            ans.push_back('1');
          } else {
            if (k>0) {
              ans.push_back('1');
              ops[i]++;
              k--;
            } else ans.push_back('0');
          }
        }
      } else {
        int dt = (k-n1);
        if (dt % 2 == 0) {
          ans = string(n, '1');
          for (int i = 0; i <id1.size(); ++i) {
            ops[id1[i]]++;
          }
          ops[n-1] += dt;
        } else {
          ans = string(n-1, '1') + string(1, '0');
          for (int i = 0; i < id1.size(); ++i) {
            ops[id1[i]]++;
          }
          ops[n-1] += dt;
        }
      }
    } else {
      if (k <= n0) {
        for (int i = 0; i < n; ++i) {
          if (s[i] == '1') {
            ans.push_back('1');
          } else {
            if (k>0) {
              k--;
              ans.push_back('1');
              ops[i]++;
            } else ans.push_back('0');
          }
        }
      } else {
        int dt = (k-n0);
        if (dt % 2 == 0) {
          ans = string(n, '1');
          for (int i = 0; i <id0.size(); ++i) {
            ops[id0[i]]++;
          }
          ops[n-1] += dt;
        } else {
          ans = string(n-1, '1') + string(1, '0');
          for (int i = 0; i < id0.size(); ++i) {
            ops[id0[i]]++;
          }
          ops[n-1] += dt;
        }
      }
    }
    cout<<ans<<endl;
    for (int i = 0; i < n; ++i) {
      printf("%d", ops[i]);
      if (i < n-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
