#include <string>
#include <iostream>
#include <fstream>

#include "list_object.cpp"

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

void print_main_menu(List *lists)
{
  print_file("titles/hello.txt");
  if (lists == nullptr)
  {
    std::cout << "У вас нет списков на данный момент" << endl;
  }
  std::cout << "[1] Создать новый список" << endl;
  if (lists != nullptr)
  {
    std::cout << "[2] Удалить список" << endl;
  }
}

int main()
{
  List *lists = nullptr;
  print_main_menu(lists);
  int choice = 0;
  std::cout << ">> ";
  std::cin >> choice;
  return 0;
}
