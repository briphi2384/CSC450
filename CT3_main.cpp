//
//  main.cpp
//  CSC450_CT_Mod3
//
//  Created by Brian Phipps on 9/26/24.
//

#include <iostream>

int main() {
    
    //declare variables
    int num1;
    int num2;
    int num3;
    
    //declare pointers, allocate memory
    int * pointer1 = new int;
    int * pointer2 = new int;
    int * pointer3 = new int;
 
    //gather input from user
    std::cout << "Enter first number: ";
    std::cin>>num1;
    std::cout << "\nEnter second number: ";
    std::cin>>num2;
    std::cout<<"\nEnter third number: ";
    std::cin>>num3;
    
    //assign pointers
    *pointer1 = num1;
    *pointer2 = num2;
    *pointer3 = num3;
    
    //Display memory addresses and stored info
    std::cout <<"\nFirst number: "<<*pointer1;
    std::cout<<"\nAddress in memory: "<<pointer1;
    std::cout<<"\nSecond number: "<<*pointer2;
    std::cout<<"\nAddress in memory: "<<pointer2;
    std::cout<<"\nThird number: "<<*pointer3;
    std::cout<<"\nAddress in memory: "<<pointer3<< std::endl;
    
    //delete and deallocate memory
    delete pointer1;
    delete pointer2;
    delete pointer3;
    
    
    return 0;
}
