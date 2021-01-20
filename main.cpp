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
//      if there is 1 or more books already in the list. This function will add another book at the end of the list.
        else{
            tailNode->nextNode=currentNode;
            tailNode=currentNode;
            totalBooks++;
        }
    }

    int display_by_author(string author_name ){		//searching books by author name
        temp = headNode;
        for (int i=1; i<=totalBooks ;i++){
            {
                cout<<"Name of book"<<currentNode -> bookName<<endl;
                cout<<"author name: "<<temp -> author<<"\t\tbook name: "<<temp -> bookName<<"\t\tid : "<<temp -> serialNo<<endl;
            }
            temp = temp -> nextNode;
        }
    }
    int search_by_ISBN(int ISBN ){           	//search book by ISBN number
        temp = headNode;
        for (int i=1 ; i<=totalBooks ; i++){

            if(temp -> serialNo == ISBN){
                cout<<"id : "<<temp -> serialNo<<"\nbook name: "<<temp -> bookName<<"\nauthor name: "<<temp -> author;
            }
            temp = temp -> nextNode;
        }
    }
    bookNode *traverse(int index){
        currentNode = headNode;
        for(int i=1 ; i<=index ; i++){
            currentNode = currentNode -> nextNode;
        }
        return currentNode;
    }

    int delete_Book(string book_name){				//Delete any Books
        currentNode = new bookNode;
        currentNode = headNode;
        for (int i=1; i<=totalBooks ; i++){
            //	cout<<"Name of book"<<currentNode -> bookName<<endl;

            if(currentNode -> bookName == book_name){
                if(i==1){
                    currentNode = headNode;
                    headNode = headNode -> nextNode;
                }
                else
                {
                    bookNode *prev=traverse(i-1);
                    currentNode = prev->nextNode;
                    prev -> nextNode = currentNode -> nextNode;

                }
                delete currentNode;
                totalBooks--;
            }
            currentNode = currentNode -> nextNode;
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