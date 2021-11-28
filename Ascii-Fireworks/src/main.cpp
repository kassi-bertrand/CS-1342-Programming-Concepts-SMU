#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    char *buffer[BUFFER_LINES];
    string userInput;

    //Allocate Buffer
    AllocateBuffer(buffer, BUFFER_LINES, BUFFER_COLUMNS);

    do{
        cout << "Do you want to see the fireworks? (y|n)" << endl;
        cin >> userInput;
        if(userInput == "n"){
            //Deallocate buffer
            DeallocateBuffer(buffer, BUFFER_LINES, BUFFER_COLUMNS);
            cout << "Thanks for stopping by!" << endl;
            break;
        }

        //clear the buffer
        ClearBuffer(buffer, BUFFER_LINES, BUFFER_COLUMNS);

        //Copy fireworks at randomly generated x,y
        int randomX,randomY;
        GetRandomNumbers(randomX, randomY);
        CopyImage1(buffer, randomX, randomY);

        GetRandomNumbers(randomX, randomY);
        CopyImage2(buffer, randomX, randomY);

        GetRandomNumbers(randomX, randomY);
        CopyImage3(buffer, randomX, randomY);

        GetRandomNumbers(randomX, randomY);
        CopyImage4(buffer, randomX, randomY);

        //present buffer
        PresentBuffer(buffer, BUFFER_LINES, BUFFER_COLUMNS);
    }while(true);

    return 0;
}
