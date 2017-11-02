//
//  pa1.cpp
//  Programming Assignment 1
//
//  Created by Logan Peck on 9/20/16.
//  
//
#include <iostream>
#define MAX_SIZE 15


int main() {
    int size;
    double tempInteger = 0;
    
    std::cout << "Enter the size of a magic square: ";
    std::cin >> tempInteger;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    
    //check if equal to zero
    //testing for character entry
    if (tempInteger == 0) {
        std::cout << "You entered text. Please run the code again and enter an integer :)" << std::endl;
        return(1);
    }
    //checks if the entry is a decimal 
    if (tempInteger != (int)tempInteger) {
        std::cout << "You entered a decimal, please enter an integer." << std::endl;
        return(1);
    }
    else {
	size = tempInteger;
	if (size > MAX_SIZE || size <= 0 || size % 2 == 0) {
		std::cout << "Invalid input. Please try again." << std::endl;
		return(0);
	}
    }	
    
    
    int  magicSquare[MAX_SIZE][MAX_SIZE];
    
    //initialize each row and column of the array to 0 values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            magicSquare[i][j] = 0;
        }
    }
    
    //creates and initializes the position for 1
    int i = size/2;
    int j = size-1;
    
    //for loop places all values in magic square one by one
    for (int tempNum = 1; tempNum <= size*size; ) {
        if (i==-1 && j==size) {
            j = size-2;
            i = 0;
        }
        else {
            if (j==size){
                j = 0;
            }
            if (i < 0)
                i=size-1;
        }
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        }
        else {
            magicSquare[i][j] = tempNum++; //this sets the number value in place
            j++;
            i--;
        }
    }
    
    //print the magic square in the proper format, size * size
    std::cout << "\n" << "Magic Square #1 is: " << "\n" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << magicSquare[i][j] << "\t";
        }
        std:: cout << std::endl;
    }
    std::cout << std::endl;
    
    //calculates the sum of each row of the n by n magic square matrix and
    //prints out the values below the magic square
    std::cout << "Checking the sums of every row: \t";
    for (i=0; i<size ; i++) {
        int rowSum =0;
        for (int j = 0; j<size; j++) {
            rowSum += magicSquare[i][j];
        }
        std::cout << rowSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum in each column of the n by n magic square matrix and
    //prints out the values sequentially
    std::cout << "Checking the sums of every column: \t";
    for (int i=0; i<size ; i++) {
        int colSum =0;
        for (int j = 0; j<size; j++) {
            colSum += magicSquare[j][i];
        }
        std::cout << colSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum of each of the two diagonals of the n by n magic square matrix and
    //prints out the values below the magic square
    
    //Diagonal 1
    std::cout << "Checking the sums of each diagonal: \t";
    int diagSum1=0;
    for (int i=0;i<size;i++){
        diagSum1 += magicSquare[i][i];
    }
    std::cout << diagSum1 << "\t";
    
    //diagonal 2
    int diagSum2=0;
    for (int i=size-1;i>=0;i--){
        diagSum2 += magicSquare[i][i];
    }
    std::cout << diagSum2;
    
    std::cout << std::endl;
    
    //creates a second magic square by transposing the original magic square
    //re-arranges the rows and columns to create a new n by n matrix
    std::cout << "\n" << "Magic Square #2 is: " << "\n" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << magicSquare[j][i] << "\t";
        }
        std:: cout << std::endl;
    }
    std::cout << std::endl;

    
    //calculates the sum of each row of the n by n magic square matrix and
    //prints out the values below the magic square
    std::cout << "Checking the sums of every row: \t";
    for (i=0; i<size ; i++) {
        int rowSum =0;
        for (int j = 0; j<size; j++) {
            rowSum += magicSquare[i][j];
        }
        std::cout << rowSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum in each column of the n by n magic square matrix and
    //prints out the values sequentially
    std::cout << "Checking the sums of every column: \t";
    for (int i=0; i<size ; i++) {
        int colSum =0;
        for (int j = 0; j<size; j++) {
            colSum += magicSquare[j][i];
        }
        std::cout << colSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum of each of the two diagonals of the n by n magic square matrix and
    //prints out the values below the magic square
    
    //Diagonal 1
    std::cout << "Checking the sums of each diagonal: \t";
    int diagSum3=0;
    for (int i=0;i<size;i++){
        diagSum3 += magicSquare[i][i];
    }
    std::cout << diagSum3 << "\t";
    
    //diagonal 2
    int diagSum4=0;
    for (int i=size-1;i>=0;i--){
        diagSum4 += magicSquare[i][i];
    }
    std::cout << diagSum4;
    
    std::cout << std::endl;
    
    
    
    //creates a 3rd magic square by interchanging the rows within the magic square
    //the first and third row values are interchanged
    std::cout << "\n" << "Magic Square #3 is: " << "\n" << std::endl;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            std::cout << magicSquare[i][j] << "\t";
        }
        std:: cout << std::endl;
    }
    std::cout << std::endl;

    
    //calculates the sum of each row of the n by n magic square matrix and
    //prints out the values below the magic square
    std::cout << "Checking the sums of every row: \t";
    for (i=0; i<size ; i++) {
        int rowSum =0;
        for (int j = 0; j<size; j++) {
            rowSum += magicSquare[i][j];
        }
        std::cout << rowSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum in each column of the n by n magic square matrix and
    //prints out the values sequentially
    std::cout << "Checking the sums of every column: \t";
    for (int i=0; i<size ; i++) {
        int colSum =0;
        for (int j = 0; j<size; j++) {
            colSum += magicSquare[j][i];
        }
        std::cout << colSum << "\t";
    }
    std::cout << std::endl;
    
    //calculates the sum of each of the two diagonals of the n by n magic square matrix and
    //prints out the values below the magic square
    
    //Diagonal 1
    std::cout << "Checking the sums of each diagonal: \t";
    int diagSum5=0;
    for (int i=0;i<size;i++){
        diagSum5 += magicSquare[i][i];
    }
    std::cout << diagSum5 << "\t";
    
    //diagonal 2
    int diagSum6=0;
    for (int i=size-1;i>=0;i--){
        diagSum6 += magicSquare[i][i];
    }
    std::cout << diagSum6;
    
    std::cout << std::endl;

    
}

