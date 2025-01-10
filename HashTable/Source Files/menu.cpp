#include "../Header Files/menu.h"
#include "../Header Files/Dictionary.h"
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

void ShowDictionary(const Dictionary* dictionary)
{
    HashTable* hashTable = const_cast<Dictionary*>(dictionary)->GetHashTable();

    int length = hashTable->GetLength();
    if (length == 0)
    {
        std::cout << "Dictionary is empty.\n";
        return;
    }

    HashTableItem** data = hashTable->GetData();
    int capacity = hashTable->GetHashTableSize();

    std::cout << "Dictionary contents:\n";
    for (int i = 0; i < capacity; i++)
    {
        HashTableItem* temp = data[i];
        while (temp)
        {
            std::cout << "Key: " << temp->Key << ", Value: " << temp->Value << "\n";
            temp = temp->Next;
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
    std::cout << "4. Show current structure\n";
    std::cout << "5. Back to main menu\n";
    std::cout << "Enter your choice: ";
    std::cout << "\n";
}

bool ChooseDataStructure(bool& exitProgram)
{
    std::cout << "Choose data structure:\n";
    std::cout << "1. HashTable\n";
    std::cout << "2. Dictionary \n";
    std::cout << "0. Exit\n"; 
    int choice;
    std::cin >> choice;

    if (choice == 0)
    {
        exitProgram = true; 
        return false;       
    }

    if (choice == 1)
    {
        return true; 
    }
    else if (choice == 2)
    {
        return false; 
    }
    else
    {
        return ChooseDataStructure(exitProgram); 
    }
}
