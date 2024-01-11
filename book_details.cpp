#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;

struct Book {
    string title;
    string author;
    int publish_year;
    bool genre;  // true for fiction, false for non-fiction
};

Book book[6];
Book non_fiction[6];
Book fiction[6];

void get_book_details();
void cat_books();
void old_book();

	int main() 
	{
	    get_book_details();
	    cat_books();
	    old_book();
	}
	
	void get_book_details() 
	{
	    for (int i = 0; i < 6; ++i) 
		{
	        bool check;
	        cout << "\nEnter Book Details : ";
	
	        cout << "\n\t\t\t>  Book Title  : ";
	        getline(cin, book[i].title);
	
	        cout << "\n\t\t\t>  Author Name : ";
	        getline(cin, book[i].author);
	
	        cout << "\n\t\t\t>  Publish Year: ";
	        do {
	            if (cin >> book[i].publish_year) 
				{
	                check = false;
	            } 
				else 
				{
	                check = true;
	                cin.clear();
	                cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            }
	        } while (check);
	
	        cout << "\n\t\t\t>  1-Fiction";
	        cout << "\n\t\t\t>  2-Non_fiction";
	        char genre;
	        do {
	            genre = _getch();
	            if (genre == '1') 
				{
	                book[i].genre = true;
	            } 
				else if (genre == '2') 
				{
	                book[i].genre = false;
	            } 
				else 
				{
	                cin.clear();
	                cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            }
	
	        } while (genre != '1' && genre != '2');
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	}
	
	void cat_books() 
	{
	    int a = 0, b = 0;
	    for (int i = 0; i < 6; ++i) 
		{
	        if (book[i].genre == true) 
			{
	            fiction[a] = book[i];
	            a++;
	        } 
			else if (book[i].genre == false) 
			{
	            non_fiction[b] = book[i];
	            b++;
	        }
	    }
	}
	
	void old_book() 
	{
	    int min_fiction_year = INT_MAX, min_non_fiction_year = INT_MAX;
	    Book earliest_fiction, earliest_non_fiction;
	
	    for (int i = 0; i < 6; ++i) {
	        if (fiction[i].publish_year < min_fiction_year) 
			{
	            min_fiction_year = fiction[i].publish_year;
	            earliest_fiction = fiction[i];
	        }
	
	        if (non_fiction[i].publish_year < min_non_fiction_year) 
			{
	            min_non_fiction_year = non_fiction[i].publish_year;
	            earliest_non_fiction = non_fiction[i];
	        }
	    }
	
	    // Display the details of the books
	    cout << "\n\nFiction Books:\n";
	    for (int i = 0; i < 6; ++i) 
		{
	        cout << "Title: " << fiction[i].title << ", \tAuthor: " << fiction[i].author << ", \tPublish Year: " << fiction[i].publish_year << endl;
	    }
	    cout << "Earliest Fiction Book: " << earliest_fiction.title << " by " << earliest_fiction.author << " (Publish Year: " << earliest_fiction.publish_year << ")\n";
	
	    cout << "\nNon-Fiction Books:\n";
	    for (int i = 0; i < 6; ++i) 
		{
	        cout << "Title: " << non_fiction[i].title << ", \tAuthor: " << non_fiction[i].author << ", \tPublish Year: " << non_fiction[i].publish_year << endl;
	    }
	    cout << "Earliest Non-Fiction Book: " << earliest_non_fiction.title << " by " << earliest_non_fiction.author << " (Publish Year: " << earliest_non_fiction.publish_year << ")\n";
	}
