// copy assignment constrcutor helps us to replace the value of two wxisting objects 
// for example we have created movie1 and movie2 objects and bith has values 
// so we wannt to replace movie2 values by movie1 values.

#include <iostream>
#include <cstring>
using namespace std;


class Movie{
    private:
    char title[200];
    float year;
    int rating;

    public:
    Movie(const char *title, int year, float rating); // parameterized constructor
    Movie(const Movie& source); // copy constructor
    Movie& operator = (const Movie& source); //copy assinment constructor
    ~Movie(); // destructor
    void display() const;
};

Movie::Movie(const char *title, int year, float rating){
    strcpy(this->title, title); //here we are using this because the arguments and the mamber variables shares the same name so to indicate member variables we use this
    this->year = year;
    this->rating = rating;
}

Movie::Movie(const Movie& source){ //copy constructor where i can copy an existing object to a new object
    strcpy(this->title, source.title);
    this->year = source.year;
    this->rating = source.rating;
}

Movie& Movie::operator = (const Movie& source){
    strcpy(this->title, source.title);
    this->year = source.year;
    this->rating = source.rating;
    return *this;
}

Movie::~Movie(){}; 

void Movie::display() const{
    cout << title << ", " << year << ", " << rating << endl;
}


int main(){

    Movie movie1("The Godfather", 1972, 9.2);
    Movie movie2("Goodfellas", 1990, 9.2);
    Movie movie3("Casablanca", 1942, 8.9);

    Movie movie4(movie1); //it means we are copying movie1 to movie4.
    movie4.display(); // here i have succesfully copied the movie1 to movie4 and displaying it its an example of copy constructor

    //but now as i have both movie1 and movie2 objects (they already exist) so i can replae the value between them
    movie1 = movie2; // here i am replacing the value of movie1 with movie2
    movie1.display(); 

    return 0;
}