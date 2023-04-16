
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<lli , lli>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;
typedef priority_queue<lli> pq;
typedef priority_queue<pair<lli,lli>> pqp;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define printarr(a , n) for(int i = 0 ; i < n  ;i ++) cout << a[i] << " "; cout << endl;

#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18
/*
	order_of_key(x) -> number of elements strictly smaller than x
	find_by_order(k) -> kth element 
*/

struct Point
{
	int x;
	int y;
};

bool comp(Point p1 , Point p2)
{
	return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

int rotation(Point p1 , Point p2 , Point p3)
{
	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;
	int x3 = p3.x;
	int y3 = p3.y;

	int val = (x2 - x1)*y3 + (x3 - x2)*y1 + (x1 - x3)*y2;
	if(val < 0)
	{
		return 1;
	}
	if(val > 0)
	{
		return -1;
	}
	return 0;

}

bool equal(Point p1 ,Point p2)
{
	return (p1.x == p2.x) && (p1.y == p2.y);
}

void solve()
{

	lli n;
	cin >> n;

	vector<Point> points;

	for(int i = 0 ; i < n ; i ++)
	{
		Point p;
		cin >> p.x >> p.y;
		points.push_back(p);
	}

	sort(points.begin(), points.end() , comp);

	vector<Point> convexhull;
	convexhull.push_back(points[0]);

	Point l = points[0];
	Point q = points[1];

	do
	{
		Point nq;

		// check for all i
		// l --- i --- q to be right turn

		for(int i = 0 ; i < n ; i ++)
		{
			// -1 left  turn
			//  1 right turn

 			if(rotation(l , points[i] , q) == 1)
			{
				q = points[i];
				nq = points[(i+1)%n];
			}
		}

		convexhull.push_back(q);
		l = q;
		q = nq;

	}
	while(!equal(l ,points[0]));
	
	
	cout << "Convex Hull" << endl;
	for(Point p:convexhull)
	{
		cout << p.x << " " << p.y << endl;
	}

}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

    solve();
	
	return 0;
}
