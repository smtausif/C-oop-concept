Inheritance is one of the key concepts in object-oriented programming. 
It allows a new class (called the derived class or child class) to inherit
properties and behaviors (methods) from an existing class (called the base class or parent class). 

This helps to reduce code duplication and create a more logical structure for your programs.

By this we can add new features to the derived class without affecting the base class.
in that case we can use both functionality from base class and derived class for the derived one.

syntax to make derived class
class Derivedclassname : public Baseclassname {
    // ...
};

Base class:

            Definition: A base class (also known as a parent class or superclass) is a class that provides properties and methods that can be inherited by other classes.
            
            Purpose: It serves as a foundation for creating more specific subclasses.

            Example:

            class Animal {
            public:
                void eat() {
                cout << "Eating..." << endl;
                }
            };


