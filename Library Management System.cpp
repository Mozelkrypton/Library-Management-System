/*libray management system in C++  using OOP1*/

#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Book_lib {
    private:
        string isbn,title,author,publication; /*used private variables throungh the project*/
    public:
        /*set user value to private variables*/
        void setIsbn(string a){isbn = a;}
        void setTitle(string b){title = b;}
        void setAuthor(string c){author = c;}
        void setPublication(string e){publication = e;}
        /*get the values from private variables*/
        string getIsbn(){return isbn;}
        string getTitle(){return title;}
        string getAuthor(){return author;}
        string getPublication(){return publication;}
};

/*initialize the functions and pass the counter() parameter to them*/
void adding_book(int counter);
void deleting_book(int counter);
void editing_book(int counter);
void searching_book(int counter);
void viewing_all_books(int counter);
void quit();

/*counter for Book array*/
int counter=0;

/*function for incrementing counter*/
void increment(int a){
    a++;
    counter=a;
}

/*function for decrementing counter*/
void decrement(int a){
    a--;
    counter=a;
}

/*Book class array initialization*/
Book_lib books[10];

/*This is the main function of the project*/
int main(){
string choice;
/*Menu*/
system("CLS");
cout<<"------------------------------------ZU LIBRARY MANAGEMENT SYSTEM-----------------------------------------------\n\n";
cout<<"[1]----------ADD BOOK----------\n";  
cout<<"[2]----------DELETE BOOK-------\n";  
cout<<"[3]----------EDIT BOOK---------\n";  
cout<<"[4]----------SEARCH BOOK-------\n";  
cout<<"[5]----------VIEW ALL BOOKS----\n";  
cout<<"[6]==========QUIT==============\n\n";

cout<<"ENTER YOUR CHOICE PLEASE: ";
getline(cin,choice);
system("CLS");
/*using if statements to call functions if a condition is met*/
if(choice=="1"){
    adding_book(counter); 
}       
else if(choice=="2"){   
    deleting_book(counter);
}
else if(choice=="3"){
    editing_book(counter);  
}
else if(choice=="4"){
    searching_book(counter);    
}
else if(choice=="5"){
    viewing_all_books(counter); 
}
else if(choice=="6"){
    quit();
}
else{
    main(); 
    /*call back the main function*/
}
    
_getch();
return 0;
}

/*The books_addition function*/
void adding_book(int counter){
    string isbn,title,author,publication;
    cout<<"ADD BOOKS TO THE SYSTEM\n\n";
    if(counter<10){
        cout<<"Enter ISBN: ";
        getline(cin,isbn); 
        
        /*getline - just like cin but includes white spaces*/
        
        cout<<"Enter Title of the book: ";
        getline(cin,title);
        cout<<"Enter the name of the author: ";
        getline(cin,author);
        cout<<"Enter Publication: ";
        getline(cin,publication);
        books[counter].setIsbn(isbn);
        
        /*update the book object with the assighned values*/
        
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setPublication(publication); 
        increment(counter);
            
        /*calling function to increment counter*/
        
        cout<<"\nBOOK ADDED SUCCESSFULLY!!!!!!\n\nPlease press enter to continue. . .";
        _getch();
        main();
    }
    else{
        cout<<" SORRY YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPlease press any key to continue . . .";
        _getch();
        main();
    }
}

/*fuction for deleting books */
void deleting_book(int counter){
    string isbn;
    int choice;
    cout<<"DELETE BOOK FROM THE SYSTEM\n\n";
    if(counter==0){
        cout<<"THERE IS NO BOOK TO DELETE !\n\nPlease press any key to continue . . .";
        _getch();
        main();
    }
    cout<<"Enter ISBN: ";
    getline(cin,isbn);

    for(int i=0;i<counter;i++){
        
/*Updating the books status*/
        if(books[i].getIsbn()==isbn){
            cout<<"\nBOOK FOUND\n\n";
            cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
            cin>>choice;
            if(choice==1){
                books[i].setIsbn(""); 
                
                /*setting the value to none after user update*/
                books[i].setTitle("");
                books[i].setAuthor("");
                books[i].setPublication("");
                for(int a=i;a<counter;a++){
                    
                    /*adjusting the values after deletion of data eg. data from book[4] copied to book[3]*/
                    
                    books[a] = books[a+1];
                }
                books[9].setIsbn("");
                
                 /*adjustment if the library is full(10 books)*/
                 
                books[9].setTitle("");
                books[9].setAuthor("");
                books[9].setPublication("");
                decrement(counter); 
                /*calling function to decrement counter for updating the object status*/
                cout<<"\nBOOK SUCCESSFULLY DELETED FROM THE SYSTEM!\n\nPlease press any key to continue . . .";
                _getch();
                main();
            }
            else{
                main();
            }
        }
    }
    cout<<"\nBOOK NOT FOUND!\n\nPlease press any key to continue . . .";
    _getch();
    main();
    
}
void editing_book(int counter){
    system("CLS");
    string editIsbn,choice;
    string isbn,title,author,publication;
    cout<<"\nEDIT BOOK\n\n";
    if(counter==0){
        cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
        _getch();
        main();
    }
    cout<<"Enter ISBN: ";
    getline(cin,editIsbn);
    for(int i=0;i<counter;i++){
        
        /* Using the for loop to find a match*/
        
        if(books[i].getIsbn()==editIsbn){
            cout<<"\nBOOK FOUND!\n\n";
            cout<<"ISBN: "<<books[i].getIsbn()<<endl;
            cout<<"TITLE: "<<books[i].getTitle()<<endl;
            cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
            cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
            cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
            getline(cin,choice);
            if(choice=="1"){
                /*re-entering values to the book object*/
                cout<<"Enter ISBN: ";
                getline(cin,isbn);
                cout<<"Enter Title: ";
                getline(cin,title);
                cout<<"Enter Author: ";
                getline(cin,author);
                cout<<"Enter Publication: ";
                getline(cin,publication);
                books[i].setIsbn(isbn);
                books[i].setTitle(title);
                books[i].setAuthor(author);
                books[i].setPublication(publication);   
                cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
                _getch();
                editing_book(counter);
            }
            else{
                main();
            }           
        }
}
    cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
    _getch();
    main();
}
void searching_book(int counter){
    string isbn;
    int choice;
    bool print = false; 
    /*boolean expression to decide which to print*/
    cout<<"SEARCH BOOK\n\n";
    if(counter==0){
        cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
        _getch();
        main();
    }
    cout<<"Enter ISBN: ";
    getline(cin,isbn);
    for(int i=0;i<counter;i++){
        /*finding a match using for loop*/
        if(books[i].getIsbn()==isbn){ 
            cout<<"\nBOOK FOUND!\n\n";
            cout<<"ISBN: "<<books[i].getIsbn()<<endl;
            cout<<"TITLE: "<<books[i].getTitle()<<endl;
            cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
            cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
            print = true;
        }
    }
    if(print){
        cout<<"\n\nPress any key to continue . . .";
        _getch();
        main();
    }
    
    /* executes if there is no boooks found */
    
    else{
        cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
        _getch();
        main();     
    }
}
void viewing_all_books(int counter){
    /* printing all the values on the library using book array*/
    cout<<"VIEW ALL BOOKS\n\n";
    for(int i=0;i<counter;i++){
        cout<<"BOOK DETAILS\n\n";
        cout<<"ISBN: "<<books[i].getIsbn()<<endl;
        cout<<"TITLE: "<<books[i].getTitle()<<endl;
        cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
        cout<<"PUBLICATION: "<<books[i].getPublication()<<endl<<endl;
    }
    cout<<"please press any key to continue . . .";
    _getch();
    main();
}
void quit(){
    /*This is the exit function*/
    _exit(1);
}
