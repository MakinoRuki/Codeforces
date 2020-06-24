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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n,t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    string ans="";
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == '0') ans.push_back(s[i]);
      else {
        bool found=false;
        while(!ans.empty() && ans.back()=='0') {
          ans.pop_back();
          found=true;
        }
        if (!found) {
          ans.push_back(s[i]);
        } else {
          ans.push_back('0');
        }
      }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
  }
  return 0;
}
