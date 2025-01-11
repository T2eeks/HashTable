#pragma once
#include "HashTable.h"
#include "Dictionary.h"
#include <string>
// TODO: Полетела кодировка
//! \brief ���������� ������� ��������� ���-�������
//! \param hashTable ��������� �� ���-�������
void ShowHashTable(const HashTable* hashTable);

//! \brief �������� ������� ��������� �������
//! \param dictionary ��������� �� �������
void ShowDictionary(const Dictionary* dictionary);

//! \brief �������� ���� �� ������������
//! \return ��������� ����
std::string GetKey();

//! \brief �������� ������� ���� ���������
void ShowMenu();

//! \brief ����� ��������� ������
//! \return true, ���� ������� ���-�������; false, ���� ������ �������
bool ChooseDataStructure(bool& exitProgram);
