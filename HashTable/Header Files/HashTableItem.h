#pragma once
#include <string>

// TODO: Полетела кодировка
//! \brief ��������� �������� ���-�������
//! \details ������������ ����� ���� � ����������� ������ ��� ���������� �������� ������� �������
struct HashTableItem
{
    //! \brief �������� ���� ��������
    std::string Key;

    //! \brief �������� �������� ��������
    std::string Value;

    //! \brief ��������� �� ��������� ������� � ������
    HashTableItem* Next;

    //! \brief ����������� �������� ���-�������
    //! \param key ���� ��������
    //! \param value �������� ��������
    //! \param next ��������� �� ��������� ������� � ������ 
    HashTableItem(const std::string& key, const std::string& value, HashTableItem* next = nullptr)
        : Key(key), Value(value), Next(next) {}
};
