/************************************************
       POLYMORPHISM
**************************************************/
//INTRODUCTION:
// -> Two types of Polymorphism
// a)Compile Time Polymorphism / Static / Early binding
//     i)Function Overloading
//     ii)Operator Overloading
// b)Runtime Polymorphism / Dynamic/ Lazy Binding
//     i)Function Overriding (using virtual function)

/********************************************************************Function Overloading Example************************************************************************/
//-> Same name but dufferent argument.
class Test{
public:
    void fun(int x){
        cout<<"Integer"<<endl;
    }

    void fun(double x){
        cout<<"Double"<<endl;
    }
}
int main(){
    Test t1;
    t1.fun(10);
    t1.fun(10.5);
    return 0;
}

/****************************************************************************Operator Overloading Example***************************************************************/
class Complex{
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0): real {r}, imag{i} {}
    Complex operator + (Complex const &obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.real;
        return res;
    }
    void show(){
        cout << real <<" + i"<<imag<<endl;
    }
};

int main(){
    Complex c1{1,3}, c2{2,5};
    Complex c3 = c1 + c2; // c1 is a calling object and c2 goes as a parameter to the function
    c3.show();
    return 0;
}

/*****************************************************************************Run time Polymorphism Example**************************************************************/

class Base{
public:
    virtual void fun() {
        cout<<"Base"<<endl;
    }
};

class Derived{
public:
    void fun() {
        cout<<"Derived"<<endl;
    }
};

int main(){
    Base *b = new Derived(); 
    b->fun();
    return 0;
}

//->Expectation is that we want derive function to get called but we end up calling base fun().
//->To correct the implementation, we need to implement run time polymorphism by making the override function "virtual" in base class.
