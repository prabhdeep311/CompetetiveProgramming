//
//  RMQ.cpp
//  O(lgn)
//
//  Created by Prabhdeep Singh Walia on 31/05/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <list>
#include <fstream>
#include <set>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)
#define pii pair<int, int>
//void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int n, a[1005], st[2010];
int ConstructST(int l, int r, int stind)
{
    if(l==r)
    {
        st[stind] = a[l];
        return a[l];
    }
    int mid = l+(r-l)/2;
    st[stind] = min(ConstructST(l, mid, 2*stind+1), ConstructST(mid+1, r, 2*stind+2));
    return st[stind];
}

int GetMin(int l, int r, int ss, int se, int stind)
{
    if(l<0 || r>n-1 || l>r)    return -1;
    if(ss>=l && se<=r)    return st[stind];
    if(se<l || ss>r)    return INT_MAX;
    int mid = ss+(se-ss)/2;
    //cout<<ss<<" "<<se<<" "<<mid<<"\n";
    return min(GetMin(l, r, ss, mid, 2*stind+1), GetMin(l, r, mid+1, se, 2*stind+2));
}

int main(int argc, const char * argv[])
{
    cin>>n;
    REP(i, n)   cin>>a[i];
    ConstructST(0, n-1, 0);
    int l, r, s;
    cin>>s;
    while(s--)
    {
        cin>>l>>r;
        cout<<GetMin(l, r, 0, n-1, 0)<<"\n";
    }
    
    return 0;
}










