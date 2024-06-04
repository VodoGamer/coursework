#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *previous_node;
  Node *next_node;
};

class List
{
public:
  Node *_start;
  Node *_last;

  List() : _start(nullptr), _last(nullptr) {}

  void append(int value);
  void pop();
  void print();
  int get(int index);

  ~List();
};

void List::append(int value)
{
  Node *node = new Node;
  node->value = value;
  if (!_start)
  {
    _start = node;
  }
  else
  {
    _last->next_node = node;
    node->previous_node = _last;
  }
  _last = node;
}

void List::pop()
{
  if (!_last)
  {
    return;
  }
  Node *node = _last;
  if (!node->previous_node)
  {
    _last = nullptr;
    _start = nullptr;
  }
  else
  {
    _last = node->previous_node;
    _last->next_node = nullptr;
  }
  delete node;
}

void List::print()
{
  Node *buffer = _start;
  cout << "List (";
  while (buffer)
  {
    if (buffer != _start)
    {
      cout << ", ";
    }
    cout << buffer->value;
    buffer = buffer->next_node;
  }
  cout << ")" << endl;
}

int List::get(int index)
{
  Node *buffer;
  if (index >= 0)
  {
    buffer = _start;
    for (int i = 0; i < index; i++)
    {
      buffer = buffer->next_node;
    }
  }
  else
  {
    buffer = _last;
    index++; // for start from last element [1, 2, 3].get(-1) == 3
    for (int i = index; i < 0; i++)
    {
      buffer = buffer->previous_node;
    }
  }
  return buffer->value;
}

List::~List()
{
  Node *current = _start;
  while (current)
  {
    Node *next = current->next_node;
    delete current;
    current = next;
  }
}

// int main()
// {
//   List my_list;
//   my_list.append(10);
//   my_list.print();
//   my_list.append(20);
//   my_list.append(40);
//   my_list.print();
//   std::cout << my_list.get(0) << std::endl;
//   std::cout << my_list.get(-1) << std::endl;
//   return 0;
// }