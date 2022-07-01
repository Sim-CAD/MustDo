/* ***********************************************
                     TEMPLATE
**************************************************/

// 1) We use templates for function and class. Hence we have:
//     a) Function templates Syntax: template<typename name1, typename name2, ...>
//     b) Class templates Syntax: template<typename  name> class className{..};
// 2) It is used to write generic programs.
// 3) Important point is that we pass data type as parameter to function or class.
//
//Disadvantage
//1) Slow the compiler
//2) Error messages are not helpful
//3) The implementation is exposed
//4) Difficult to debug the code as compiler has replaced the code.
//5) All code is exposed in the header file

//B.Stroustrup's Views
//1)Prefer a template over derived classes when run-time efficiency is at a premium
//2)Prefer derived classes over a template if adding new variants without recompilation is important
//3)Prefer a template over derived classes when no common base can be defined
   

#include<iostream>
using namespace std;

/* FUNCTION TEMPLATE STARTS*/
// int getMaxInt(int x, int y){
//     return x > y? x : y;
// }

// char getMaxChar(char x, char y){
//     return x > y? x : y;
// }

//Template function
//Compiler will create seperate functions with different data types at compile type
//Similar to getMaxInt() and getMaxChar() as per the call
template<typename T>
T getMax(T x, T y){
    return x > y ? x : y;
}
/* FUNCTION TEMPLATE ENDS*/





/*****************************************************************/




/* CLASS TEMPLATE STARTS*/

// class ArrayList{
// private:
//     struct ControlBlock{
//         int capacity;
//         int* arr_ptr;
//     };
//     ControlBlock *s;
// public:
//     ArrayList(int capacity){
//         s = new ControlBlock;
//         s->capacity = capacity;
//         s->arr_ptr = new int[s->capacity];
//     }

//     void addElement(int index, int data){
//         if(index >= 0 && index <= s->capacity - 1)
//             s->arr_ptr[index] = data;
//     }

//     void printAll(){
//         for(int i = 0; i < s->capacity; i++){
//             cout<<s->arr_ptr[i]<<" ";
//         }
//     }
// };

template<class T>
class ArrayList{
private:
    struct ControlBlock{
        int capacity;
        T* arr_ptr;
    };
    ControlBlock *s;
public:
    ArrayList(int capacity){
        s = new ControlBlock;
        s->capacity = capacity;
        s->arr_ptr = new T[s->capacity];
    }

    void addElement(int index, T data){
        if(index >= 0 && index <= s->capacity - 1)
            s->arr_ptr[index] = data;
    }

    void printAll(){
        for(int i = 0; i < s->capacity; i++){
            cout<<s->arr_ptr[i]<<" ";
        }
    }
};

/* CLASS TEMPLATE ENDS*/

int main(){
    int x = 18, y = 20;
    char c1 = 'a', c2 = 'x';
    // cout<<getMaxInt(x,y)<<endl;

    // //Above function will be incompatible hence we need to create a new function getMaxChar()
    // cout<<getMaxChar(c1, c2)<<endl;

    //Rather than that let's create a Function Template that works for both datatypes
    cout<<getMax<int>(x,y)<<endl;
    cout<<getMax<char>(c1, c2)<<endl;


    // ArrayList obj(5);
    // obj.addElement(0, 4); //only int type data type is supported
    // obj.printAll();

    ArrayList <int>obj1(4);
    obj1.addElement(0,4);
    obj1.printAll();

    ArrayList <int>obj2(4);
    obj2.addElement(0,4.00);
    obj2.printAll();

return 0;
}