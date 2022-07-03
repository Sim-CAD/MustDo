/* ***********************************************
        TYPES OF COMPILER OPTIMIZATIONS
**************************************************/

//We are going to discuss about two types of compiler optimizations:
//a) SIMD
//b) Loop unrolling
//c) Return Value Optimization (RVO)

// a) SIMD(Single Instruction Multiple Data):

// Introduction
// ->It is an instruction set.
// ->It gives data level parallelism. i.e Single instruction is executed parallel on multiple data points similar to multiple instructions.
// ->SIMD based program is called vectorization.
// ->It improves the performance of applications.
// ->It has 128 bits ( 4 * 32) i.e 4 Integers can be stores in 128 bits register.

eg: C[i] = B[i] + A[i]; is in a  loop.

// ->In each iteration we have :
//         -> 2 loads for loading the a single value to A and B
//         -> 1 add for adding A and B
//         -> 1 store for storing the value to C
// Hence, total number of CPU cycles = 4 in one cycle
// So total number of CPU cycles = 4* number of iterations

// Using SIMD we can reduce the number of CPU cycles of the entire iterations
//         ->1 load can load 4 A values
//         ->1 load can load 4 B values
//         ->1 add can add for 4 different values of A and B
//         ->1 store can store 4 differnt values in C
// Hence, total number of CPU cycles are now reduced.

// Implementation
// 1) Either write a code in such a way that compiler is able to vectorize and hence SIMD can be applied.
// eg: SIMD cannot work in the code with the dependency.


for(int i = 0 ; i < 998; i++){ //SIMD cannot work here as we have dependency.
    a[i] += b[i];
    b[i+1] += c[i]; 
}

a[0] += b[0];  //SIMD can work here as we now removed dependency
for(int i = 0; i < 998; i++){
    b[i+1] += c[i];
    a[i+1] += b[i+1];
}
// 2) Programmer in the code can use compiler intrinsics to get SIMD advantages.

/******************************************************************************************************************************/

// b) Loop unrolling:
// -> Loop tranformation technique
// -> optimizes the execution time.
// -> Increses the code size.

//Original Code
for(int i = 0; i < 2; i++)
    cout << "Hello";

        vs
//Optimized code after loop unrolling
cout<<"Hello";
cout<<"Hello";


/*******************************************************************************************************************************/

// c) Return Value Optimization(Copy Elision)
//-> It avoids unnecessary call to the constructors.
//-> Return-value optimization is a compiler technique to avoid copying an object that a function returns as its value, including avoiding creation of a temporary object.
//-> It helps to save memory and time.
//->As of C++17, Copy Elision is guaranteed when an object is returned directly.

class Base{
    public:
    Base(){
        cout<<"Constructor of Base "<<endl;
    }
    Base(const Base &){
        cout<<"Copy constructor Of Base "<<endl;
    }
};
Base fun1(){
    return Base();
}

int main(){
    Base b = fun1();
    //This calls fun1()
    //Which creates object of Base class
    //For creation default constructor is called.
    //After the object is created, the same object is returned.
    //For returning it creates a temporary object by calling copy constructor.
    //Finally, the temp object will get copied to object b so one more time copy constructor gets called.
    return 0;
}

// Without compiler optimization expected Output:(use flag -fno-elide-constructors)
// Constructor of Base
// Copy constructor of Base
// Copy constructor of Base

//With compiler optimization the output is:
// Constructor of Base
       

