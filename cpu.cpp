#include "cpu.h"


//-----------------------------------------------------------------------------
//LoadProgram- uses an input file to load program. parses file based on input
// commands to be added to the command queue
void CPU :: LoadProgram(string toadd){
    ifstream infile(toadd);
    string line;

    while(infile){
        infile >> line;

        if(line == "PSH"){
            infile >> line;
            int num = stoi(line);
            CPUstack.push(num);
        }
        else {
            CPUqueue.push(line);
        }

        if (infile.eof()){
            break;
        }
    }  
}


//-----------------------------------------------------------------------------
//Run- Runs the full program. This function goes through the whole command
// queue and runs the commands if there are enough values in the stack to run
// them. if not, clears the remaining command queue to be re populated
int CPU :: Run(){

    while (CPUqueue.size > 0){

        if(CPUstack.size == 1){
            cout << "only one variable left in the stack\n";
            cout <<"Cannot complete operations\n";
            cout << "returning final value\n";

            while(CPUqueue.size > 0){
                CPUqueue.pop();
            }
            break;
        }

        switchHelper();  
    }

    if(CPUqueue.size == 0 && CPUstack.size >=2){
        cout << "Error, not enough commands to clear the stack\n";
        return -1;
    }
    
    cout << "\nRuns output: ";
    return CPUstack.pop();
}

//-----------------------------------------------------------------------------
//Next- Performs the same functionality as next but only for the next command
// returns 0 if command can be ran and -1 if command cannot be run
int CPU :: Next(){
    if (CPUqueue.size > 0){
        if (CPUstack.size == 1){
            cout << "only one variable left in the stack\n";
            cout <<"Cannot complete operations\n";
              while(CPUqueue.size > 0){
                CPUqueue.pop();
            }
            return -1;
        }
        else{
            switchHelper();
            return 0;
        }
    }
    else{
        return -1;
    }
}

//-----------------------------------------------------------------------------
//switchHelper- Switch helper is called by run and Next. used to determine what
// command is going to be ran. uses a switch to determine what command to run
void CPU :: switchHelper(){
    int stringVal = 0;
    stringVal = CPUqueue.pop();

    switch(stringVal){
        case 201: //201 == ADD
            ADD();
        break;

        case 234: //234 == SUB
            SUB();
        break;
                                    //Numeric values assigned to strings in 
        case 322: //322 == MULT     // queue.pop(). See queue.pop() for 
            MULT();                 // more info
        break;

        case 227: //227 == DIV
            DIV();
        break;

        case 224: //224 == CMP
            CMP();
        break;

        default:
            cout << "not a recognized command\n";
        break;
    }
} 

//-----------------------------------------------------------------------------
//Add,SUB,MULT,DIV,CMP- Simple math operators; add, subtract, multiply, divide,
// compare
void CPU :: ADD(){
    
    firstVal = CPUstack.pop();
    secondVal = CPUstack.pop();
    CPUstack.push(firstVal + secondVal);
}
    
//-----------------------------------------------------------------------------
void CPU :: SUB(){

    firstVal = CPUstack.pop();
    secondVal = CPUstack.pop();
    CPUstack.push(secondVal - firstVal);
}

//-----------------------------------------------------------------------------
void CPU :: MULT(){
    
    firstVal = CPUstack.pop();
    secondVal = CPUstack.pop();
    CPUstack.push(secondVal * firstVal);
}

//-----------------------------------------------------------------------------
void CPU :: DIV(){
   
    firstVal = CPUstack.pop();
    secondVal = CPUstack.pop();

    if(firstVal != 0){
        CPUstack.push(secondVal / firstVal);
    }
    else if(firstVal == 0){
        cout << "cannot divide by 0\n";
    }
}

//-----------------------------------------------------------------------------
void CPU :: CMP(){
        
    firstVal = CPUstack.pop();
    secondVal = CPUstack.pop();

    if(firstVal >  secondVal){
        CPUstack.push(1);
    }
    if (firstVal == secondVal){
        CPUstack.push(0);
    }
    if(firstVal < secondVal){
        CPUstack.push(-1);
    }
}

//-----------------------------------------------------------------------------
//Overloaded <<- used to print out the full queue and stack values. 
ostream &operator <<(ostream &output, const CPU &outCPU){
    cout << endl;
    outCPU.CPUqueue.print();
    cout << endl;
    outCPU.CPUstack.print();

    return output;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------