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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    vector<pair<int,int>> sg;
    sg.clear();
    int id = -1;
    int ans=0;
    for (int i = 0; i < n; ++i) {
    //  cout<<"i="<<i<<" "<<s1[i]<<
      if (s1[i] == '0' && s2[i] == '0') {
        ans++;
        // if (id >= 0) {
        //   sg.push_back(make_pair(id, i-1));
        //   id = -1;
        // }
      } else if (s1[i] == '1' && s2[i] == '1') {
        if (i-1>=0 && s1[i-1]=='0' && s2[i-1]=='0'&&id != i-1) {
          ans++;
          id = i-1;
        } else {
          if (i+1<n && s1[i+1]=='0' && s2[i+1]=='0'&& id!=i+1) {
            ans++;
            id=i+1;
          }
        }
      } else {
        ans+=2;
      //  cout<<i<<" "<<ans<<endl;
        // if (id >= 0) {
        //   sg.push_back(make_pair(id, i-1));
        //   id=-1;
        // }
      }
    }
    // if (id >= 0) {
    //   sg.push_back(make_pair(id, n-1));
    // }
    // for (int i = 0; i < sg.size(); ++i) {
    //   int l = sg[i].first;
    //   int r = sg[i].second;
    //   if (r-l+1>1) {
    //     if (l-1>=0 && s1[l-1] == '0' && s2[l-1] == '0') {
    //       ans++;
    //     }
    //     if (r+1 < n && s1[r+1] == '0' && s2[r+1] == '0') {
    //       ans++;
    //     }
    //   } else {
    //     if ((l-1>=0&&s1[l-1]=='0'&&s2[l-1]=='0') || (r+1<n&&s1[r+1]=='0'&&s2[r+1]=='0')) {
    //       ans++;
    //     }
    //   }
    // }
    // for (int i = 0; i < n; ++i) {
    //   if (s1[i] == '0' && s2[i] == '0') {
    //     if (i-1>=0 && s1[i-1]=='1' && s2[i-1]=='1') {
    //       if (i+1<n && s1[i+1]=='1' && s2[i+1]=='1') {
    //         ans--;
    //       }
    //     }
    //   }
    // }
    printf("%d\n", ans);
  }
  return 0;
}
