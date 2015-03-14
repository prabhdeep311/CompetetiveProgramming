//
//  Euclid_GCD_LCM.cpp
//  O(log(min(a,b)))
//
//  Created by Prabhdeep Singh Walia on 13/03/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, b%a) : a;
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int main(int argc, const char * argv[])
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b)<<"\n"<<lcm(a, b)<<"\n";
    return 0;
}

