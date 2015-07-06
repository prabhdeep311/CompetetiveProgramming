//
//  LazyPropogation.cpp
//  O(lgn)
//
//  Created by Prabhdeep Singh Walia on 1/07/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//


/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

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

#define inf 0x7fffffff

int arr[maxn];
int tree[4*maxn];
int lazy[4*maxn];

void build_tree(int node, int a, int b) {
  	if(a > b) return;
  	
  	if(a == b)
    {
        tree[node] = arr[a];
		return;
	}
	
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
    
  	if(lazy[node] != 0)
    { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it
        
		if(a != b)
        {
			lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
        
   		lazy[node] = 0; // Reset it
  	}
    
	if(a > b || a > j || b < i)
		return;
    
  	if(a >= i && b <= j)
    {
        tree[node] += value;
        
		if(a != b) // Not leaf node
        {
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
        return;
	}
    
	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
    
	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range
    
	if(lazy[node] != 0)
    { // This node needs to be updated
		tree[node] += lazy[node]; // Update it
        
		if(a != b)
        {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
        
		lazy[node] = 0; // Reset it
	}
    
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
    
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
    
	int res = max(q1, q2); // Return final result
	
	return res;
}

int main()
{
    int N;
    cin>>N;
	for(int i = 0; i < N; i++) arr[i] = 1;
    
	build_tree(1, 0, N-1);
    
	memset(lazy, 0, sizeof lazy);
    
	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100
    
	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}








