#pragma once
#include "HashTable.h"
#include <string>

//! \brief Отобразить текущее состояние хеш-таблицы
//! \param hashTable Указатель на хеш-таблицу
void ShowHashTable(const HashTable* hashTable);

//! \brief Получить ключ от пользователя
//! \return Введенный ключ
std::string GetKey();

//! \brief Показать главное меню программы
void ShowMenu();
