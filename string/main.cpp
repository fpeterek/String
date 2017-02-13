//
//  main.cpp
//  string
//
//  Created by Filip Peterek on 16/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include <iostream>
#include "string.hpp"

int main(int argc, const char * argv[]) {
    
    string test = "test";
    const string test123 = test + " 123";
    
    std::cout << "Test: " << test123 << std::endl;
    
    std::cout << "test123[2]: " << test123[2] << std::endl;
    std::cout << "test123[-2]: " << test123[-2] << std::endl;
    
    std::cout << "Substring: " << test123.substring(0, 5) << std::endl;
    
    test += "321";
    std::cout << "Test321: " << test << std::endl;
    
    std::cout << "Reversed: " << test.reverse() << std::endl;
    std::cout << "test123.substring(len - 1, 1): " << test.substring(test.length() - 1, 1) << std::endl;
    
    std::cout << "Cyka == Blyat: " << (string("Cyka") == string("Blyat")) << std::endl;
    std::cout << "Cyka == Cyka: " << (string("Cyka") == string("Cyka")) << std::endl;
    
    std::cout << "\"Geralt of Rivia\".find(\"of\"): " << string("Geralt of Rivia").find("of") << std::endl;
    
    size_t klepnaPos = string("Geralt of Rivia").find("Klepna");
    
    std::cout << "\"Geralt of Rivia\".find(\"Klepna\"): "
              << (klepnaPos == string::npos ? std::string("Not found") : std::to_string(klepnaPos)) << std::endl;
    
}
