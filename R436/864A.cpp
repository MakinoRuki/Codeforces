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
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int main() {
	map<int,int> ss;
	cin>>n;
	for (int i = 1;  i<= n; ++i) {
		scanf("%d", &a[i]);
		ss[a[i]]++;
	}
		if (ss.size()!=2) {
			cout<<"NO"<<endl;
		} else {
			auto itr=ss.begin();
			auto itr2=itr;
			itr2++;
			if (itr->second != itr2->second) {
				cout<<"NO"<<endl;
			} else {
				cout<<"YES"<<endl;
				cout<<itr->first<<" "<<itr2->first<<endl;
			}
		}
	return 0;
}
