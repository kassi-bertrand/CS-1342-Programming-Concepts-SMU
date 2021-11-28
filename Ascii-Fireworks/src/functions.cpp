//
// Created by billy on 11/3/2021.
//

#include "functions.h"

void AllocateBuffer(char *buffer[], int bufferLines, int bufferColumns){

    for(int i = 0; i < bufferLines; i++){
        buffer[i] = new char[bufferColumns];
    }

    //fill the buffer with ' '
    for(int i = 0; i < bufferLines; i++){
        for(int u = 0; u < bufferColumns; u++){
            buffer[i][u] = ' ';
        }
    }
}

void CopyImage1(char *buffer[], int x, int y){

    const int HEIGHT = 3;
    const int WIDTH = 5;
    //IMAGE 1 matrix;
    char fireWorkArt[HEIGHT][WIDTH] = {
            {'.', '*', ' ', '*', '.'},
            {' ', '*', '.', '.', '*'},
            {' ', ' ', ' ', '*', ' '}
    };

    //copy IMAGE 1 to buffer
    for(int i = 0; i < HEIGHT; i++){
        for(int u = 0; u < WIDTH; u++){
            if((i+y) < BUFFER_LINES && (u+x) < BUFFER_COLUMNS){
                buffer[i + y][u + x] = fireWorkArt[i][u];
            }
        }
    }

    //copy Firework trace
    int greenPointX = 4;
    int greenPointY = 3;
    CopyFireworkTrace(buffer, greenPointX + x, greenPointY + y);

}
void CopyImage2(char *buffer[], int x, int y){

    const int HEIGHT = 4;
    const int WIDTH = 9;
    //IMAGE 2 matrix;
    char fireWorkArt[HEIGHT][WIDTH] = {
            {' ','^',',','^',',','^',' ',' ',' '},
            {'^',',','^',',','^',',','^',',','^'},
            {'^',',','^',',','^',',','^',',','^'},
            {' ','^',',','^',',','^',' ',' ',' '}
    };

    //copy IMAGE 2 to buffer
    for(int i = 0; i < HEIGHT; i++){
        for(int u = 0; u < WIDTH; u++){
            if((i+y) < BUFFER_LINES && (u+x) < BUFFER_COLUMNS){
                buffer[i + y][u + x] = fireWorkArt[i][u];
            }
        }
    }

    //copy Firework trace
    int greenPointX = 5;
    int greenPointY = 4;
    CopyFireworkTrace(buffer, greenPointX + x, greenPointY + y);
}
void CopyImage3(char *buffer[], int x, int y){

    const int HEIGHT = 3;
    const int WIDTH = 7;
    //IMAGE 3 matrix;
    char fireWorkArt[HEIGHT][WIDTH] = {
            {'`','o','`','o','`',' ',' '},
            {'o','`','o','`','o','`','o'},
            {'`','o','`','o','`',' ',' '},
    };

    //copy IMAGE 3 to buffer
    for(int i = 0; i < HEIGHT; i++){
        for(int u = 0; u < WIDTH; u++){
            if((i+y) < BUFFER_LINES && (u+x) < BUFFER_COLUMNS){
                buffer[i + y][u + x] = fireWorkArt[i][u];
            }
        }
    }

    //copy Firework trace
    int greenPointX = 3;
    int greenPointY = 3;
    CopyFireworkTrace(buffer, greenPointX + x, greenPointY + y);
}
void CopyImage4(char *buffer[], int x, int y){

    const int HEIGHT = 5;
    const int WIDTH = 11;
    //IMAGE 4 matrix;
    char fireWorkArt[HEIGHT][WIDTH] = {
            {' ',' ',' ','~','@','~','@','~',' ',' ',' '},
            {'~','*','~','@','~','*','~','@','~','*','~'},
            {'~','*','~','@','$','#','$','@','~','*','~'},
            {'~','*','~','@','~','*','~','@','~','*','~'},
            {' ',' ',' ','~','@','~','@','~',' ',' ',' '}
    };

    //copy IMAGE 4 to buffer
    for(int i = 0; i < HEIGHT; i++){
        for(int u = 0; u < WIDTH; u++){
            if((i+y) < BUFFER_LINES && (u+x) < BUFFER_COLUMNS){
                buffer[i + y][u + x] = fireWorkArt[i][u];
            }
        }
    }

    //copy Firework trace
    int greenPointX = 6;
    int greenPointY = 5;
    CopyFireworkTrace(buffer, greenPointX + x, greenPointY + y);
}


void CopyFireworkTrace(char *buffer[], int x, int y){
    if(x < 30){
        // fireworks = '\'
        while( x < BUFFER_COLUMNS && y < BUFFER_LINES){
            buffer[y][x] = '\\';
            x++;
            y++;
        }
    }
    else if(x > 30){
        // fireworks = '/'
        while( x < BUFFER_COLUMNS && y < BUFFER_LINES){
            buffer[y][x] = '/';
            x--;
            y++;
        }
    }
    else{
        // fireworks = '|'
        while( x < BUFFER_COLUMNS && y < BUFFER_LINES){
            buffer[y][x] = '|';
            y++;
        }
    }
}

void PresentBuffer(char *buffer[], int bufferLines, int bufferColumns){
    for(int i = 0; i < bufferLines; i++){
        for(int u = 0; u < bufferColumns; u++){
            cout << buffer[i][u];
        }
        cout << endl;
    }
}

void ClearBuffer(char *buffer[], int bufferLines, int bufferColumns){
    for(int i = 0; i < bufferLines; i++){
        for(int u = 0; u < bufferColumns; u++){
            buffer[i][u] = ' ';
        }
    }
}

void DeallocateBuffer(char *buffer[], int bufferLines, int bufferColumns){
    for(int i = 0; i < bufferLines; i++){
        delete [] buffer[i];
    }
}

void GetRandomNumbers(int &x, int &y){
    x = rand() % 60;
    y = rand() % 20;
}
