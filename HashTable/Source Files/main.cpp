#include "../Header Files/menu.h"
#include "../Header Files/Dictionary.h"
#include "../Header Files/HashTable.h"
#include <iostream>
#include <limits>

void InvalidInput();

// TODO: В словаре не должно быть более одной пары ключ-значение с одим и тем же ключем
int main()
{
    bool exitProgram = false;

    while (!exitProgram)
    {
      bool useHashTable = ChooseDataStructure(exitProgram);

      if (exitProgram)
      {
          std::cout << "Exiting program.\n";
          break;
      }
      HashTable* hashTable = nullptr;
      Dictionary* dictionary = nullptr;

      if (useHashTable)
      {
          hashTable = new HashTable();
      }
      else
      {
          dictionary = new Dictionary();
      }

      bool exitStructure = false;

      while (!exitStructure)
      {
          ShowMenu();
          int choice;
          std::cin >> choice;
          std::string key, value;

          if (std::cin.fail())
          {
              InvalidInput();
              continue;
          }

          switch (choice)
          {
          case 1:
              key = GetKey();
              std::cout << "Enter value: ";
              std::cin >> value;

              if (useHashTable)
              {
                  hashTable->AddElement(key, value);
                  std::cout << "Added successfully!\n";
              }
              else
              {
                  dictionary->Add(key, value);
                  std::cout << "Added successfully!\n";
              }

              break;

          case 2:
              key = GetKey();
              if (useHashTable)
              {
                  if (hashTable->RemoveItem(key, value))
                  {
                      std::cout << "Removed value: " << value << "\n";
                  }
                  else
                  {
                      std::cout << "Key not found.\n";
                  }
              }
              else
              {
                  if (dictionary->Delete(key, value))
                  {
                      std::cout << "Removed value: " << value << "\n";
                  }
                  else {
                      std::cout << "Key not found.\n";
                  }
              }
              break;

          case 3:
              key = GetKey();
              if (useHashTable)
              {
                  if (hashTable->FindItem(key, value))
                  {
                      std::cout << "Found value: " << value << "\n";
                  }
                  else
                  {
                      std::cout << "Key not found.\n";
                  }
              }
              else
              {
                  if (dictionary->Search(key, value))
                  {
                      std::cout << "Found value: " << value << "\n";
                  }
                  else
                  {
                      std::cout << "Key not found.\n";
                  }
              }
              break;


          case 4:
              if (useHashTable)
              {
                  ShowHashTable(hashTable);
              }
              else
              {
                  ShowDictionary(dictionary);
              }
              break;

          case 5:
              exitStructure = true;
              break;

          default:
              InvalidInput();
          }
      }

      if (useHashTable)
      {
          delete hashTable;
          hashTable = nullptr;
      }
      else
      {
          delete dictionary;
          dictionary = nullptr;
      }

    }

    return 0;
}

void InvalidInput()
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Unknown command. Please enter a valid choice.\n";
}
