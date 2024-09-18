//
//  main.cpp
//  CS450_CTMod2
//
//  Created by Brian Phipps on 9/18/24.
//

#include <iostream>
#include <string>

int main() {
    std::string str1; //user input 1
    std::string str2; //user input 2
    std::string str3; // concatenated string
    
    for (int i =0; i < 3; i++){ //collect data from user 3 times.
  
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1); //Gathers input from user
    
    std::cout << "\nEnter second string: ";
    std::getline(std::cin, str2);
    
    //Output new, concatenated string
    str3 = str1 + str2; //concatenates the two strings. strcat() would work with C-Strings.
    std::cout << "\nConcatenated String: "<< str3 <<std::endl;
    
    //Empty the string variables
        str1.clear();
        str2.clear();
        str3.clear();
}//end of for loop.
    return 0;
}//end of main
