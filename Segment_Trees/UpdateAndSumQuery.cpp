//
//  UpdateAndSumQuery.cpp
//  O(lgn), O(lgn)
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

int n, m, l, r, a[100], c;
int ConstructST(int a[], int n, int s, int e, int st[], int i)
{
    if(s==e)    //just one elem
    {
        st[i] = a[s];
        return a[s];
    }
    int mid = (e+s)/2;
    st[i] = ConstructST(a, n, s, mid, st, 2*i+1)+ConstructST(a, n, mid+1, e, st, 2*i+2);
    return st[i];
}

int getSum(int st[], int n, int s, int e, int ss, int se, int i)
{
    if(s<0 || e>=n || e<s)   return -1;
    
    if(s<=ss && e>=se)  return st[i];
    if(e<ss || s>se)    return 0;
    int mid = (ss+se)/2;
    return getSum(st, n, s, e, ss, mid, 2*i+1) + getSum(st, n, s, e, mid+1, se, 2*i+2);
}

void updateST(int st[], int n, int i, int diff, int ss, int se, int ind)
{
    if(i<0 || i>=n) return;
    if(i<ss || i>se)    return;
    st[ind]+=diff;
    if(se!=ss)
    {
        int mid = (ss+se)/2;
        updateST(st, n, i, diff, ss, mid, 2*ind+1);
        updateST(st, n, i, diff, mid+1, se, 2*ind+2);
    }
}

int main(int argc, const char * argv[])
{
    in(n);
    REP(i, n)   in(a[i]);
    int st[2*n];
    ConstructST(a, n, 0, n-1, st, 0);
    //cout<<getSum(st, n, 3, 5, 0, n-1, 0);
    in(m);
    while(m--)
    {
        in(c);in(l);in(r);
        if(c==1)
        {
            cout<<getSum(st, n, l, r, 0, n-1, 0)<<"\n";
        }
        else
        {
            updateST(st, n, l, r-a[l], 0, n-1, 0);
            a[l] = r;
            REP(i, n)   cout<<a[i]<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}










