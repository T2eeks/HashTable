#pragma once
#include "HashTable.h"
#include "Dictionary.h"
#include <string>

//! \brief Отобразить текущее состояние хеш-таблицы
//! \param hashTable Указатель на хеш-таблицу
void ShowHashTable(const HashTable* hashTable);

//! \brief Показать текущее состояние словаря
//! \param dictionary Указатель на словарь
void ShowDictionary(const Dictionary* dictionary);

//! \brief Получить ключ от пользователя
//! \return Введенный ключ
std::string GetKey();

//! \brief Показать главное меню программы
void ShowMenu();

//! \brief Выбор структуры данных
//! \return true, если выбрана хэш-таблица; false, если выбран словарь
bool ChooseDataStructure(bool& exitProgram);
