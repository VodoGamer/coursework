#include <iostream>

struct Node
{
  int value;
  Node *previous_node;
  Node *next_node;

  Node(int val) : value(val), previous_node(nullptr), next_node(nullptr) {}
};

class List
{
public:
  Node *_start;
  Node *_last;

  List() : _start(nullptr), _last(nullptr) {}

  void append(int value);
  void pop();
  void print() const;
  int get(int index) const;

  ~List();
};

void List::append(int value)
{
  Node *node = new Node(value);
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

void List::print() const
{
  Node *buffer = _start;
  std::cout << "List (";
  while (buffer)
  {
    if (buffer != _start)
    {
      std::cout << ", ";
    }
    std::cout << buffer->value;
    buffer = buffer->next_node;
  }
  std::cout << ")" << std::endl;
}

int List::get(int index) const
{
  Node *buffer = nullptr;
  if (index >= 0)
  {
    buffer = _start;
    for (int i = 0; buffer && i < index; i++)
    {
      buffer = buffer->next_node;
    }
  }
  else
  {
    buffer = _last;
    index++; // for start from last element [1, 2, 3].get(-1) == 3
    for (int i = index; buffer && i < 0; i++)
    {
      buffer = buffer->previous_node;
    }
  }
  if (buffer)
  {
    return buffer->value;
  }
  throw std::out_of_range("Index out of range");
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
