//
//  XORLazy.cpp
//  Codeforces http://codeforces.com/contest/242/problem/E
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
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=100005;
const double eps=1e-6;
typedef vector<vector<ll> > matrix;

int arr [maxn];
int tree[21][4*maxn];
int lazy[21][4*maxn];

void build(int node,int left,int right,int no)
{
    if(left==right)
    {
        tree[no][node]=0;
        if(arr[left] & (1<<no))
        {
            tree[no][node]=1;
        }
        return;
    }
    int mid=(left+right)>>1;
    build(2*node,left,mid,no);
    build(2*node+1,mid+1,right,no);
    
    tree[no][node]= tree[no][2*node]+tree[no][2*node+1];
    return;
}

void update(int node,int left,int right,int no,int i,int j)
{
    if(lazy[no][node])
    {
        tree[no][node]= (right-left+1)-(tree[no][node]);
        if(left!=right)
        {
            lazy[no][2*node]^=1;
            lazy[no][2*node+1]^=1;
        }
        lazy[no][node]=0;
    }
    if(left > j || right < i) return ;
    if(left>=i && right <=j)
    {
        tree[no][node]= (right-left+1)-(tree[no][node]);
        if(left!=right)
        {
            lazy[no][2*node]^=1;
            lazy[no][2*node+1]^=1;
        }
        lazy[no][node]=0;
        return;
    }
    
    int mid=(left+right)>>1;
    update(2*node,left,mid,no,i,j);
    update(2*node+1,mid+1,right,no,i,j);
    
    tree[no][node]= tree[no][2*node]+tree[no][2*node+1];
    return;
}


int query(int node,int left,int right,int no,int i,int j)
{
    
    if(lazy[no][node])
    {
        tree[no][node]= (right-left+1)-(tree[no][node]);
        if(left!=right)
        {
            lazy[no][2*node]^=1;
            lazy[no][2*node+1]^=1;
        }
        lazy[no][node]=0;
    }
    
    if(left > j || right < i) return 0;
    
    if(left >= i && right <= j)
    {
        return tree[no][node];
    }
    
    int mid=(left+right)>>1;
    
    return query(2*node,left,mid,no,i,j)+query(2*node+1,mid+1,right,no,i,j);
}
int main()
{
    int n,l,r,x,c;
    scanf("%d",&n);
    REP(i,n)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<20;i++)
    {
        build(1,0,n-1,i);
    }
    // cout<<"af"<<endl;
    int m;
    scanf("%d",&m);
    
    REP(i,m)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d %d",&l,&r);
            ll sum=0;
            for(int i=0;i<20;i++)
            {
                sum+= ( query(1,0,n-1,i,l-1,r-1) * (1LL<<i));
            }
            cout<<sum<<"\n";
        }
        else
        {
            scanf("%d %d %d",&l,&r,&x);
            for(int i=0;i<20;i++)
            {
                if(x & (1<<i))
                    update(1,0,n-1,i,l-1,r-1);
            }
        }
    }
    
    return 0;
}








