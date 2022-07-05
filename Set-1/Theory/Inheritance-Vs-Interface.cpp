/************************************************
       Inheritance vs Interface
**************************************************/
//Interface : An Interface is a programmatic contract. It defines the required functions that must be implemented by a class for it to meet that contract.

interface IVehicle {
void Move(); // This defines that any implementing class must have this method
}

//Inheritance : Inheritance is an element of object oriented programming that allows similar objects to inherit functionality and data from each other.

class Vehicle : IVehicle {
void Move() { ... do something here... }
}

class Car : Vehicle {
// Does not need to implement Move() because it inherits it from Vehicle
}