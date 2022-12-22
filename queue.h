#pragma once

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class queue{

  public:
  int size = 0;
//-----------------------------------------------------------------------------
//Mutators for queue
  void push(string topush);
  int pop();

//-----------------------------------------------------------------------------
//Print- prints queue
  void print()const;


  private:

  //-----------------------------------------------------------------------------
  //Node struct- used to store a postition pointer and data variable
  struct Node{
    shared_ptr <Node> next;
    string data;
  };

//-----------------------------------------------------------------------------
//Positional pointers
  shared_ptr <Node> current = NULL;
  shared_ptr<Node> head = NULL;

};