//
//  pa2.cpp
//  Programming Assignment 2
//
//  Created by Logan Peck on 10/15/16.
//
//

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
    programName = "NULL"; //Set node value to n
    
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
    Node* temp=first;                               //Set temp equal to head
    first=new Node(num);                            //Create a new node based on num
    first->next=temp;                               //Set the new head node to the old head node
    
};

void LinkedList::printList(){
    Node* temp=first;                                //Start temp at the beginning of List
    while(temp!=NULL){                              //When nextNode points to Null it is end of the list
        for (int i=0; i<=7; i++){
            if (temp->programName == "NULL") {
                cout << "Free" << " ";
            }
            else {
                cout << temp->programName << " ";
            }
            temp = temp->next;
        }
        cout << endl;//Set temp to next Node in list
    }
    cout << endl;
    
};

//displays user dialogue
void displayMenu(){
    
    std::cout<<std::endl;
    std::cout<<"\t1. Add program"<<std::endl;
    std::cout<<"\t2. Kill program"<<std::endl;
    std::cout<<"\t3. Fragmentation"<<std::endl;
    std::cout<<"\t4. Print Memory"<<std::endl;
    std::cout<<"\t5. Exit"<<std::endl;
    std::cout<<std::endl;
}

int numberOfPages (int progSize) {
    int numberOfPages;
    if (progSize % 4 == 0) {
        numberOfPages = progSize/4;
    }
    else {
        numberOfPages = progSize/4 + 1;
    }
    return numberOfPages;
}


//when the command line argument for "worst" is chosen, the following code will run
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
    
    cout << "Using Worst Fit Algorithm" << endl;
    displayMenu();
    cout << "Choice - ";
    cin >> choice;
    
    while (choice != 5) {
        switch (choice) {
            default: {
                cout << "This input is not recognized! Please try again!" << endl;
                cout << endl;
                displayMenu();
                cout << "Choice - ";
                cin >> choice;
                break;
            }
                //Add a program
             
            case 1: {
                int numberPages;
                emptyPages = 0;
                contMem = 0;
                initFreeMemPosition = 0;
                indexFreeMem = 0;
                int i = 0;
                cout << "Program Name: ";
                cin >> progName;
                cout << "Program Size (KB): ";
                cin >> progSize;
                
                numberPages = numberOfPages((int) progSize);
                Node *temp = first;
                
                while (temp != NULL) {
                    if (temp->programName == "NULL") {
                        emptyPages++;
                    }
                    else {
                        if (emptyPages > contMem) {
                            contMem = emptyPages;
                            indexFreeMem = initFreeMemPosition;
                            emptyPages = 0;
                        }
                        else {
                            initFreeMemPosition = i+1;
                            emptyPages = 0;
                        }
                    }
                    temp = temp->next;
                    i++;
                    
                }
                if (emptyPages > contMem) {
                    contMem = emptyPages;
                    indexFreeMem = initFreeMemPosition;
                }
                if (emptyPages == amtFreePages) {
                    contMem = emptyPages;
                    indexFreeMem = initFreeMemPosition;
                }
                if (contMem >= numberPages) {
                    Node *temp = first;
                    for (int i = 0; i < indexFreeMem; i++) {
                        temp = temp->next;
                    }
                    for (int i = 0; i < numberPages; i++) {
                        temp->programName=progName;
                        temp = temp->next;
                    }
                    while (temp != NULL) {
                        temp = temp->next;
                    }
                    amtFreePages = amtFreePages - numberPages;
                    
                }
                else {
                    cout << "Program " << progName << " does not fit!" << endl;
                }
                cout << endl;
                cout << "Program " << progName << " Successfully Added! (" << numberPages << " Page(s) Used)" << endl;
                cout << endl;
                
                cout << "Choice - ";
                cin >> choice;
                
                break;
                
            }
                break;
                
                
                //kill program
            case 2: {
                cout << "Enter the Program Name: ";
                cin >> progName;
                Node* temp=first;
                
                while(temp!=NULL){                              //When nextNode points to Null it is end of the list
                    
                    if (temp->programName == progName) {
                        temp->programName = "NULL";
                    }
                    temp = temp->next;//Set temp to next Node in list
                }
                cout << endl;
                cout << progName << " was killed successfully!" << endl;
                cout << endl;
                cout << "Choice - ";
                cin >> choice;

                break;
            }
                
                //Fragmentation
            case 3: {
                fragment = 0;
                Node* temp=first;
                cout << endl;
                while(temp!= NULL){                              //When nextNode points to Null it is end of the list
                    if (temp->programName == "NULL") {
                        fragment++;
                        while (temp!= NULL){
                            if(temp->programName == "NULL"){
                                temp = temp->next;
                            }
                        }
                    }
                    
                    else {
                        if (temp->programName != "NULL") {
                            temp = temp->next;
                        }
                    }
                }
                cout << "There are " << fragment << "fragment(s)." << endl;
                cout << endl;
                cout << "Choice - ";
                cin >> choice;
                
                
            }
                
                //Print Memory
            case 4: {
                cout << endl;
                printList();
                cout << "Choice - ";
                cin >> choice;
                break;
                
            }
                
            case 5: {
                cout << "This program will now exit. Goodbye!" << endl;
                exit(0);
                break;
            }
        }
    }
}

//when the command line argument for "best" is chosen, the following code will run
void LinkedList::best() {
    
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
    
    //originally the output below said for best fit algorithm only
    cout << "Using Best Fit Algorithm" << endl;
    displayMenu();
    cout << "Choice - ";
    cin >> choice;
    
    while (choice != 5) {
        switch (choice) {
            default: {
                cout << "This input is not recognized! Please try again!" << endl;
                cout << endl;
                displayMenu();
                cout << "Choice - ";
                cin >> choice;
                break;
            }
                //Add a program
                
            case 1: {
                int numberPages;
                emptyPages = 0;
                contMem = 0;
                initFreeMemPosition = 0;
                indexFreeMem = 0;
                int i = 0;
                cout << "Program Name: ";
                cin >> progName;
                
                
                cout << "Program Size (KB): ";
                cin >> progSize;
                
                numberPages = numberOfPages((int) progSize);
                Node *temp = first;
                
                while (temp != NULL) {
                    if (temp->programName == "NULL") {
                        emptyPages++;
                    }
                    else {
                        //THIS LINE CHANGED Wednesday, November 16, 2016 - 4:26 PM
                        //changed from "<=" to "<"
                        if (emptyPages <= contMem) {
                            contMem = emptyPages;
                            indexFreeMem = initFreeMemPosition;
                            emptyPages = 0;
                        }
                        else {
                            initFreeMemPosition = i+1;
                            emptyPages = 0;
                        }
                    }
                    temp = temp->next;
                    i++;
                    
                }
                if (emptyPages <= contMem) {
                    contMem = emptyPages;
                    indexFreeMem = initFreeMemPosition;
                }
                if (emptyPages == amtFreePages) {
                    contMem = emptyPages;
                    indexFreeMem = initFreeMemPosition;
                }
                //CHANGED FROM ">=" to "<=" Wednesday, November 16, 2016 - 4:31 PM
                if (contMem >= numberPages) {
                    Node *temp = first;
                    for (int i = 0; i < indexFreeMem; i++) {
                        temp = temp->next;
                    }
                    for (int i = 0; i < numberPages; i++) {
                        temp->programName=progName;
                        temp = temp->next;
                    }
                    while (temp != NULL) {
                        temp = temp->next;
                    }
                    amtFreePages = amtFreePages - numberPages;
                    
                }
                else {
                    cout << "Program " << progName << " does not fit!" << endl;
                }
                cout << endl;
                cout << "Program " << progName << " Successfully Added! (" << numberPages << " Page(s) Used)" << endl;
                cout << endl;
                
                cout << "Choice - ";
                cin >> choice;
                
                break;
                
            }
                break;
                
                
                //kill program
            case 2: {
                cout << "Enter the Program Name: ";
                cin >> progName;
                Node* temp=first;
                
                while(temp!=NULL){                              //When nextNode points to Null it is end of the list
                    
                    if (temp->programName == progName) {
                        temp->programName = "NULL";
                    }
                    temp = temp->next;//Set temp to next Node in list
                }
                cout << endl;
                cout << progName << " was killed successfully!" << endl;
                cout << "Choice - ";
                cin >> choice;
                
                break;
            }
                
                //Fragmentation
            case 3: {
                fragment = 0;
                Node* temp=first;
                cout << endl;
                while(temp!= NULL){                              //When nextNode points to Null it is end of the list
                    if (temp->programName == "NULL") {
                        fragment++;
                        while (temp!= NULL){
                            if(temp->programName == "NULL"){
                                temp = temp->next;
                            }
                        }
                    }
                    
                    else {
                        if (temp->programName != "NULL") {
                            temp = temp->next;
                        }
                    }
                }
                cout << "There are " << fragment << "fragment(s)." << endl;
                cout << "Choice - ";
                cin >> choice;
                
            }
                
                //Print Memory
            case 4: {
                cout << endl;
                printList();
                cout << "Choice - ";
                cin >> choice;
                break;
                
            }
                
            case 5: {
                cout << "This program will now exit. Goodbye!" << endl;
                exit(0);
                break;
            }
        }
    }
}



    
int main(const int argc, const char **argv) {
    
    int num = 32;                                                          //Set Number of Elements (50,000 is noticeable)
    LinkedList *L1= new LinkedList();                                   //Instantiate L1 object from Linked List class
    for(int i=0;i<num;i++){
        L1->insertNode(i);                                        //insert i into L1 at Head
        
    }
    

    string *cppArgs = new std::string[argc];
    for (int i=0; i != argc; ++i) {
        cppArgs[i] = std::string(argv[i]);
    }
    if (argc == 2) {                                                   //make sure user put correct amount of args
        if (cppArgs[1] == "worst") {
            L1->worst();
        } else if (cppArgs[1] == "best") {
            L1->best();
        } else {
            cout << "Improper argument entered by user, please enter BEST or WORST." << endl;
        }
    }
    
}
                





