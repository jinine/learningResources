#include <iostream>
#include <vector>
#include <list>
#include <iterator>

class Book
{
public:
    int id;
    std::string title;
    std::vector<std::pair<int, std::string>> content;
    int last_page = 0;

    Book(int _id, std::string _title, std::vector<std::pair<int, std::string>> _content)
    {
        id = _id;
        title = _title;
        content = _content;
    }
};

class Library
{
public:
    std::list<Book> book_list;
    Library()
    {
        book_list = {};
    }
    void print_library()
    {
        for (auto it = book_list.begin(); it != book_list.end(); ++it)
        {
            std::cout << it->title << '\n';
        }
    }

    void add_book(Book book)
    {
        book_list.insert(book_list.end(), book);
    }
};

int main()
{
    Library *library = new Library();
    Book *book = new Book(0, "Title", {{0, "page 1"}});
    library->add_book(*book);
    library->print_library();

    return 0;
}