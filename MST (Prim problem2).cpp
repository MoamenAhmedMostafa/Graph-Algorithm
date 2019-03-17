#include <bits/stdc++.h>
using namespace std;
#define all(v)          ((v).begin()), ((v).end())
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v,d)		memset(v, d, sizeof(v))
const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>P;
const ll mod = ll(1e9 + 7);
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
const int N = 500001;
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
struct point{
	double x, y;
};
ll gcd(ll a, ll b){ return !b ? a : gcd(b, a % b); }
ll fixMod(ll a, ll b){ return ((a%b) + b) % b; }
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2.;
};
double dis(point a, point b) {
	ll x = a.x - b.x, y = a.y - b.y;
	return sqrt(x * x + y * y);
}
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
const ll OO = 1e8;
#define sz(v)               ((int)((v).size()))

struct edge {
	int from, to;
	double w;
	edge(int from, int to, double w) : from(from), to(to), w(w) {}
	bool operator < (const edge & e) const {
		return w > e.w;  
	}
};
int n;
double PRIM_MST2(vector< vector< edge > > adjList) 
{   
	int n = sz(adjList);
	double mstCost = 0;
	vi vis(n, 0);
	vector<edge> edges;            
	priority_queue<edge> q;       
	q.push(edge(-1, 0, 0));
	while (!q.empty()) {
		edge e = q.top();       q.pop();
		if (vis[e.to]) continue;
		vis[e.to] = 1;
		mstCost += e.w;
		for (int j = 0;j<sz( adjList[e.to]);j++) {             
			edge ne = adjList[e.to][j];
			if (!vis[ne.to])              
				q.push(ne);
		}
	}
	return mstCost;
	
}
int main(){
	fast
		int T = 1;
	while (cin >> n &&n){
		
		vector< vector< edge > > adj(n);
		point v[1001];
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				double ds = dis(v[i], v[j]);
				adj[i].push_back(edge(i, j, ds));
				adj[j].push_back(edge(j, i, ds));
			}
		}
		cout << fixed <<setprecision(2)<<PRIM_MST2(adj) << endl;
	}
	stop();
	return 0;
}