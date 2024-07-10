#include <iostream>
#include <cstring>

using namespace std;

/*-----------------------------Base class------------------------------------*/
class Youtubechannel{
    protected:
    //member variables//
    char *channel_name; // i want to dynamicall allocate memory
    int subscribers;

    public:
    //default constructor
    Youtubechannel();

    //parameterized constructor//
    Youtubechannel(const char *name, int sub);

    //copy constructor
    Youtubechannel(const Youtubechannel& source);

    //copy assignment operator
    Youtubechannel& operator = (const Youtubechannel& source);

    //destructor
    ~Youtubechannel();

    //displaying youtube channel name and subscribers
    void display() const;
};

Youtubechannel::Youtubechannel(){
    channel_name = nullptr;
    subscribers = 0;
}

Youtubechannel::Youtubechannel(const char *name, int sub){
    channel_name = new char(strlen(name)+1); 
    strcpy(channel_name, name);
    subscribers = sub;
}

Youtubechannel::Youtubechannel(const Youtubechannel& source){
    channel_name = new char(strlen(source.channel_name)+1); //i have to fynamically allocate again for copying ther name
    strcpy(this->channel_name, source.channel_name);
    this->subscribers = source.subscribers;
}

Youtubechannel& Youtubechannel::operator=(const Youtubechannel& source){
    strcpy(this->channel_name, source.channel_name);
    this->subscribers = source.subscribers;
    return *this;
}

void Youtubechannel::display() const{
    cout<<"Youtube Channel Name: "<<channel_name<<endl;
    cout<<"Subscribers: "<<subscribers<<endl;
    cout<<"\n"<<endl;
}

Youtubechannel::~Youtubechannel(){
    delete[] channel_name;
    channel_name = nullptr;
}
/*-----------------------------end of Base class------------------------------------*/

class youtubername:public Youtubechannel{
    protected:
    char *youtuber_name;
    int no_of_videos;

    public:
    //constructors
    youtubername();
    youtubername(const char *channel_name, int subs, const char *name, int total_videos);
    //copy constructor
    youtubername(const youtubername& newone);
    //copy assigbnment constructor
    youtubername& operator = (const youtubername& source);
    //deconstructor
    ~youtubername();
    //display
    void display() const;
};

youtubername::youtubername(){
    youtuber_name = nullptr;
    no_of_videos = 0;
}

youtubername::youtubername(const char *channel_name, int subs, const char *name, int total_videos) : Youtubechannel(channel_name, subs) {
    youtuber_name = new char[strlen(name) + 1];
    strcpy(youtuber_name, name);
    no_of_videos = total_videos;
}

youtubername::youtubername(const youtubername& newone){
    youtuber_name = new char[strlen(newone.youtuber_name)+1];
    strcpy(this->youtuber_name, newone.youtuber_name);
}

youtubername& youtubername::operator = (const youtubername& source){
    if(this != &source){
        delete[] youtuber_name;
    }
    youtuber_name = new char[strlen(source.youtuber_name)+1];
    strcpy(youtuber_name, source.youtuber_name);
    no_of_videos = source.no_of_videos;
    return *this;
}

youtubername::~youtubername(){
    delete[] youtuber_name;
    youtuber_name = nullptr;
}

void youtubername::display() const{
    Youtubechannel::display();// by this i am calling the diplay funtion from the Youtubechannel class(base class) so that it prints the youtube channel name and the subscriber.
    cout << "Youtuber name: " << youtuber_name << endl;
    cout << "No of videos: " << no_of_videos << endl;
    cout << "\n" << endl;
}


int main(){
    Youtubechannel yt1("Tech With Tim", 1000000);
    yt1.display();

    Youtubechannel yt2(yt1); // copy constructor
    yt2.display();

    Youtubechannel yt3("Code with harry", 750000);
    yt3.display();

    yt3 = yt2; // copy assignment
    yt3.display();


    //--------------------inheritance from the Youtubechannel class---------

    youtubername y4("Coding strategy", 650000, "SM Tuaif", 27);
    y4.display();
    
    

    return 0;
}