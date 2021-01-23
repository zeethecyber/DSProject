/*This is a Library Management System created with C++
This program uses data structures implementation
It will have the following function
 1- Add funtion
 2- Search Funtion
 3- Update Function
 4- Delete Function
 */

#include "iostream"
using namespace std;


// This is a Linked List Class
class bookList
{
private:
//    Creating Structures for Book bookNode
    struct bookNode
    {
        int serialNo;
        unsigned long long int isbn;
        string bookName;
        string author;
        bool issued=false;  //to check if book is issued or not
        bookNode *nextNode;     //link of next bookNode
        bookNode *prevNode;
    };
    bookNode *headNode=new bookNode();      //headNode node of bookNodes
    bookNode *tailNode;                     //tail node of bookNodes
    bookNode *currentNode;                  //this will carry the input from user
    bookNode *temp;                         //this pointer will be used to iterate between book nodes
    struct bookBorrower
    {
        unsigned long int ID;
        unsigned long int isbn;
        string personName;
        string bookName;
        bookBorrower *next;
        bookBorrower *prev;
    };
    bookBorrower *head=new bookBorrower();      //headNode node of bookNodes
    bookBorrower *tail;                     //tail node of bookNodes
    bookBorrower *current;                  //this will carry the input from user
    bookBorrower *tempp;                         //this pointer will be used to iterate between book nodes
    int totalBooks=0;
    int totalBorrower=0;

public:
//    inserting bookNode element at the of the list
    void addBook(int srNo,unsigned long int isbN,string name,string auth)
    {
        currentNode=new bookNode();     //Creating new book node
//      Inserting data
        currentNode->serialNo=srNo;
        currentNode->isbn=isbN;
        currentNode->bookName=name;
        currentNode->author=auth;
        currentNode->nextNode= nullptr;
//      Checking if there are some already or not
        if(totalBooks==0)
        {
//          Creating the first head and tail node
            headNode=currentNode;
            tailNode=currentNode;
            totalBooks++;
        }
//      if there is 1 or more books already in the list. This function will add another book at the end of the list.
        else{
            tailNode->nextNode=currentNode;
            currentNode->prevNode=tailNode;
            tailNode=currentNode;
            totalBooks++;
        }
    }
    void issueBook(unsigned long int isbN, unsigned long int borrower_id,string borrower_name)
    {
        temp=headNode;
        bool found= false;
        string book_name;
        for (int i = 0; i < totalBooks; ++i) {
            if (temp->isbn==isbN)
            {
                temp->issued=true;
                book_name=temp->bookName;
                found=true;
                break;
            }
            temp=temp->nextNode;
        }
        if (found==true)
        {
            current=new bookBorrower();
            current->ID=borrower_id;
            current->personName=borrower_name;
            current->isbn=isbN;
            current->bookName=book_name;
            if (totalBorrower==0)
            {
                head=current;
                tail=current;
                totalBorrower++;
            } else{
                tail->next=current;
                tail=current;
                totalBorrower++;
            }
            cout<<"\nBook Issued!!";
        }
    }

    void issuedBooks()
    {
        tempp=head;
        for (int i = 0; i < totalBorrower; ++i) {
            cout<<"\n-----------------------------------------";
            cout<<"\nBorrower ID : "<<tempp->ID;
            cout<<"\nBorrower Name : "<<tempp->personName;
            cout<<"\nBook Borrowed : "<<tempp->bookName;
            cout<<"\nBook ISBN : "<<tempp->isbn;
            cout<<"\n-----------------------------------------";
            tempp=tempp->next;
        }
    }

    void depositBook(unsigned long int isbN)
    {
        tempp=head;
        bool found=false;
        for (int i = 0; i < totalBorrower; ++i) {
            if (tempp->isbn==isbN)
            {
                found=true;
                break;
            }
            tempp=tempp->next;
        }
        if (tempp==head)
        {
            head=head->next;
            delete tempp;
            totalBorrower--;
        } else{
            tempp->prev=current;
            current->next=tempp->next;
            delete tempp;
            totalBorrower--;
        }

        temp=headNode;
        for (int i = 0; i < totalBooks; ++i) {
            if (temp->isbn==isbN)
            {
                temp->issued= false;
            }
        }
        cout<<"Book Deposit Successful";
    }

    void displayByAuthor(string authorName ){		//searching books by author name
        temp=headNode;
        bool found= false;
        cout<<"\nBooks by Author "<<authorName;
        for (int i = 0; i < totalBooks; ++i) {
            if (temp->author==authorName)
            {
                found= true;
                cout<<"\n--------------------------------------------------";
                cout<<"\nSerial Number: "<<temp->serialNo;
                cout<<"\nISBN: "<<temp->isbn;
                cout<<"\nBook Name : "<<temp->bookName;
                cout<<"\nAuthor: "<<temp->author;
                cout<<"\nIssued? : "<<temp->issued;
                cout<<"\n--------------------------------------------------";
            }
            temp=temp->nextNode;
        }
        if (found== false)
        {
            cout<<"\nNo Book Found!!";
            cout<<"\n--------------------------------------------------";
        }
    }
    void searchByISBN(unsigned long int isbN){           	//search book by ISBN number
        temp=headNode;
        bool found= false;
        cout<<"\nBook by ISBN "<<isbN;
        for (int i = 0; i < totalBooks; ++i) {
            if (temp->isbn==isbN)
            {
                found= true;
                cout<<"\n--------------------------------------------------";
                cout<<"\nSerial Number: "<<temp->serialNo;
                cout<<"\nISBN: "<<temp->isbn;
                cout<<"\nBook Name : "<<temp->bookName;
                cout<<"\nAuthor: "<<temp->author;
                cout<<"\nIssued? : "<<temp->issued;
                cout<<"\n--------------------------------------------------";
            }
            temp=temp->nextNode;
        }
        if (found== false)
        {
            cout<<"\nNo Book Found!!";
            cout<<"\n--------------------------------------------------";
        }
    }

//      Function to display all books in the linked list
    void display()
    {
        temp=headNode;
        for (int i = 0; i < totalBooks; ++i) {
            cout<<"\n--------------------------------------------------";
            cout<<"\nSerial Number: "<<temp->serialNo;
            cout<<"\nISBN: "<<temp->isbn;
            cout<<"\nBook Name : "<<temp->bookName;
            cout<<"\nAuthor: "<<temp->author;
            cout<<"\nIssued? : "<<temp->issued;
            cout<<"\n--------------------------------------------------";
            temp=temp->nextNode;
        }
    }

    void deleteBook(unsigned long int isbN)
    {
        temp=headNode;
        bool found=false;
        for (int i = 0; i < totalBooks; ++i) {
            if (temp->isbn==isbN)
            {
                found=true;
                break;
            }
            temp=temp->nextNode;
        }
        if (found)
        {
            if (temp==headNode)
            {
                headNode=headNode->nextNode;
                delete temp;
            } else{
                currentNode=temp->prevNode;
                currentNode->nextNode=temp->nextNode;
                delete temp;
            }
            totalBooks--;
        }
        cout<<"\nBook Deleted!!";
    }
};


void mainMenu(bookList ls)
{
    int choice,srno=0;
    unsigned long int id,isbn;
    string bookName,author,borrowerName;
    cout<<"----------WELCOME TO LIBRARY MANAGMENT SYSTEM-------------\nCreated by Zeeshan,Muneeb & Hamza";
    cout<<"\nchoose one option from following (Enter a number)";
    cout<<"1: Insert a book\n";
    cout<<"2: Issue a book\n";
    cout<<"3: Deposit a book\n";
    cout<<"4: Search a book by Author\n";
    cout<<"5: Search a book by ISBN\n";
    cout<<"6: Modify a book\n";
    cout<<"7: Delete a book\n";
    loop:cin>>choice;
    switch (choice) {
        case 1:
            srno++;
            cout<<"Enter ISBN of Book: ";
            cin>>isbn;
            cout<<"Enter Name of Book: ";
            getline(cin,bookName);
            cout<<"Enter name of Author of Book: ";
            getline(cin,author);
            ls.addBook(srno,isbn,bookName,author);
            cout<<"Book Added!!";
            mainMenu(ls);
            break;
        case 2:
            cout<<"Enter borrower ID: ";
            cin>>id;
            cout<<"Enter borrower name: ";
            cin>>borrowerName;
            cout<<"Enter ISBN of Book to borrow: ";
            cin>>isbn;
            ls.issueBook(isbn,id,borrowerName);
            cout<<"Book Issued Successfully";
            mainMenu(ls);
            break;
        case 3:
            cout<<"Enter ISBN of Book to deposit: ";
            cin>>isbn;
            ls.depositBook(isbn);
            cout<<"Book Deposited Successfully";
            mainMenu(ls);
            break;
        case 4:
            cout<<"Enter Author Name: ";
            cin>>author;
            ls.displayByAuthor(author);
            mainMenu(ls);
            break;
        case 5:
            cout<<"Enter ISBN: ";
            cin>>isbn;
            ls.searchByISBN(isbn);
            mainMenu(ls);
            break;
        case 6:
            cout<<"We Are working on it, Sorry";
            break;
        case 7:
            cout<<"Enter ISBN to delete a book: ";
            cin>>isbn;
            ls.deleteBook(isbn);
            mainMenu(ls);
            break;
        default:
            cout<<"Wrong Value Entered Please try again!!";
            goto loop;

    }
}
int main()
{
    bookList list1;
    mainMenu(list1);
}