// Main.cpp

//  Jered Stevens
//  09/2/2024
//  UVA Problem 11988
//
//  To compile, navigate to working directory and make sure you
//  have the following files:
//  main.cpp    list.h    input2
//  then enter the following command into terminal
//  g++ main.cpp -o main
//
//  To run, enter the following into terminal
//  ./main < input2 > out2

#include <iostream>
#include <string>
#include "list.h"

using namespace std;
/*
    -use linked list
    -node pointer named cursor to keep track of where to insert data
    -when a bracket is found, call function cursorFront or cursorBack
        to move position of inserted data
*/
int main()
{
    string line;
    List list;

    while (cin >> line)
    {
        if (line.size() > 100000)
        {
            continue;
        }

        for (char i : line)
        {
            // test to know when to switch stacks
            if (i == '[')
            {
                list.cursorFront();
            }
            else if (i == ']')
            {
                list.cursorBack();
            }
            else
            {
                list.insertCursor(i);
            }
        }
        list.print();
        cout << endl;
        list.clearList();
    }
}
