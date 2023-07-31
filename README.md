# Library_Management_System
This is a simple implementation of a Library Management System (LMS) using C++. The program allows users to manage a collection of books by performing various operations such as entering book data, editing book information, deleting books, searching for books, and displaying the book collection.
# Class Structure
## class Node
This class represents a node in the doubly linked list that holds information about a book. Each node has four private data members:
* **string author:** Represents the author's name of the book.
* **string title:** Represents the title of the book.
* **string publication:** Represents the publication of the book.
* **string book_id:** Represents the unique identifier (ID) of the book.
Additionally, it has two private pointers:

* **`Node* next`:** Points to the next node in the linked list.
* **`Node* pre`:** Points to the previous node in the linked list.
The class provides two constructors:

* **Node():** Default constructor.
* **Node(string auth, string tit, string pub, string book):** Parameterized constructor to initialize the data members.
The class LMS (Library Management System) is a friend of the Node class, which means it can access the private members of the Node class.

## class LMS
This class represents the Library Management System and manages the collection of books using a doubly linked list. It contains the following private data members:

* **`Node* head:`** A pointer to the first node of the doubly linked list. It represents the head of the linked list.
* **fstream File:** An fstream object used for file input/output to store book records.
The class provides several member functions to perform different operations on the collection of books:

* **void menu():** Displays the main menu and handles user input for various operations.
* **void Search():** Allows the user to search for books either by book ID or book title.
* **bool Del():** Handles the deletion of book records.
* **void Delete():** Deletes book records from the collection.
* **void EditRecord():** Allows the user to edit the information of a book.
* **void LLtoFile():** Writes the data from the linked list to the file.
* **void EnterData():** Allows the user to enter new book data and adds it to the linked list.
* **void FiletoLL():** Reads data from the file into the linked list.
* **void Display():** Displays the entire collection of books.
Additionally, the class has a **main** function to create an object of the **LMS** class and start the Library Management System by calling the **menu()** method.

The **LMS** class uses the **Node** class to store and manage the book records in a doubly linked list. The doubly linked list allows efficient traversal of the book records in both forward and backward directions. The **fstream** object is used to interact with a file ("LMS.txt") for persistent storage of the book records between different program runs.

# Features
* **Add** new books to the collection with details like author name, book title, publication, and book ID.
* **Edit** existing book information, including author name, title, publication, and book ID.
* **Delete** books from the collection either by book ID or book title.
* **Search** for books in the collection based on book ID or book title.
* **Display** the entire book collection.

# How to Use
* When you run the program, it will **display** a menu with various options.
* Choose an **option** from the menu to perform the corresponding operation.
* To **enter** book data, select **option 1** and provide the required information.
* To **edit** book information, select **option 2**, and follow the instructions to choose a book for editing and update its details.
* To **delete** books, select **option 3**, and follow the instructions to delete specific books or clear the entire collection.
* To **search** for books, select **option 4**, and follow the instructions to search by book ID or book title.
* To **display** all the books in the collection, select **option 5**.

# File Persistence
The program uses file I/O to store the book records in the file named "LMS.txt". The data is saved to the file whenever a new book is added, book information is edited, or a book is deleted. On program startup, it loads the data from the file into the linked list.

# Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

