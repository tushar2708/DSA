//
//  Palindrome.cpp
//  Practice
//
//  Created by tdwivedi on 5/11/16.o
//  Copyright © 2016 tdwivedi. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    while(N--){
        string input;
        cin >> input;
        int len = input.length();
        for(int i=0, j=len-1; i <= j; i++, j-- ){
            if(input[i]==input[j]){
                continue;
            } else if (input[i+1] == input[j]){
                cout << i << endl;
                break;
            } else if (input[i] == input[j-1]){
                cout << j << endl;
                break;
            }
        }
        cout << "-1" << endl;
    }
    return 0;
    
    
}
