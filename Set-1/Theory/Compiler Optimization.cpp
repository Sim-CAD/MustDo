/* ***********************************************
        TYPES OF COMPILER OPTIMIZATIONS
**************************************************/

//We are going to discuss about two types of compiler optimizations:
//a) SIMD
//b) Loop unrolling

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

       

