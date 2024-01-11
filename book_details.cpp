#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;

struct Book
{
	string title;
	string author;
	int publish_year;
	bool genre;
	bool old_n;
	bool old;
};

Book book[6];
Book non_fiction[6];
Book fiction[6];


void get_book_details();
void cat_books();
void old_book();


	int main()
	{
		
	}
	
	void get_book_details()
	{
		for(int i = 0; i < 6 ; ++i)
		{
			bool check;
			cout << "\nEnter Book Details : ";
			
			cout << "\n\t\t\t>  Book Title  : ";
			getline(cin,book[i].title);
			
			cout << "\n\t\t\t>  Author Name : ";
			getline(cin,book[i].author);
			
			cout << "\n\t\t\t>  Publish Year: ";
			do
			{
				if(cin >> book[i].publish_year;)
				{
					check = false;
				}
				else
				{
					check = true;
					cin.clear();
					cin.ignore(numeric_limits<streamsize> :: max(), '\n');
				}
			}while(check);
			
			cout << "\n\t\t\t>  1-Fiction";
			cout << "\n\t\t\t>  2-Non_fiction";
			char genre;
			do
			{
				genre = _getch();
				if(genre == '1')
				{
					book[i].genre = true;
				}
				else if(genre == '2')
				{
					book[i].genre = false;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize> :: max(),'\n');
				}    	
				
			}while(genre != '1' || genre != '2');	
		}
	}
	
	void cat_books()
	{
		int a=0,b=0;
		for(int i = 0 ; i < 6 ; ++i)
		{
			if(book[i].genre == true)
			{
				fiction[a].author = book[i].author;
				fiction[a].title = book[i].title;
				fiction[a].publish_year = book[i].publish_year;
				a++;
			}
			else if(book[i].genre == false)
			{
				non_fiction[b].author = book[i].author;
				non_fiction[b].title = book[i].title;
				non_fiction[b].publish_year = book[i].publish_year;
				b++;
			}
		}
	}
	
	void old_book()
	{
		
	}