#include <iostream>
#include <cstring>
using namespace std;

/// -----------------base class------------------//

class Person{
    protected: // i have used protected instead of private cz derivaed class cant use base class's private members..
        char name[20];
        int age;

    public:
        Person(); // default constructor
        Person(const char *p_name, int p_age); // parameterized constructor
        Person(const Person& source); // copy constructor
        Person& operator = (const Person& source); // copy assignment constyructor
        void display() const; // printing name and age;
};

Person::Person(){
    strcpy(name, "No name");
    age = 0;
}

Person::Person(const char *p_name, int p_age){
    strcpy(name, p_name);
    age = p_age;
}

Person::Person(const Person& source){
    strcpy(name, source.name);
    age = source.age;
}

Person& Person::operator = (const Person& source){
    strcpy(name, source.name);
    age = source.age;

    return *this;
}

void Person::display() const{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}


///------------------dervided class----------------//


class Student : public Person{
    private:
        int studentId;
        char studentSection;

    public:
        Student(); // deafult constructor
        Student(const char *p_name, int p_age, int p_studentId, char p_student); //parameterized constructor
        void age_and_sec() const;
};

Student::Student(){
    strcpy(name, "No Name"); // here "name" i am using it from base class thats why i have protected my member variables from base class
    age = 0; // same i am using age from base class
    studentId = 0;
    studentSection = ' ';
};

Student::Student(const char *p_name, int p_age, int p_studentId, char sec){
    strcpy(name, p_name);
    age = p_age;
    studentId = p_studentId;
    studentSection = sec;
}

void Student::age_and_sec() const{
    cout << "Student Id: " << studentId << endl;
    cout << "Student Section: " << studentSection << endl;
    
}


//---------------main function-------------//

int main(){

    // From base class

    Person person1 = Person("SM Tausif", 22);
    person1.display();
    cout << "\n" << endl;

    Person person2(person1); // copy constructor
    person2.display();
    cout << "\n" << endl;

    Person person3 = Person("Rohit Yadav", 12);
    person3 = person2; //copy assignment constructor
    person3.display();
    cout << "\n" << endl;

    // Derived class

    Student student1 = Student("Ruksar", 21, 123, 'A');
    student1.display(); // i am using display from base class cz i have no diplay funrtion in my derived class
    student1.age_and_sec(); // i am using age_and_sec from derived 



    return 0;
}
