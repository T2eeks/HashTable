#include "../Header Files/menu.h"
#include "../Header Files/HashTable.h"
#include <iostream>

void ShowHashTable(const HashTable* hashTable)
{
    std::cout << "Hash Table State:\n";
    for (int i = 0; i < hashTable->GetHashTableSize(); i++)
    {
        HashTableItem* current = hashTable->GetData()[i];
        std::cout << i << ": ";
        if (!current)
        {
            std::cout << "[ ]\n";
        }
        else
        {
            while (current)
            {
                std::cout << "{Key: " << current->Key << ", Value: " << current->Value << "} -> ";
                current = current->Next;
            }
            std::cout << "NULL\n";
        }
    }
}

std::string GetKey()
{
    std::string key;
    std::cout << "Enter key: ";
    std::cin >> key;
    return key;
}

void ShowMenu()
{
    std::cout << "1. Add (key, value)\n";
    std::cout << "2. Delete (key)\n";
    std::cout << "3. Search (key)\n";
    std::cout << "4. Show Hash Table\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cout << "\n";
}
