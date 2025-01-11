#pragma once
#include <string>

//! \brief Структура элемента хеш-таблицы
//! \details Представляет собой узел в односвязном списке для разрешения коллизий методом цепочек
struct HashTableItem
{
    //! \brief Получить ключ элемента
    std::string Key;

    //! \brief Получить значение элемента
    std::string Value;

    //! \brief Указатель на следующий элемент в списке
    HashTableItem* Next;

    //! \brief Конструктор элемента хеш-таблицы
    //! \param key Ключ элемента
    //! \param value Значение элемента
    //! \param next Указатель на следующий элемент в списке 
    HashTableItem(const std::string& key, const std::string& value, HashTableItem* next = nullptr)
        : Key(key), Value(value), Next(next) {}
};
