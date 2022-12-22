#include "stack.h"

//-----------------------------------------------------------------------------
//Push- creates a new node, attaches it to the stack, and fills the nodes data
// Checks to see if the stack is empty before creating a new node
void stack :: push(int topush){

    if(size == 0){
        shared_ptr<Node> temp (new Node);
        head = temp;
        current = temp;
        temp->data = topush;
        size = size + 1;
    }
    else{
        shared_ptr<Node> temp (new Node);
        temp->previous = current;
        temp->data = topush;
        current = temp;
        size = size + 1;
    }
}


//-----------------------------------------------------------------------------
//Pop- pulls a node off the stack, returns the nodes data
int stack :: pop(){
    int hold = 0;
    shared_ptr<Node>popHold;

    if(current != NULL){
        hold = current->data;
        popHold = current->previous;
        current->previous = NULL;
        current = popHold;
    
        size = size - 1 ;
    }
    return hold;
}

//-----------------------------------------------------------------------------
//Print- prints the full stack contents using a temporary print pointer
// called later in the program by overloaded << operator for CPU
void stack :: print()const{
    shared_ptr<Node>print;
    print = current;
    
    while(print != NULL){
        cout << print->data << "    ";
        print = print->previous;
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------