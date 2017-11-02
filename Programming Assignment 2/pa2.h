//
//  pa2.h
//  Programming Assignment 2
//
//  Created by Logan Peck on 10/15/16.
//
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node (int n);
    string programName;
    Node* next;
};

Node::Node(int n){
    programName = "NULL";
};



class LinkedList {
public:
    Node *first = NULL;
    Node *current;
    Node *temp;
    void printList();
    void worst();
    void insertNode(int num);
    void best();
    
};

void LinkedList::insertNode(int num){
    Node* temp=first;
    first=new Node(num);
    first->next=temp;
};

void LinkedList::printList(){
    Node* temp=first;
};

void displayMenu(){
    
}

int numberOfPages (int progSize) {
    int numberOfPages;
    
}


void LinkedList::worst() {
    
    //variables to be used in the worst fit algorithm
    int choice = 0;
    int amtFreePages = 32;
    int emptyPages;
    int contMem;
    int initFreeMemPosition;
    int progSize;
    int indexFreeMem;
    int fragment;
    string progName;
    
}

void LinkedList::best() {
    
    
    int choice = 0;
    int amtFreePages = 32;
    int emptyPages;
    int contMem;
    int initFreeMemPosition;
    int progSize;
    int indexFreeMem;
    int fragment;
    string progName;
    
}


int main(const int argc, const char **argv) {
    
    int num = 32;
    LinkedList *L1= new LinkedList();
    string *cppArgs = new std::string[argc];
}


#endif /* Header_h */
