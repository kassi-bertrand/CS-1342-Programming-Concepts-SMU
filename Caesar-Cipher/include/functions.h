//
// Created by billy on 9/15/2021.
//

#ifndef PROGRAM2_FUNCTIONS_H
#define PROGRAM2_FUNCTIONS_H
#include <string>
#include <iostream>
#include <cctype>

std::string encrypt(const std::string& plainText, const std::string& key);
std::string decrypt(const std::string& cipherText, const std::string& key);
std::string getUserInput();
std::string validatePassCode(std::string passCode);
void capitalize(std::string& input);

#endif //PROGRAM2_FUNCTIONS_H
