#pragma once
#include "HashTableItem.h"
#include <string>

//! \brief Структура, представляющая хеш-таблицу
struct HashTable
{
private:
    //! \brief Количество элементов в таблице
    int _length = 0;

    //! \brief Размер таблицы
    int _hashTableSize = 8;

    //! \brief Массив указателей на элементы таблицы
    HashTableItem** _data;

public:
    //! \brief Конструктор для инициализации хеш-таблицы
    HashTable();

    //! \brief Деструктор для освобождения памяти
    ~HashTable();

    //! \brief Получить количество элементов в таблице
     //! \return Количество элементов
    int GetLength() const;

    //! \brief Установить количество элементов в таблице
    //! \param length Новое количество элементов
    void SetLength(int length);

    //! \brief Получить размер таблицы
    //! \return Размер таблицы
    int GetHashTableSize() const;

    //! \brief Установить размер таблицы
    //! \param size Новый размер таблицы
    void SetHashTableSize(int size);

    //! \brief Получить массив данных таблицы
    //! \return Указатель на массив данных
    HashTableItem** GetData() const;

    //! \brief Установить массив данных таблицы
    //! \param data Новый массив данных
    void SetData(HashTableItem** data);

    //! \brief Инициализация хеш-таблицы
    //! \param hashTable Указатель на хеш-таблицу
    void InitHashTable();

    //! \brief Удалить хеш-таблицу
    //! \param hashTable Указатель на хеш-таблицу
    void DeleteHashTable();

    //! \brief Добавить элемент в хеш-таблицу
    //! \param key Ключ элемента
    //! \param value Значение элемента
    //! \return Код состояния добавления
    int AddElement(const std::string& key, const std::string& value);

    //! \brief Найти элемент в хеш-таблице
    //! \param key Ключ элемента
    //! \param value Переменная для сохранения найденного значения
    //! \return true, если элемент найден, иначе false
    bool FindItem(const std::string& key, std::string& value);

    //! \brief Удалить элемент из хеш-таблицы
    //! \param key Ключ элемента
    //! \param value Переменная для сохранения удалённого значения
    //! \return true, если элемент успешно удалён, иначе false
    bool RemoveItem(std::string& key, std::string& value);

    //! \brief Проверка необходимости рехэширования
    //! \return true, если рехэширование необходимо, иначе false
    bool IsNeedToRehashing();

    //! \brief Выполнить рехэширование хеш-таблицы
    //! \param hashTable Указатель на хеш-таблицу
    bool Rehashing();
  
};
