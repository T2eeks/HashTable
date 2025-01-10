#pragma once
#include "HashTable.h"
#include <string>

//! \brief ���������� ������� ��������� ���-�������
//! \param hashTable ��������� �� ���-�������
void ShowHashTable(const HashTable* hashTable);

//! \brief �������� ���� �� ������������
//! \return ��������� ����
std::string GetKey();

//! \brief �������� ������� ���� ���������
void ShowMenu();
