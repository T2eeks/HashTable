#pragma once
#include <string>

struct HashTableItem
{
    std::string Key;
    std::string Value;
    HashTableItem* Next;

    HashTableItem(const std::string& key, const std::string& value, HashTableItem* next = nullptr)
        : Key(key), Value(value), Next(next) {}
};
