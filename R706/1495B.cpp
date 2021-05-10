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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int p[N];
int us[N][2];
int ds[N][2];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	memset(us, -1, sizeof(us));
	memset(ds, -1, sizeof(ds));
	for (int i = 1; i <= n; ++i) {
		ds[i][0]=0;
		if (i-1>=1 && p[i]>p[i-1]) {
			ds[i][0] = ds[i-1][0]+1;
		}
	}
	for (int i = n; i >= 1; --i) {
		ds[i][1]=0;
		if (i+1<=n && p[i]>p[i+1]) {
			ds[i][1] = ds[i+1][1]+1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		us[i][0]=0;
		if (i-1>=1 && p[i]<p[i-1]) {
			us[i][0]=us[i-1][0]+1;
		}
	}
	for (int i = n; i >= 1; --i) {
		us[i][1]=0;
		if (i+1<=n && p[i]<p[i+1]) {
			us[i][1]=us[i+1][1]+1;
		}
	}
	multiset<int> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		if (us[i][0]>0) {
			ss.insert(us[i][0]);
		}
		if (us[i][1]>0) {
			ss.insert(us[i][1]);
		}
	//	cout<<"i="<<i<<" "<<us[i][0]<<" "<<us[i][1]<<endl;
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
	//	cout<<i<<" "<<ss.size()<<endl;
		if (ds[i][0]>0 && ds[i][1]>0) {
			int l = i-ds[i][0];
			int r = i+ds[i][1];
			if (us[l][0]>0) ss.erase(ss.find(us[l][0]));
			if (us[l][1]>0) ss.erase(ss.find(us[l][1]));
			if (us[r][0]>0) ss.erase(ss.find(us[r][0]));
			if (us[r][1]>0) ss.erase(ss.find(us[r][1]));
			// if (i==3) cout<<ds[i][0]<<" "<<ds[i][1]<<" "<<ss.size()<<endl;
			// if (i==3) {
			// 	for (auto itr : ss) {
			// 		cout<<"x="<<(itr)<<endl;
			// 	}
			// }
			if (!ss.empty() && (*ss.rbegin())>=max(ds[i][0], ds[i][1])) {
				if (us[l][0]>0) ss.insert(us[l][0]);
			if (us[l][1]>0) ss.insert(us[l][1]);
			if (us[r][0]>0) ss.insert(us[r][0]);
			if (us[r][1]>0) ss.insert(us[r][1]);
				continue;
			}
		//	bool ok=true;
		//	if (i==3) cout<<ds[i][0]<<" "<<ds[i][1]<<" "<<l<<" "<<us[l][0]<<" "<<us[l][1]<<" "<<r<<" "<<us[r][0]<<" "<<us[r][1]<<endl;
			if ((us[l][0]<ds[i][0]&&(ds[i][0]%2==0))||max(us[l][0],us[l][1])<ds[i][1]) {
				if ((us[r][1]<ds[i][1]&&(ds[i][1]%2==0))||max(us[r][0],us[r][1])<ds[i][0]) {
			//		if (i==3) cout<<"??"<<endl;
					bool ok=true;
					if (ds[i][0]%2==0) {
						if (ds[i][1]<=ds[i][0]-1) {
							ok=false;
						}
					}
					if (ds[i][1]%2==0) {
						if (ds[i][0]<=ds[i][1]-1) {
							ok=false;
						}
					}
				//	if (i==5) cout<<"ok="<<ok<<endl;
					if (ok) ans++;
				}
			}


			if (us[l][0]>0) ss.insert(us[l][0]);
			if (us[l][1]>0) ss.insert(us[l][1]);
			if (us[r][0]>0) ss.insert(us[r][0]);
			if (us[r][1]>0) ss.insert(us[r][1]);
		}
		// else if (ds[i][0]>0) {
		// 	int l = i-ds[i][0];
		// 	if (us[l][0]>0) ss.erase(ss.find(us[l][0]));
		// 	if (us[l][1]>0) ss.erase(ss.find(us[l][1]));
		// 	if (!ss.empty() && (*ss.rbegin())>=max(ds[i][0], ds[i][1])) {
		// 		if (us[l][0]>0) ss.insert(us[l][0]);
		// 	if (us[l][1]>0) ss.insert(us[l][1]);
		// 		continue;
		// 	}
		// 	if ((us[l][0]<ds[i][0]&&(ds[i][0]%2==0))) {

		// 		ans++;
		// 	}
		// 	if (us[l][0]>0) ss.insert(us[l][0]);
		// 	if (us[l][1]>0) ss.insert(us[l][1]);
		// } else if (ds[i][1]>0) {
		// 	int r = i-ds[i][1];
		// 	if (us[r][0]>0) ss.erase(ss.find(us[r][0]));
		// 	if (us[r][1]>0) ss.erase(ss.find(us[r][1]));
		// 	if (!ss.empty() && (*ss.rbegin())>=max(ds[i][0], ds[i][1])) {
		// 		if (us[r][0]>0) ss.insert(us[r][0]);
		// 	if (us[r][1]>0) ss.insert(us[r][1]);
		// 		continue;
		// 	}
		// 	if ((us[r][1]<ds[i][1]&&(ds[i][1]%2==0))) {
		// 		ans++;
		// 	}
		// 	if (us[r][0]>0) ss.insert(us[r][0]);
		// 	if (us[r][1]>0) ss.insert(us[r][1]);
		// }
	}
	cout<<ans<<endl;
  return 0;
}
