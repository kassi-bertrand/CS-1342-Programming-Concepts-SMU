#include <iostream>
#include <string>
#include "functions.h"

int main() {
    std::cout << "Welcome to SMU Encryption engine!" << std::endl << std::endl;

    do{
        std::cout << "Please enter a command: ";
        std::string userCommand = getUserInput();

        while(userCommand != "ENCRYPT" && userCommand != "DECRYPT" && userCommand != "QUIT"){
            std::cout << userCommand << " is not a valid command. Please enter one of ENCRYPT/DECRYPT/QUIT" << std::endl << std::endl;
            std::cout << "Please enter a command: ";
            userCommand = getUserInput();
        }

        if(userCommand == "ENCRYPT"){
            std::cout << "Enter your passcode: ";
            std::string passCode = validatePassCode(getUserInput());

            std::cout << "Enter the message to the encrypted: ";
            std::string plainText = getUserInput();

            std::cout << std::endl << "Encrypting your message..." << std::endl << std::endl;
            std::string cipherText = encrypt(plainText, passCode);

            std::cout << "Passcode: " << passCode << std::endl;
            std::cout << "Plaintext Message: " << plainText << std::endl;
            std::cout << "Ciphertext Message: " << cipherText << std::endl << std::endl  ;
        }
        else if(userCommand == "DECRYPT"){
            std::cout << "Enter your passcode: ";
            std::string passCode = validatePassCode(getUserInput());

            std::cout << "Enter the message to be decrypted: ";
            std::string cipherText = getUserInput();

            std::cout << std::endl << "Decrypting your message..." << std::endl << std::endl;
            std::string plainText = decrypt(cipherText, passCode);

            std::cout << "Passcode: " << passCode << std::endl;
            std::cout << "Ciphertext Message: " << cipherText << std::endl;
            std::cout << "Plaintext Message: " << plainText << std::endl << std::endl;
        }
        else if(userCommand == "QUIT"){
            std::cout << "Goodbye!"<< std::endl;
            break;
        }
    }while(true);
    return 0;
}
