#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 8002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    if (n <= 3) {
      cout<<-1<<endl;
    } else if ( n == 4) {
      cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;
    } else if (n == 5) {
      cout<<1<<" "<<3<<" "<<5<<" "<<2<<" "<<4<<endl;
    } else {
      vector<int> ans;
      ans.clear();
      int pre=1;
      ans.push_back(1);
      while(true) {
        if (pre >= n) break;
        if (n-pre==5 || (n-pre)>=10) {
          pre += 3;
          ans.push_back(pre);
          pre -= 2;
          ans.push_back(pre);
          pre += 3;
          ans.push_back(pre);
          pre -= 2;
          ans.push_back(pre);
          pre += 3;
          ans.push_back(pre);
        } else {
          if (n-pre==9) {
            vector<int> ds={3,-2,3,-2,4,3,-2,-2,3};
            for (int i = 0; i < ds.size(); ++i) {
              pre += ds[i];
              ans.push_back(pre);
            }
            pre += 9;
          } else if (n-pre == 8) {
            vector<int> ds={3,-2,3,-2,4,2,-3,2};
            for (int i = 0; i < ds.size(); ++i) {
              pre += ds[i];
              ans.push_back(pre);
            }
            pre += 8;
          } else if (n- pre == 7) {
            vector<int> ds= {3,-2,3,3,-2,-3,4};
            for (int i = 0; i < ds.size(); ++i) {
              pre += ds[i];
              ans.push_back(pre);
            }
            pre += 7;
          } else if (n-pre == 6) {
            vector<int> ds= {3,-2,3,2,-4,3};
            for (int i = 0; i < ds.size(); ++i) {
              pre += ds[i];
              ans.push_back(pre);
            }
            pre += 6;
          }
        }
      }
      for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i];
        if (i < ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
