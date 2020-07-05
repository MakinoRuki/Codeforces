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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    string ans="";
    for (int last = 0; last <= 9; ++last) {
      for (int nn = 0; nn <= 19; ++nn) {
        string res="";
        res.push_back(last+'0');
        if (nn>0) res += string(nn, '9');
        int m=n;
        for (int i = 0; i <= k; ++i) {
          if (last+i>9) {
            m -= (last+i)%10;
            m -= 1;
          } else {
            m -= last+i+nn*9;
          }
        }
       // if (last==8&&nn==4) cout<<"m="<<m<<endl;
        if (m<0) continue;
        if (m%(k+1)!=0) continue;
        m /= (k+1);
        if (m) res.push_back(min(8, m)+'0');
        m -= min(8, m);
        while(m) {
          res.push_back(min(9,m)+'0');
          m -= min(9,m);
        }
        reverse(res.begin(), res.end());
        if (ans.empty() || ans.size()>res.size() || (ans.size()==res.size() && ans>res)) {
          ans = res;
        }
      }
    }
    if (ans.empty()) cout<<-1<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}
