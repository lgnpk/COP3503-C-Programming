//
//  main.cpp
//  PA3-take3
//
//  Created by Logan Peck on 11/20/16.
//  Copyright © 2016 Logan Peck. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <iomanip>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

int main(int argc, const char * argv[]) {
    
    //array stacks to be used to keep track of each keyword, identifier, constant
    //operator, delimiter and error
    std::string keywords [100];
    std::string identifiers [100];
    std::string constants [100];
    std::string operators [100];
    std::string delimiters [100];
    std::string errors [100];
    
    //additional variables
    int numNest = 0;
    
    
    //ask the user to enter the file name
    //file must be in the same location as pa3.cpp
    std::string fileName;
    std::cout << "Please enter a filename: ";
    std::cin >> fileName;
    int fileNameSize = fileName.length();
    //std::cout << input << std::endl;
    
    //checks to make sure the file is open
    std::ifstream file(fileName.c_str());
    if(!file.is_open()) {
        std::cout << "Upon checking, it seems that the file was unable to be opened." << std::endl;
        return 1;
    }
    
    for (int i = 0; i <= fileNameSize; ++i) {
        std::string nextWord;
        file >> nextWord;
        std::cout<<nextWord<<std::endl;
    }
    

    
    
    
    

    
     file.close();
    
    //print results at the end of the program once finished parsing
    std::cout << "The depth of nested loop(s) is " << numNest << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Keyword(s): " << keywords << std::endl;
    std::cout << "Identifier(s): " << identifiers << std::endl;
    std::cout << "Constant(s): " << constants << std::endl;
    std::cout << "Operator(s): " << operators << std::endl;
    std::cout << "Delimiter(s): " << delimiters << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Error(s): " << errors << std::endl;
    
    
    
    return 0;
}
