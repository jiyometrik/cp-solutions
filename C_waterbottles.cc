#include <bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(x, start, end)                                                   \
	for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); \
			 ((start) < (end) ? x++ : x--))
#define each(i, v) for (auto i : (v))
#define fast()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define nl '\n'
#define pa pair
#define vc vector
#define dq deque
#define qu queue
#define pq priority_queue
#define mp map
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define sz(c) (ll)(c.size())
#define pub push_back
#define pob pop_back
#define mpr make_pair
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll q, a, c, t, f;

int main() {
	fast();

	cin >> q;

	qu<pa<ll, ll>> cus; // customers
	mp<ll, ll> ord;     // orders
	set<ll> gone;       // food items that have been sold out

	rep(w, 1, q + 1) {
		cin >> a;
		if (a == 1) {
			cin >> c >> t >> f;
			cus.push({c, t});
			ord[c] = f;
		} else if (a == 2) {
			cin >> c >> f;
			ord[c] = f;
		} else if (a == 3) {
			cin >> f;
			gone.insert(f);
		} else if (a == 4) {
			while (((cus.front().se < w) ||
							(gone.find(ord[cus.front().fi]) != gone.end())) &&
						 !cus.empty()) {
				cus.pop();
				if (cus.empty()) break;
			}

			if (cus.empty())
				cout << -1 << nl;
			else {
				cout << cus.front().fi << nl;
				cus.pop();
			}
		}
	}
}
