//
//  main.cpp
//  pointers
//
//  Created by Gonzalo Vergara on 2/16/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 5;
    int *ptr = &n;
    std::cout << **&ptr;
    return 0;
}
