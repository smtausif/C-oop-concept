

Copy constructor:

        we use copy constructor when we want to copy an object. for example
        we have a class Book which have some member variables and function
        sp we have 1 instance in main funtion ex: book1
        so now we have created another instance or object book2 and want to
        copy book1 to book2

        int main(){
        Book book1("The Great Gatsby", "F. Scott Fitzgerald");
        Book book2(book1);
        book2.display();
        }


Copy assignment operator:

        when we want to replace the vaues of an already existing object based
        on another object