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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int b[N];
bool solve(vector<pair<pair<int,int>, int>>& rk, int id, vector<int>& ans) {

  for (int i = id; i < rk.size() - 1; ++i) {
    if (rk[i].second == 0) {
      continue;
    }
    if (i+1<rk.size()) {
      if (rk[i+1].first.second % 2) {
        return false;
      }
      for (int j = rk[i].first.first + rk[i].first.second-1;;) {
        if (j+1<=n && a[j+1] == 0) {
          ans.push_back(j);
          a[j+1]=1;
          a[j+2]=1;
          j += 2;
        } else {
          break;
        }
      }
    }
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    //  a[i] = rand()%2;
      b[i] = a[i];
    }
    // cout<<"a=";
    // for (int i =1 ; i <= n; ++i) {
    //   cout<<" "<<a[i];
    // }
    // cout<<endl;
    vector<pair<pair<int,int>, int>> rk;
    rk.clear();
    vector<int> ans;
    ans.clear();
    int cnt = 0;
    int i = 1;
    while(i <= n) {
      if (a[i] == 1) {
        cnt++;
        i++;
      } else {
        if (cnt % 2 == 0) {
          cnt=0;
          i++;
        } else {
          int j = i-1;
          while(j + 2 <= n && !a[j+1] && !a[j+2]) {
            a[j+1]=1;
            a[j+2] = 1;
            ans.push_back(j);
            j += 2;
            cnt += 2;
          }
          if (j + 1 > n) {
            break;
          } else {
            if (j + 2 > n) {
              if (a[j+1]) {
                cnt++;
              }
              break;
            } else {
              if (a[j+1] == 0) {
                ans.push_back(j);
                a[j] = 0;
                a[j+2] = 0;
                j += 2;
                cnt = 0;
                i = j;
              } else {
                i = j+1;
              }
            }
          }
        }
      }
    }


    cnt = 0;
    for (int i =1 ; i <= n; ++i) {
      cnt += a[i];
    }
    if ((cnt % 2) || cnt == n) {
      puts("NO");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) {
        if (i-2>=1 && a[i-1] == 1 && a[i-2] == 1) {
          int j = i;
          while(j-2>=1 && a[j-1] == 1 && a[j-2]==1) {
            ans.push_back(j-2);
            a[j-1]=0;
            a[j-2]=0;
            j -= 2;
          }
        }
        if (i+2<=n && a[i+1] ==1 && a[i+2] == 1) {
          ans.push_back(i);
          a[i+1]=0;
          a[i+2]=0;
        }
      }
    }
    puts("YES");
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
    // for (int i = 1; i <= n; ++i) {
    //   if (b[i] == 0) {
    //     if (i-2>=1 && b[i-1] == 1 && b[i-2] == 1) {
    //       int j = i;
    //       while(j-2>=1 && b[j-1] == 1 && b[j-2]==1) {
    //         ans.push_back(j-2);
    //         b[j-1]=0;
    //         b[j-2]=0;
    //         j -= 2;
    //       }
    //     }
    //     if (i+2<=n && b[i+1] ==1 && b[i+2] == 1) {
    //       ans.push_back(i);
    //       b[i+1]=0;
    //       b[i+2]=0;
    //     }
    //   }
    // }
    // bool found=false;
    // for (int i = 1; i <= n; ++i) {
    //   if (b[i] == 1) {
    //     found=true;
    //     break;
    //   }
    // }
    // cout<<"a=";
    // for (int i = 1; i <= n; ++i) {
    //   cout<<" "<<a[i];
    // }
    // cout<<endl;
    // if (!found) {
    //   puts("YES");
    //   printf("%d\n", (int)ans.size());
    //   for (int i = 0; i < ans.size(); ++i) {
    //     printf("%d", ans[i]);
    //     if (i < ans.size()-1) cout<<" ";
    //     else cout<<endl;
    //   }
    //   continue;
    // } else {
    //   ans.clear();
    // }
    // int id = -1;
    // int cnt=0;
    // for (int i = 1; i <= n; ++i) {
    //   if (i == 1 || a[i] == a[i-1]) {
    //     cnt++;
    //   } else {
    //     rk.push_back(make_pair(make_pair(i-cnt, cnt), a[i-1]));
    //     cnt = 1;
    //   }
    // }
    // if (cnt > 0) {
    //   rk.push_back(make_pair(make_pair(n+1-cnt, cnt), a[n]));
    // }
    // // for (int i = 0; i < rk.size(); ++i) {
    // //   cout<<"i="<<i<<" "<<rk[i].first
    // // }
    // for (int i = 0; i < rk.size(); ++i) {
    //   if (rk[i].second == 1) {
    //     if (i+2 < rk.size()) {
    //       int j = rk[i].first.first + rk[i].first.second - 1;
    //      // cout<<"j="<<j<<endl;
    //       while(j + 2 <= n && !a[j+1] && !a[j+2]) {
    //         ans.push_back(j);
    //         a[j+1]= 1;
    //         a[j+2] = 1;
    //         j += 2;
    //       }
    //     }
    //   }
    // }
    // rk.clear();
    // cnt=0;
    // for (int i = 1; i <= n; ++i) {
    //   if (i == 1 || a[i] == a[i-1]) {
    //     cnt++;
    //   } else {
    //     rk.push_back(make_pair(make_pair(i-cnt, cnt), a[i-1]));
    //     cnt = 1;
    //   }
    // }
    // if (cnt > 0) {
    //   rk.push_back(make_pair(make_pair(n+1-cnt, cnt), a[n]));
    // }
    // // for (int i = 1; i <= n; ++i) {
    // //   cout<<"i="<<i<<" "<<a[i]<<endl;
    // // }
    // for (int i = 0; i < rk.size(); ++i) {
    // //  cout<<"x="<<i<<" "<<rk[i].first.first<<" "<<rk[i].first.second<<" "<<rk[i].second<<endl;
    //   if (rk[i].second == 0 && rk[i].first.second == 1) {
    //     if (i-1>=0 && (rk[i-1].first.second % 2)) {
    //       if (i+1 < rk.size()) {
    //         ans.push_back(rk[i].first.first-1);
    //         int id = rk[i].first.first;
    //         a[id-1] = 0;
    //         a[id+1] = 0;
    //         rk[i-1].first.second--;
    //         rk[i+1].first.second--;
    //       }
    //     }
    //   }
    // }
    // // for (int i = 1; i <= n; ++i) {
    // //   cout<<"i2="<<i<<" "<<a[i]<<endl;
    // // }
    // cnt=0;
    // bool ok = true;
    // for (int i = 0; i < rk.size(); ++i) {
    //   if (rk[i].second == 1 && (rk[i].first.second % 2)) {
    //     ok=false;
    //     break;
    //   }
    // }
    // for (int i = 1; i <= n; ++i) {
    //   if (a[i] == 0) cnt++;
    // }
    // if (!ok || !cnt) {
    //   puts("NO");
    // } else {
    //   for (int i = 1; i <= n; ++i) {
    //     if (a[i] == 0) {
    //       if (i-1>=1 && a[i-1] == 1) {
    //         int j = i;
    //         while(j-1>=1 && a[j-1] == 1) {
    //           ans.push_back(j-2);
    //           a[j-1]=0;
    //           a[j-2]=0;
    //           j -= 2;
    //         }
    //       }
    //       if (i+1<=n && a[i+1] ==1) {
    //         ans.push_back(i);
    //         a[i+1]=0;
    //         a[i+2]=0;
    //       }
    //     }
    //   }
    //   puts("YES");
    //   printf("%d\n", (int)ans.size());
    //   for (int i = 0; i < ans.size(); ++i) {
    //     printf("%d", ans[i]);
    //     if (i < ans.size()-1) cout<<" ";
    //     else cout<<endl;
    //   }
    // }
  }
  return 0;
}
