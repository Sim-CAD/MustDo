/\* **********************\*\*\***********************
STACK Vs HEAP
************************\*\*************************/

Application Memory:

|------------|  
| Haep |->Gets allocated with dynamic memory allocation(Grows with the application)
| |
| |
|------------|
| |
| Stack |->Stores local variables, function calls (Fixed Size)
| |
|------------|  
| |
| Static/ |
| Global |-> Static and global variables (Fixed Size)
| |
|------------|  
| Code |-> Stotes all instructions that need to be executed (Fixed Size)
| |
|------------|

#include<stdio.h>  
int total;  
   
eg:  
int square(int x){  
 return x\*x; STACK 1 STACK 2
} |------------|  
 | | -> Function at the top will execute first. | |  
int squareSum(int x, int y){ | | -> Once completed it will get poped from stack. |--------|  
 int z = square(x+y); | | |printf()|
return z; | Square | | |
} | | |--------|  
 |------------| | |
int main(){ |Square sum | | main() |
int a = 4, b = 8; | x, y, z | |--------|  
 total = squareSum(a, b); |------------|  
 printf("output = %d", total); | main() | -> memory allocated to main (Stack frame)
|------------| -> It has memory for its local variables, arguments,
return memory address
} -> Size is calcutated at compile time

STACK
-> Fixed Size and if exceeded by bad recursion it leds to Stack Overflow
-> Actual allocation of local variable happens in run time.
-> Allocation and delocation happens by a set rule i.e when function call happens it is pushed on the top of stack and after complition it is poped from the stack.
-> Scope of the variable cannot be manipulated if it is on stack.
-> Memory calculation is done in compile time.

HEAP
-> Heap grows with the program unlike STACK.
-> Allocation and delocation does not happen by a set of rules. Programmer can allocate or deallocate as per the programmer demands.
-> Heap is called free pool of memory or free store of memory.
-> It is used for dynamic memory allocation.

#include<studio.h>
#include<stdlib.h>

int main(){
int a; //goes in stack
int _p; //p goes in stack but points memory to heap
p = (int_) malloc(sizeof(int));
\*p = 10;
free(p);
}
STACK HEAP
|------------| |---------|  
| | | |
| | | |
| | |---------|  
|------------| --->| memory | ->p is pinting to the memory allocated in Heap  
| main() | | |---------|  
| p | --------| | |
|------------| |---------|
