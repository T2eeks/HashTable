#include "../Header Files/HashTable.h"
#include <vector>
#include <ctime>
#include <cstdlib>

// TODO: внести в класс HashTable
static int PearsonHash(const std::string& key, int tableSize)
{
    // TODO: Вынести 256 в константу внутри метода
    static std::vector<int> T(256);
    static bool initialized = false;

    if (!initialized)
    {
        for (int i = 0; i < 256; i++) T[i] = i;
        std::srand(std::time(nullptr));
        for (int i = 0; i < 256; i++)
        {
            std::swap(T[i], T[rand() % 256]);
        }
        initialized = true;
    }

    int hash = 0;
    for (char c : key) hash = T[(hash ^ c) % 256];
    return hash % tableSize;
}

HashTable::HashTable()
{
    _hashTableSize = 8; 
    _length = 0;
    InitHashTable();
}

HashTable::~HashTable()
{
    DeleteHashTable();
}


void HashTable::InitHashTable()
{
    _data = new HashTableItem * [_hashTableSize]();
}

int HashTable::GetLength() const
{
    return _length;
}

void HashTable::SetLength(int length)
{
    _length = length;
}

int HashTable::GetHashTableSize() const 
{
    return _hashTableSize;
}

void HashTable::SetHashTableSize(int size) 
{
    _hashTableSize = size;
}

HashTableItem** HashTable::GetData() const
{
    return _data;
}

void HashTable::SetData(HashTableItem** data)
{
    _data = data;
}

void HashTable::DeleteHashTable()
{
    for (int i = 0; i < _hashTableSize; i++)
    {
        HashTableItem* current = _data[i];
        while (current) 
        {
            HashTableItem* toDelete = current;
            current = current->Next;
            delete toDelete;
        }
    }
    delete[] _data;
    _data = nullptr;
}


int HashTable::AddElement(const std::string& key, const std::string& value) 
{
    int index = PearsonHash(key, _hashTableSize);
    HashTableItem* current = _data[index];

    while (current) 
    {
        if (current->Key == key && current->Value == value) 
        {
            return 1;
        }
        current = current->Next;
    }

    _data[index] = new HashTableItem(key, value, _data[index]);
    _length++;

    if (IsNeedToRehashing())
    {
        Rehashing();
        return true;
    }

    return false;
}


bool HashTable::FindItem(const std::string& key, std::string& value)
{
    int index = PearsonHash(key, _hashTableSize);
    HashTableItem* current = _data[index];

    while (current)
    {
        if (current->Key == key)
        {
            value = current->Value; 
            return true; 
        }
        current = current->Next;
    }
    return false; 
}


bool HashTable::RemoveItem(std::string& key, std::string& value)
{
    int index = PearsonHash(key, _hashTableSize);
    HashTableItem* current = _data[index];
    HashTableItem* prev = nullptr;

    while (current)
    {
        if (current->Key == key)
        {
            if (prev)
            {
                prev->Next = current->Next;
            }
            else
            {
                _data[index] = current->Next;
            }

            value = current->Value; 
            delete current;
            _length--;
            return true; 
        }
        prev = current;
        current = current->Next;
    }
    return false; 
}

bool HashTable::IsNeedToRehashing()
{
    // TODO: Вынести в константу внутри метода
    return static_cast<double>(_length) / _hashTableSize > 0.8;
}

bool HashTable::Rehashing()
{
    int newSize = _hashTableSize * 2;

    HashTableItem** newData = new HashTableItem * [newSize]();
    if (!newData) 
    {
        return false; 
    }

    for (int i = 0; i < _hashTableSize; i++)
    {
        HashTableItem* current = _data[i];
        while (current)
        {

            int newIndex = PearsonHash(current->Key, newSize);
            HashTableItem* next = current->Next;

            current->Next = newData[newIndex];
            newData[newIndex] = current;

            current = next;
        }
    }

    delete[] _data;

    _data = newData;
    _hashTableSize = newSize;

    return true;

}

