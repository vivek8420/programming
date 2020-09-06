#include<bits/stdc++.h>
using namespace std;
#define int long long

struct point
{	
	int x,y;
	bool operator<(const point &a)
	{
		if(a.y==y)
			return x<a.x;
		return y<a.y;
	}
};

point p0;

/*
	0-linear
	1-clock wise
	3-anti clock wise
*/
int orientation(point a,point b,point c)
{
	int tmp=(b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
	if(tmp==0)
		return 0;
	return (tmp>0)?1:2;
}


bool compare(point a,point b)
{
    int o=orientation(p0,a,b);
    if(o==2)
        return true;
    else
        return false;
	
}	

void graham_scan(point p[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(p[i]<p[0])
		{
			point tmp;
			tmp=p[i];
			p[i]=p[0];
			p[0]=tmp;
		}
	}
	p0=p[0];
	sort(p+1,p+n,compare);
	
	/*for(int i=0;i<n;i++)
		cout<<p[i].x<<" "<<p[i].y<<endl;*/	
	
	stack<point>st;
	st.push(p[0]);
	st.push(p[1]);
	
	for(int i=2;i<n;i++)
	{
	    
		point p2=st.top();
		st.pop();	
		point p1=st.top();
		st.push(p2);
			
		while(!st.empty() && orientation(p1,st.top(),p[i])==1)
		{
			st.pop();
		}
		st.push(p[i]);
	}
	
	while(!st.empty())
	{
		p0=st.top();
		st.pop();
		cout<<p0.x<<" "<<p0.y<<endl;
	}		
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	point p[n];
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	
	graham_scan(p,n);
}
