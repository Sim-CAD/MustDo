/************************************************
       INHERITANCE
**************************************************/

// INTRODUCTION:
// ->OOPs concept where Derive class inherits the features/properties of the Base class.
// ->It provides code reusability.
// ->Easily create an Interface.
// ->We only derive a class when we can satisfy IS-A relationship with a base class. eg Vechicle as Base class and car as Derived class, car Is-A vechicle and not vise-versa.


// TYPES:
// 1) Single Inheritance: 1 base class and 1 derive class (single level)
// 2) Multilevel Inheritance: multiple single inheritance, 1 base class has 1 derived class which also a base class of its another derived class. i.e A base class has derive class B and B has a derive class C. ((multiple level))
// 3) Mutiple Inheritance: 1 derive class from more than 1 base class
// 4) Heirarchical Inheritance: 1 base class and deriving multiple derived class
// 5) Hybrid Inheritance: combination of mutiple and heirarchical inheritance.
// 6) Multiplath Inheritance: A derived class (D) with 2 base classes ( B and C) and these base classes have one common base class (A).


// MODES: (Access Specifier)
// 1) public : visible to everyone
// 2) protected : visible to current class and derived class only.
// 3) private : visible only to the current class


// Notes:
// -> Base class : private items
//    Inheritance mode : public     ||  private      ||  protected
//    Derived class : Not inherited || Not inherited || Not inherited

// -> Base class : protected items
//    Inheritance mode : public   ||  private   || protected
//    Derived class : protected   ||  private   || protected

// -> Base class : public items
//    Inheritance mode : public   ||  private   || protected
//    Derived class : protected   ||  private   || protected


/********************************************************************* Single Inheritance Example***********************************************************************/
class Base{
protected:
        int x;
};

class Derived : public Base{
public:
    void print(){
        cout<< x<<endl;
    }
};

int main(){
    Derived D;
    D.print(); //No error

    cout << D.x<<endl; //Error
    return 0;
}

/******************************************************************* Multilevel Inheritance Example ********************************************************************/

class Animal {};
class cat : public Animal {};
class RussianBlueCat : public cat {};

// ->cat IS-A Animal
// ->RussianBlueCat IS-A Cat ans IS-A Animal as well.


/*****************************************************************  Mutiple Inheritance Example ***********************************************************************/
//->There is a ambiguity problem in multiple inheritance.

class Youtuber{
public:
    Youtuber(){
        cout<<"Youtuber"<<endl;
    }
    void work(){
        cout<<"Working on Youtube!"<<endl;
    }
};
class Engineer{
public:
    Engineer(){
        cout<<"Engineer"<<endl;
    }
     void work(){
        cout<<"Working on Engineer!"<<endl;
    }
};
class Smriti : public Youtuber, public Engineer{
public:
    Smriti(){//Compiler changed this into Smriti() : Youtuber(), Engineer()
        cout<<"Smriti"<<endl;
    }
};

int main(){
    Smriti s;
    s.work(); //Ambiguity
    return 0;
}

// Output:
// Youtuber
// Engineer
// Smriti

//NOTES:
//Compiler calls  constructor automatically in the sequence the class has been inherited.
//If the object is created without any parameter we need not to explicitly write the constructor call of the inherited class.
//However, if we have parameterized creation of the object then we need to call the inherited class constructor.
//Constructor is called in the sequence starting with Yotuber then Engineer and then Smriti and the distructor is called in the sequence of Smriti, Engineer and Youtuber
//Problem is Ambiguity as two base classes i.e Youtuber and Engineer has same work(). Compiler is confused which work() to call.

//Solve the ambugity:
// 1) Explicitily mention the class name:  s.Youtuber::work(); 
// 2) Slicing: Youtuber y = s;  y.work(); 
// 3) Using static cast: static_cast<Engineer>(s).work(); 



/**************************************************************************Heirarchical Inheritance Example**************************************************************/


class Human{
public:
    Human(){
        cout<<"Human"<<endl;
    }
     void eat(){ //Common function with same functionality from the derived class pulled to base class
        cout<<"food"<<endl;
    }
};
class Youtuber: public Human{
public:
    Youtuber(){
        cout<<"Youtuber"<<endl;
    }
    void work(){
        cout<<"Making videos"<<endl;
    }
   
};
class Engineer: public Human{
public:
    Engineer(){
        cout<<"Engineer"<<endl;
    }
    void work(){
        cout<<"Making projects"<<endl;
    }
};
class Doctor: public Human{
public:
    Doctor(){
        cout<<"Doctor"<<endl;
    }
    void work(){
        cout<<"Saving life"<<endl;
    }
};

int main(){
    Human* h;
    Youtuber y ;
    y.eat();
    y.work();
    return 0;
}


/**************************************************************************Hybrid Inheritance Example**************************************************************/
//->Multiple + Hierarchical Inheritance = Hybrid Inheritance

class Student{
public:
    void studying(){
        cout<<"Studying"<<endl;
    }
};
class Male{};
class Female{};
class Boy : public Student, public Male{};
class Girl: public Student, public Female{};


int main(){
    Boy Hari;
    Hari.studying();

    Girl Laxmi;
    Laxmi.studying();
    return 0;
}

//Multiple Inheritance
//->Boy is inheriting two base classes male and student
//->Girl is inheriting two base classes female and student

//Hierarhial Inheritance
//->Boy and girl is inheriting from Student base class.



/**************************************************************************Multipath Inheritance Example**************************************************************/
//->Multiple path from derive class to base class.
//->Special case of hybrid inheritance.
//->Diamond Problem

class Human{
public:
    void breathing() { cout<<"I am breathing"<<endl;}
};
class Youtuber: public Human{};
class Engineer: public Human{};
class Smriti: public Youtuber, public Engineer{};

int main(){
    Smriti s;
    s.breathing(); //Error as Smriti will have two breathing funtions, one coming from youtube and other from engineer
    return 0;
}

//Solution to the problem
//-> We have to inherit the base class virtually to avoid the extra copy.

class Youtuber: public virtual Human{};
class Engineer: public virtual Human{};