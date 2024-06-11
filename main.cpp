#include <string>
#include <iostream>
#include <fstream>

#include "list_object.cpp"

void print_file(string);
void print_main_menu(List *);
void print_menu_options(List *);
void create_new_list(List *);

int main()
{
  List *lists = nullptr;
  system("clear");
  print_main_menu(lists);
  return 0;
}

void print_file(string file_name)
{
  std::ifstream file;
  file.open(file_name);
  string text;
  if (file.is_open())
  {
    while (getline(file, text))
    {
      std::cout << text << std::endl;
    }
  }
  file.close();
}

void create_new_list(List *lists)
{
  std::cout << "Создание нового списка" << endl;
  List *list = new List();
  string choice;
  while (choice != "x")
  {
    std::cout << "Введите новый элемент списка (x для выхода): ";
    std::cin >> choice;
    if (choice != "x")
      list->append(std::stoi(choice));
  };
  lists = list;
  system("clear");
  print_main_menu(lists);
}

void print_main_menu(List *lists)
{
  print_file("titles/hello.txt");
  print_menu_options(lists);
  int choice = 0;
  std::cout << ">> ";
  std::cin >> choice;
  switch (choice)
  {
  case 1:
    create_new_list(lists);
    break;
  case 2:
    system("clear");
    delete lists;
    lists = nullptr;
    print_main_menu(lists);
    break;
  case 3:
    system("clear");
    lists->print();
    print_main_menu(lists);
    break;
  default:
    break;
  }
}

void print_menu_options(List *lists)
{
  if (lists == nullptr)
  {
    std::cout << "У вас нет списков на данный момент" << endl;
  }
  std::cout << "[1] Создать новый список" << endl;
  if (lists != nullptr)
  {
    std::cout << "[2] Удалить список" << endl;
    std::cout << "[3] Вывести список" << endl;
  }
  std::cout << "[0] Выход" << endl;
}