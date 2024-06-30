#include <fstream>
#include <iostream>
#include <string>

#include "list_object.cpp"

void print_file(const std::string &);
void print_main_menu(List *[100]);
void print_menu_options(List *[100]);
void create_new_list(List *[100]);
void delete_list(List *[100]);
void print_list(List *[100]);
void delete_all_lists(List *[100]);

int main() {
  List *lists[100] = {nullptr};
  system("clear");
  print_main_menu(lists);
  return 0;
}

void print_file(const std::string &file_name) {
  std::ifstream file(file_name);
  std::string text;
  if (file.is_open()) {
    while (std::getline(file, text)) {
      std::cout << text << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Unable to open file: " << file_name << std::endl;
  }
}

void create_new_list(List *lists[100]) {
  std::cout << "Создание нового списка" << std::endl;
  int index = -1;
  for (int i = 0; i < 100; ++i) {
    if (lists[i] == nullptr) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    std::cerr << "Невозможно создать новый список, нет свободного места." << std::endl;
    return;
  }
  List *list = new List();
  std::string choice;
  while (true) {
    std::cout << "Введите новый элемент списка (x для выхода): ";
    std::cin >> choice;
    if (choice == "x")
      break;
    list->append(std::stoi(choice));
  }
  lists[index] = list;
  system("clear");
  print_main_menu(lists);
}

void delete_list(List *lists[100]) {
  std::cout << "Введите номер списка для удаления (1-100): ";
  int index;
  std::cin >> index;
  index--;
  if (index < 0 || index >= 100 || lists[index] == nullptr) {
    std::system("clear");
    std::cerr << "Неверный номер списка или список не существует." << std::endl;
    print_main_menu(lists);
  }
  delete lists[index];
  lists[index] = nullptr;
  std::cout << "Список удален." << std::endl;
  system("clear");
  print_main_menu(lists);
}

void print_list(List *lists[100]) {
  std::cout << "Введите номер списка для вывода (1-100): ";
  int index;
  std::cin >> index;
  index--;
  if (index < 0 || index >= 100 || lists[index] == nullptr) {
    std::system("clear");
    std::cerr << "Неверный номер списка или список не существует." << std::endl;
    print_main_menu(lists);
  }
  system("clear");
  lists[index]->print();
  print_main_menu(lists);
}

void print_main_menu(List *lists[100]) {
  print_file("titles/hello.txt");
  print_menu_options(lists);
  int choice = 0;
  std::cout << ">> ";
  std::cin >> choice;
  switch (choice) {
    case 1:
      create_new_list(lists);
      break;
    case 2:
      delete_list(lists);
      break;
    case 3:
      print_list(lists);
      break;
    case 0:
      delete_all_lists(lists);
      break;
    default:
      break;
  }
}

void print_menu_options(List *lists[100]) {
  std::cout << "[1] Создать новый список" << std::endl;
  bool hasLists = false;
  for (int i = 0; i < 100; ++i) {
    if (lists[i] != nullptr) {
      hasLists = true;
      break;
    }
  }
  if (hasLists) {
    std::cout << "[2] Удалить список" << std::endl;
    std::cout << "[3] Вывести список" << std::endl;
  }
  std::cout << "[0] Выход" << std::endl;
}

void delete_all_lists(List *lists[100]) {
  for (int i = 0; i < 100; ++i) {
    if (lists[i] != nullptr) {
      delete lists[i];
      lists[i] = nullptr;
    }
  }
  lists = nullptr;
}