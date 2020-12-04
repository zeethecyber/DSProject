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
        string bookName;
        string author;
        bool issued=false;  //to check if book is issued or not
        bookNode *nextNode;     //link of next bookNode
    };
    int totalBooks;
    bookNode *headNode=new bookNode();      //headNode node of bookNodes
    bookNode *tailNode;                     //tail node of bookNodes
    bookNode *currentNode;                  //this will carry the input from user
    bookNode *temp;                         //this pointer will be used to iterate between book nodes
public:
    bookList()
    {
        totalBooks=0;
    }
//    inserting bookNode element at the of the list
    void addBook(int srNo,string name,string auth)
    {
        currentNode=new bookNode();     //Creating new book node
//      Inserting data
        currentNode->serialNo=srNo;
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
//      if there is 1 or more books already in the list. This funtion will add another book at the end of the list.
        else{
            tailNode->nextNode=currentNode;
            tailNode=currentNode;
            totalBooks++;
        }
    }
//      Function to display all books in the linked list
    void display()
    {
        temp=headNode;
        for (int i = 0; i < totalBooks; ++i) {
            cout <<"Serial Number :: "<< temp->serialNo << endl;
            cout <<"Book Name :: "<< temp->bookName << endl;
            cout <<"Author Name :: "<< temp->author << endl;
            cout<<"----------------------------------------------"<<endl;
            temp=temp->nextNode;
        }
    }
};

int main()
{
    bookList list1;
    list1.addBook(100,"Computer Science","Zeeshan Asif");
    list1.addBook(101,"Data Structures & Algorithm","Muneeb Akram");
    list1.addBook(102,"Programming Fundamentals","Hamza Ismail");
    list1.addBook(103,"Mathematics","Unknown");
    list1.display();
    // Muneeb Akram
}