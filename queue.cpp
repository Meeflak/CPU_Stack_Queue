#include "queue.h"

//-----------------------------------------------------------------------------
//Push- pushes a new node onto the queue. dynamically allocated and loaded with
// a string. checks to see if queue is empty when the nodes are being added
// and links nodes together with pointers
void queue :: push(string topush){
     
    if (head == NULL){

        shared_ptr<Node> temp (new Node);
        temp->data = topush;
        head = temp;
        current = temp;
        temp->next = NULL;
        size = size + 1;
    }
    else{

        shared_ptr<Node> temp (new Node);
        temp->data = topush;
        current->next = temp;
        current = temp;
        temp->next = NULL;
        size = size + 1;
    }
}

//-----------------------------------------------------------------------------
//Print- prints full queue. called later in the program by overloaded << CPU
// operator
void queue :: print()const{
    shared_ptr<Node> printPoint = head;

    while(printPoint != NULL){
        cout << printPoint->data <<  "  ";
        printPoint = printPoint->next;
    }
}

//-----------------------------------------------------------------------------
//Pop- pops the next node from the queue and returns an int. 
// A for loop calculates the value of a strings chars and adds them together.
// The final value of a strings chars are returned as an int to be used in a 
// switch statement in CPU.run() and CPU.next()
// command string totals...
// ADD = 201
// SUB = 234
// MULT = 322
// DIV = 227
// CMP - 224
int queue :: pop(){
    int stringInt = 0;
    shared_ptr<Node> holdPoint;
    string hold;
    
    if(size > 0){
        hold = head->data;
        holdPoint = head->next;

        head->next = NULL;
        head = holdPoint;
        
        size = size - 1; 
    }
    else if( size <= 0){
        cout << "\n\n nothing left to pop\n\n";
    }

    for (int i = 0; i < hold.size(); i++){
        
        stringInt = stringInt + int(hold[i]);  //Forces the chars of the string
    }                                          // into ints
    
    return stringInt;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------