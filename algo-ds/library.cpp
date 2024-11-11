#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int bookID = 0;
int memberID = 0;

class Book
{
public:
    int id;
    std::string title;
    std::vector<std::pair<int, std::string>> content;
    int last_page = 0;
    bool available = true;
    Book(std::string _title, std::vector<std::pair<int, std::string>> _content)
    {
        id = bookID;
        title = _title;
        content = _content;
        bookID = bookID + 1;
    }
};

class Member
{
public:
    int id;
    std::string name;
    std::list<Book> checked_out = {};
    Member(std::string _name)
    {
        id = memberID;
        name = _name;
        memberID = memberID + 1;
    }
};

class Library
{
public:
    std::list<Book> book_list;
    std::list<Member> member_list;
    Library()
    {
        book_list = {};
        member_list = {};
    }
    void print_library()
    {
        for (auto it = book_list.begin(); it != book_list.end(); ++it)
        {
            std::cout << it->id << '\n';
        }
    }

    void print_members()
    {
        for (auto it = member_list.begin(); it != member_list.end(); ++it)
        {
            std::cout << it->name << '\n';
        }
    }

    void add_book(Book book)
    {
        book_list.insert(book_list.end(), book);
    }

    void add_member(Member member)
    {
        member_list.insert(member_list.end(), member);
    }

    void check_out(Book book, Member member)
    {
    }
};

int main()
{
    Library *library = new Library();
    Book *book = new Book("Title", {{0, "page 1"}});
    Book *book_2 = new Book("Title", {{0, "page 1"}});
    Book *book_3 = new Book("Title", {{0, "page 1"}});
    Book *book_4 = new Book("Title", {{0, "page 1"}});
    Book *book_5 = new Book("Title", {{0, "page 1"}});
    library->add_book(*book);
    library->add_book(*book_2);
    library->add_book(*book_3);
    library->add_book(*book_4);
    library->add_book(*book_5);
    library->print_library();
    Member *member = new Member("Member");
    library->add_member(*member);
    library->print_members();

    return 0;
}