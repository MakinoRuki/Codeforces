#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 7005
using namespace std;
typedef long long ll;
int n;
ll a[N];
ll b[N];
// void print(ll x) {
// 	for (int i = 59; i >= 0; --i) {
// 		if ((1LL<<i) & x) cout<<1;
// 		else cout<<0;
// 	}
// 	cout<<endl;
// }
int main() {
	cin>>n;
	unordered_map<ll, int> cnt1;
	unordered_map<ll, int> cnt2;
	unordered_map<ll, ll> val;
	cnt1.clear();
	cnt2.clear();
	val.clear();
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		cnt1[a[i]]++;
	}
	for (int i = 1; i <= n; ++i) {
		cin>>b[i];
		val[a[i]] += b[i];
	}
	vector<ll> bits;
	bits.clear();
	for (auto v = cnt1.begin(); v != cnt1.end(); ++v) {
		bits.push_back(v->first);
		if (v->second >= 2) {
			cnt2[v->first] = 1;
		}
	}
	sort(bits.begin(), bits.end());
	// for (int i = 0; i < bits.size(); ++i) {
	// 	cout<<"xxx"<<i<<" "<<bits[i]<<endl;
	// }
	// for (int i = 0; i < bits.size(); ++i) {
	// 	ll st = bits[i];
	// 	//cout<<"yyy"<<i<<" "<<st<<endl;
	// 	for (int j = 0; j < 60; ++j) {
	// 		if ((1LL<<j) & st) continue;
	// 		if (cnt1.find(st|(1LL<<j)) != cnt1.end()) {
	// 			//cout<<st<<" "<<(st|(1<<j))<<endl;
	// 		//	cout<<"zzz"<<j<<" "<<(st|(1LL<<j))<<endl;
	// 			cnt2[st|(1LL<<j)] += cnt2[st];
	// 			val[st|(1LL<<j)] += val[st];
	// 		}
	// 	}
	// }
	for (int i =bits.size()-1; i >= 0; --i) {
		ll st = bits[i];
		for (int j = i + 1; j < bits.size(); ++j) {
			ll res = bits[i] ^ bits[j];
			if ((res | bits[i]) == bits[j] && cnt2[bits[j]]) {
				cnt2[st] =1 ;
			}
		}
	}
	ll ans = 0;
	int cnt=0;
	for (int i = 0; i < bits.size(); ++i) {
		ll st = bits[i];
		if (cnt2[st]) {
			ans += val[st];
			cnt += cnt1[st];
		}
	}
	// for (int i = 0; i < bits.size(); ++i) {
	// 	ll st = bits[i];
	// 	if (cnt2[st] || cnt1[st]>=2) {
	// 		ans += val[st];
	// 		cnt += cnt1[st];
	// 	}
	// 	//if (cnt1[st] <= 1) continue;
	// 	// bool found = false;
	// 	// //cout<<i<<" "<<bits[i]<<endl;
	// 	// for (int j = 0; j < 60; ++j) {
	// 	// 	if ((1LL<<j) & st) continue;
	// 	// 	if (cnt1[st|(1LL<<j)] >= 2) {
	// 	// 		found = true;
	// 	// 		break;
	// 	// 	}
	// 	// }
	// 	// if (found) {
	// 	// 	ans += val[st];
	// 	// 	cnt += cnt1[st];
	// 	// } else {
	// 	// 	if (cnt1[st] >= 2) {
	// 	// 		ans += val[st];
	// 	// 		cnt += cnt1[st];
	// 	// 	}
	// 	// }
	// 	// if (!found) {
	// 	// //	cout<<"***"<<i<<" "<<bits[i]<<endl;
	// 	// 	ans += val[st];
	// 	// 	cnt += cnt2[st];
	// 	// }
	// }
	if (cnt >= 2) {
		cout<<ans<<endl;
	} else {
		cout<<0<<endl;
	}
	return 0;
}
