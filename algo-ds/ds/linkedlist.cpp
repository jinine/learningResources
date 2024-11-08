#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

void print_node_details(Node* head)
{
    if (head == nullptr)
    {
        std::cout << "Node is nullptr\n";
        return;
    }
    std::cout << "data: " << head->data << '\n';
    if (head->next != nullptr)
        std::cout << "next: " << head->next->data << '\n';
    else
        std::cout << "next: nullptr\n";
}

Node* search_by_value(Node* head, int value)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

Node* search_by_index(Node* head, int index)
{
    Node* curr = head;
    for (int i = 0; i < index && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    return curr;
}

Node* insertFromFront(Node* head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

void delete_by_value(Node*& head, int value)
{
    while (head != nullptr && head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data == value) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

void delete_by_index(Node*& head, int index)
{
    if (index == 0 && head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = search_by_index(head, index - 1);
    if (prev != nullptr && prev->next != nullptr) {
        Node *temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}

Node* add(Node* head, int new_data)
{
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        return new_node;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

void print_list(Node* head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data;
        std::string has_next = (curr->next != nullptr) ? "->" : "";
        std::cout << has_next;
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node* head = new Node(0);
    head = add(head, 1);
    head = add(head, 2);
    head = add(head, 3);
    head = add(head, 4);
    head = add(head, 5);

    // Testing delete by value
    delete_by_value(head, 4);
    print_list(head);

    // Testing delete by index
    delete_by_index(head, 2);
    print_list(head);

    return 0;
}
