/* ***********************************************
                     STACK Vs HEAP
**************************************************/


// Application Memory:
// Application memory includes following types of memory:
// 1) Code : Stotes all instructions that need to be executed (Fixed Size)
// 2) Static and Global : Stores Sstatic and global variables (Fixed Size)
// 3) Stack : Stores local variables, function calls (Fixed Size)
// 4) Heap : Gets allocated with dynamic memory allocation(Grows with the application)

// STACK
// -> Fixed Size and if exceeded by bad recursion it leds to Stack Overflow
// -> Actual allocation of local variable happens in run time.
// -> Allocation and delocation happens by a set rule i.e when function call happens it is pushed on the top of stack and after complition it is poped from the stack.
// -> Scope of the variable cannot be manipulated if it is on stack.
// -> Memory calculation is done in compile time.


// HEAP
// -> Heap grows with the program unlike STACK.
// -> Allocation and delocation does not happen by a set of rules. Programmer can allocate or deallocate as per the programmer's demand.
// -> Heap is called free pool of memory or free store of memory.
// -> It is used for dynamic memory allocation.

#include<stdio.h>   
#include<stdlib.h>                                           
int total;       //Global variable stores in global/static memory section                                    
								                                                                        
int square(int x){ //Function argument x get stored in stack                        
	return x*x;                          
}                                          
							                                          
int squareSum(int x, int y){  //Function argument x, y get stored in stack                                  
	int z = square(x+y);      // Local variables a and b stores in stack             
	return z;                                
}                                               
							                 
int main(){                                                              
	int a = 4, b = 8;      //local variables a and b stores in stack                        
	total = squareSum(a, b);                 
	printf("output = %d", total);
	int *p; //p goes in stack but points memory to heap
	p = (int*) malloc(sizeof(int)); //memory allocation
	*p = 10;
	free(p); //freeing the memory                                                                    
} 




	

	
	
       