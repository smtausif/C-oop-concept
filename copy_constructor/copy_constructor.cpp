/*
1) a copy cons should be in oublic area in your class
2) it doesnt have return type
3) it shares the same name of class
4) copy constuctor receives one parameters and that parameter should be the same type
    as the class
*/

#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
    char title[200];
    char author[200];
    float *rates; // dynamic memory allocation 
    int rateCounter; // for alocating dymanic memory 

    public:
    Book(const char *titleofbook, const char *authorname); // parameterized constructor
    Book(const Book& original); // copy constructor: its in public scope, shares same class name, it received on parameter with the same class, dont forget to add const and pass it by refference
    ~Book(); // destructor: as we have using the dynamic memory we have to delete it other wise we will have memory leak problem
    void display() const;
};


// parameterized constructor: here ill copy the given title of the book and the author to my member variables and dynamically alocate memory for rates
Book::Book(const char *titleofbook, const char *authorname){
    strcpy(title, titleofbook);
    strcpy(author, authorname);
    rateCounter = 2;
    rates = new float[rateCounter];
    rates[0] = 5;
    rates[1] = 4;
    
}

//copy constructorr
//when its about copyting a dyunamially allocated memory we have to make a memory again and use a for loop.
Book::Book(const Book& original){
    strcpy(title, original.title);
    strcpy(author, original.author);
    rateCounter = original.rateCounter;
    rates = new float[rateCounter]; // allocate memory for rates again otherwise cz of the deallocation it will copy and delete again so we wont have anything
    for (int i = 0; i < rateCounter; i++) {
        rates[i] = original.rates[i];
    }
    

}

//destructor
Book::~Book(){
    delete [] rates;
    rates = nullptr;
}

//displaying books
void Book::display() const{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Rate: " << rates[0] << endl;
    cout << "Rate: " << rates[1] << endl;
}

int main(){
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    //Book book2(book1);
    Book book2 = book1; // they are same we are just copyting an object from one to another.
    book2.display();
}