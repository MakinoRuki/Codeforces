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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string a,b;
    cin>>a>>b;
    if (a[0] == b[0]) {
      puts("YES");
      string s = a.substr(0, 1);
      s += "*";
      cout<<s<<endl;
    } else if (a.back() == b.back()) {
      puts("YES");
      string s = "*" + a.substr(a.size()-1, 1);
      cout<<s<<endl;
    } else {
      string x = "";
      for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
          if (i + 1 < a.size() && j + 1 < b.size() && a[i] == b[j] && a[i+1] == b[j+1]) {
            x.push_back(a[i]);
            x.push_back(a[i+1]);
            break;
          }
        }
        if (!x.empty()) break;
      }
      if (!x.empty()) {
        puts("YES");
        x = "*" + x + "*";
        cout<<x<<endl;
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}
