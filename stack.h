#pragma once
#include <iostream>
#include <memory>

using namespace std;


class stack{
    public:

    
    //move to private. create accessors / mutators and update files
    int size = 0;

  
//-----------------------------------------------------------------------------
//Push and Pop. used to manipulate the stack. 
    void push(int topush);
    int pop();

//-----------------------------------------------------------------------------
//Print- prints stack
    void print()const;




    private:
//-----------------------------------------------------------------------------
//Node struct- used to hold the data for the stack dynamically allocated by 
// push. 
    struct Node{
        shared_ptr <Node> previous;
        int data = 0;
    };
//-----------------------------------------------------------------------------
//Position pointers
    shared_ptr <Node> current = NULL;
    shared_ptr<Node> head = NULL;

};
