#pragma once
#include "HashTable.h"
#include <string>

// TODO: Полетела кодировка
//! \brief Класс для работы с хеш-таблицей
class Dictionary {
private:
    //! \brief Хеш-таблица для хранения данных
    HashTable* _hashTable;

public:
    //! \brief Конструктор для инициализации словаря
    Dictionary();

    //! \brief Деструктор для освобождения памяти
    ~Dictionary();

    //! \brief Добавить пару ключ-значение
    //! \param key Ключ
    //! \param value Значение
    bool Add(const std::string& key, const std::string& value);

    //! \brief Удалить значение по ключу
     //! \param key Ключ
     //! \param value Переменная для сохранения удалённого значения
     //! \return true, если значение успешно удалено, иначе false
    bool Delete(const std::string& key, std::string& value);

    //! \brief Найти значение по ключу
    //! \param key Ключ
    //! \param value Переменная для сохранения найденного значения
    //! \return true, если значение найдено, иначе false
    bool Search(const std::string& key, std::string& value);

    //! \brief Получить текущее состояние хеш-таблицы
    //! \return Указатель на хеш-таблицу
    HashTable* GetHashTable();
};
