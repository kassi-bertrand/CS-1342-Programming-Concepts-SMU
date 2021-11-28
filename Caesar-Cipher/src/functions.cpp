//
// Created by billy on 9/15/2021.
//
#include "functions.h"

std::string encrypt(const std::string& plainText, const std::string& key){

    std::string cipherText;
    unsigned int u = 0;
    for(unsigned int i = 0; i < plainText.size(); i++){

        if(!std::isalpha(plainText.at(i))){
            cipherText += plainText.at(i);
            continue;
        }
        //encoding here
        cipherText += static_cast<char>(((plainText.at(i) + key.at(u % (key.size()))) % 26) + 65);
        u++;
    }
    return cipherText;
}

std::string decrypt(const std::string& cipherText, const std::string& key){
    std::string plainText;
    unsigned int u = 0;
    for(unsigned int i = 0; i < cipherText.size(); i++){

        if(!(std::isalpha(cipherText.at(i)))){
            plainText += cipherText.at(i);
            continue;
        }
        //ascii_value can be negative.
        //Since the remainder of a division CANNOT be negative, we need to check. :)
        int ascii_value = (cipherText.at(i) - key.at(u % (key.size()))) % 26;
        int y = (ascii_value < 0) ? ascii_value + 26: ascii_value;
        plainText += static_cast<char>(y + 65);
        u++;
    }
    return plainText;
}

std::string getUserInput(){
    std::string input;
    std::getline(std::cin, input);
    capitalize(input);
    return input;
}

std::string validatePassCode(std::string passCode){
    std::string newPassCode;
    do{
        if(passCode.size() == 1){
            std::cout << "Passcode must be more than one-character long, and must only contain alpha characters(a - z, A - Z). Try again: ";
            passCode = getUserInput();
            continue;
        }
        else{
            //ignore all non-alpha character
            for(int i = 0; i < passCode.size(); i++){
                if(!std::isalpha(passCode.at(i))){
                    continue;
                }
                newPassCode += passCode.at(i);
            }
            break;
        }
    } while (true);
    return newPassCode;
}


void capitalize(std::string& input){
    for(int i = 0; i < input.size(); i++){
        input.at(i) = std::toupper(input.at(i));
    }
}