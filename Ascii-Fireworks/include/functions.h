//
// Created by billy on 11/3/2021.
//

#ifndef PROGRAM4_FUNCTIONS_H
#define PROGRAM4_FUNCTIONS_H

#include <iostream>
#include <cstdlib>

using namespace std;

const int BUFFER_COLUMNS = 60;
const int BUFFER_LINES = 20;

//Dynamically allocate empty Buffer
void AllocateBuffer(char *buffer[], int bufferLines, int bufferColumns);

//copy images to buffer at position (x,y)
void CopyImage1(char *buffer[], int x, int y);
void CopyImage2(char *buffer[], int x, int y);
void CopyImage3(char *buffer[], int x, int y);
void CopyImage4(char *buffer[], int x, int y);

//Copy firework trace from (x,y) to borders of the buffer
void CopyFireworkTrace(char *buffer[], int x, int y);

//Render buffer to std::out (screen)
void PresentBuffer(char *buffer[], int bufferLines, int bufferColumns);

//deallocate buffer
void DeallocateBuffer(char *buffer[], int bufferLines, int bufferColumns);

//clear buffer
void ClearBuffer(char *buffer[], int bufferLines, int bufferColumns);

//Random function
void GetRandomNumbers(int &x, int &y);

#endif //PROGRAM4_FUNCTIONS_H
