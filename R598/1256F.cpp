#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int q, n;
string s, t;
int main() {
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    cin>>n>>s>>t;
    string ss=s;
    string tt=t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if (ss != tt) {
      cout<<"NO"<<endl;
    } else {
      int i;
      for (i = 1; i < ss.size(); ++i) {
        if (ss[i] == ss[i-1]) {
          break;
        }
      }
      if (i < ss.size()) {
        cout<<"YES"<<endl;
        continue;
      }
      int invs = 0;
      int invt = 0;
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (s[j] > s[i]) invs ^= 1;
          if (t[j] > t[i]) invt ^= 1;
        }
      }
      if (invs == invt) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}
