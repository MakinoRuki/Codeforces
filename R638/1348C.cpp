#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#define N 105
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    string ans="";
    int cnt=0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i]==s[0]) cnt++;
      else break;
    }
    if (cnt < k) {
      cout<<s.substr(k-1,1)<<endl;
    } else {
      ans.push_back(s[0]);
      if (s.back()==s[k]) {
        int rem = (n-1)/k;
        for (int i = 1; i <= rem; ++i) {
          ans.push_back(s[k]);
        }
      } else {
        ans += s.substr(k);
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}
