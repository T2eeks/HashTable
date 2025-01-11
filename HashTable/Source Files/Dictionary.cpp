#include "../Header Files/Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary() 
{
    _hashTable = new HashTable; 
}

Dictionary::~Dictionary()
{
    _hashTable->DeleteHashTable();
}

bool Dictionary::Add(const std::string& key, const std::string& value)
{
    string existingValue;
    string mutableKey = key;

    // TODO: переписывать значение
    if (_hashTable->FindItem(key, existingValue))
    {
        _hashTable->RemoveItem(mutableKey, existingValue);
    }

    _hashTable->AddElement(key, value);
    return true;
}

bool Dictionary::Delete(const std::string& key, std::string& value)
{
    return _hashTable->RemoveItem(const_cast<std::string&>(key), value);
}

bool Dictionary::Search(const std::string& key, std::string& value)
{
    return _hashTable->FindItem(key, value);
}


HashTable* Dictionary::GetHashTable()
{
    return _hashTable;
}
