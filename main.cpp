//  main.cpp
//  CT_Mod_5
//  Created by Brian Phipps on 10/9/24.
#include <iostream>
#include <fstream>

int main() {
    
    std::string originalFile = "/Users/briansmacbook/Downloads/CSC450_CT5_mod5.txt"; //file to be appended. Change file path as needed
    std::string reverseFile = "/Users/briansmacbook/Desktop/School/CSU Global/CSC450/CSC450-mod5-reverse.txt"; //new file for reversal, update filepath as needed
    
    std::ofstream outfile;
    outfile.open(originalFile, std::ios::app); //open and append file
    
    if (!outfile.is_open()){ //verify file was opened
        std::cout<<"Error opening file\n";
    }else{
        std::cout<<"Success! File was opened\n";
    }
    
    std::string userInput; //retrieve user input
    std::cout<<"Enter text to append: \n";
    std::getline(std::cin, userInput);
    
    outfile << userInput << std::endl; //append input to og file
    outfile.close();
    
    //begin reversing the file
    std::ifstream infile(originalFile);
    if (!infile.is_open()) {
        std::cout<<"Error opening file\n";
    }
    
    //reads every char from file, adds to string "content"
    std::string content;
    char ch;
    while (infile.get(ch)){
        content += ch;
    }
    infile.close();
    std::reverse(content.begin(), content.end()); //reverses content string
    
    //create and open new reverse file
    std::ofstream reverseOutfile(reverseFile);
    if (!reverseOutfile.is_open()){
        std::cout<< "Error opening file\n";
    }else{
        std::cout<<"Success!, new file was opened\n";
        std::cout<<"Reverse file created at: " << reverseFile <<std::endl;
    }
    //write content string to new file,
    reverseOutfile << content;
    reverseOutfile.close();
    
    return 0;
}
