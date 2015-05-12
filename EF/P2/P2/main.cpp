//
//  main.cpp
//  P2
//
//  Created by Gonzalo Vergara on 5/12/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int length = 3;
    int iterations= 3;
    
    int total_length = length*(pow (3, iterations));
    std::cout << "total length: " << total_length << "\n";
    
    for (int i; i<total_length; i++) {
        for (int j = 0; j<total_length; j++) {
            std::cout << "x";
        }
        std::cout << std::endl;
    }

    
    return 0;
}
