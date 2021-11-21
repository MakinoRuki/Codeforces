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
#define M 52
#define N 702
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q, p;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    bool found = false;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0' && s[i-1] == '1') {
        found=true;
        break;
      }
    }
    if (!found) {
      puts("0");
    } else {
      for (int i = 0; i < n; ++i) {
        vector<int> ids;
        ids.clear();
        for (int j = 0; j < n; ++j) {
          if (j <= i && s[j] == '1') {
            ids.push_back(j);
          } else if (j > i && s[j] == '0') {
            ids.push_back(j);
          }
        }
        string t = s;
        // if (i == 2) {
        //   for (int j = 0; j < ids.size(); ++j) {
        //     cout<<j<<" "<<ids[j]<<endl;
        //   }
        // }
        int l = 0, r = ids.size()-1;
        while(l < r) {
          swap(t[ids[l]], t[ids[r]]);
          l++;
          r--;
        }
       // cout<<t<<endl;
        bool found = false;
        for (int j = 1; j < n; ++j) {
          if (t[j] == '0' && t[j-1] == '1') {
            found=true;
            break;
          }
        }
        if (!found) {
          puts("1");
          printf("%d", (int)ids.size());
          for (int j = 0; j < ids.size(); ++j) {
            printf(" %d", ids[j]+1);
          }
          cout<<endl;
          break;
        }
      }
    }
  }
  return 0;
}
