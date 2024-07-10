#include <iostream>
#include <cstring>
using namespace std;

/*
// -------------------------------
// ostream overloading ex cout
// ------------------------------- 

class Youtubedetails{
    private:
        char youtubechannelname[200];
        int subscriber;
    
    public:
        //default constructor
        Youtubedetails();
        //parameterized constructor
        Youtubedetails(const char *name, int subs);
        //OPERATOR FUNCTION
        friend ostream& operator << (ostream& COUT, Youtubedetails& yt); //here ostream& is return type as cout is an ostream
};

Youtubedetails::Youtubedetails(){
    youtubechannelname[0] = '\0'; // this means the c-string is nullpointed it will contain no value
    subscriber = 0;
}

Youtubedetails::Youtubedetails(const char name[], int subs){
    strcpy(youtubechannelname, name);
    subscriber = subs;
}

ostream& operator << (ostream& COUT, Youtubedetails& yt){ //as i wanted to print cout << yt1 and yt1 has 
    COUT << "Youtube Name: " << yt.youtubechannelname << endl;
    COUT << "Subscriber: " << yt.subscriber << endl;
    
    return COUT;
}

int main(){
    Youtubedetails yt1 = Youtubedetails("MRbeast", 20000);
    cout << yt1;
    Youtubedetails yt2 = Youtubedetails("codebeauty", 10000);
    cout << yt2;
    
    //or we can directly print cout << yt1 << yt2; it will provide the same value;
    
    return 0;
}

*/



// -------------------------------
// binary overloading +
// ------------------------------- 

class Test{
    private: 
    int number;

    public:
    //default constructor
    Test();
    //parameterized constructor
    Test(int num);
    //operator function
    Test operator + (Test nextnum) const;
    // display
    void display() const;
};

Test::Test(){
    number = 0;
}

Test::Test(int num){
    number = num;
}

Test Test::operator + (Test nextnum) const { 
    Test sum;  
    sum.number = number + nextnum.number; // here number is always the first instance which is t1 and nextnum.number is right one which is t2
    return sum;
     
}

void Test::display() const {
    cout << "Number: " << number << endl;
}

int main(){
    Test t1 = Test(10);
    Test t2 = Test(20);
    Test t3 = Test(20);
    Test t4 = t1 + t2 + t3;

    t4.display();
    
    
    return 0;
}

