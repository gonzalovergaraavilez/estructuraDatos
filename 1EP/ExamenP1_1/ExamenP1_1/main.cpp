//
//  main.cpp
//  ExamenP1_1
//
//  Created by Gonzalo Vergara on 2/19/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#include <iostream>

std::string change_to_hex(int, char[16],std::string);

int main(int argc, const char * argv[]) {
    char conversion_values[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    /*for (int i=0;i<16;i++){
     std::cout << conversion_value[i]<< std::endl;
     }*/
    std::cout << "Escriba el número a convertir" << std::endl;
    int number = 0;
    std::cin >> number;
    
    std::string result = change_to_hex(number, conversion_values, " ");
    std::cout << "result: " << result;
    return 0;
}

std::string change_to_hex(int number, char eq_values[16], std::string current_string){
    //std::cout << "current_string: " << current_string << std::endl;
    int division= number/16;
    char equivalent_value = eq_values[number%16];
    //std::cout << "division: " << division << ", ";
    //std::cout << "equivalent: " << equivalent_value << std::endl;
    if(division<16){
        std::string temp_string =equivalent_value + current_string;
        return eq_values[division] + temp_string;
    }else{
        return change_to_hex(division, eq_values, equivalent_value + current_string);
    }
}
