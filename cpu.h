#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include "stack.h"
#include "queue.h"
using namespace std;

class CPU{
   public:
//-----------------------------------------------------------------------------
//loads program with an input file
   void LoadProgram(string toload);

//-----------------------------------------------------------------------------
//Used to run the program
//Run- runs the full queue using the stack values,
//Next- runs the next command, returns 0 if successful, -1 if not
   void switchHelper();
   int Run();
   int Next();

//-----------------------------------------------------------------------------
//Math functions that preform the Commands in the command queue
   void ADD();
   void SUB();
   void MULT();
   void DIV();
   void CMP();


//-----------------------------------------------------------------------------
//Overloaded output operator, used to print the full queue and stack
   friend ostream &operator <<(ostream &output, const CPU &outCPU);

   private:
   
   int firstVal = 0;
   int secondVal = 0;
  
   stack CPUstack;
   queue CPUqueue;

};
