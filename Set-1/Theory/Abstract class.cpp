/************************************************
       Pure Virtual Function
**************************************************/

->If class has only signature of function but not the body then we use pure virtual function.
->Sometimes Base class only knows prototype of the function and wants derive class to provide definition.
->We can give body of pure virtual function.
->If we have pure virtual function in the class, it means the class is an ABSTRACT class and we cannot create an object of that class. (But pointer and reference can be created)
->We must give the defination in the derived class otherwise it will give an error.
-> This helps in crating APIs.


class Animal{
public:
    virtual void move() = 0; //Move functionality is defined by derived class
};

//Body of the virtual function
void Animal::move(){
    cout<<"This is Animal class"<<endl;
}

class Cow: public Animal {
public:
    void move(){
        Animal::move();
        cout<<"I walk and run"<<endl;
    }
};

class Snake: public Animal {
public:
};

int main(){
    Animal a; //cannot create object, it will give error
    Animal *a; //This will work
    Snake s; //Snake did not provide defination of the pure virual function move(). Hence, it will give an error.
    return 0;
}

