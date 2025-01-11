#pragma once
#include "HashTable.h"
#include <string>

// TODO: Полетела кодировка
//! \brief ����� ��� ������ � ���-�������� (�������)
class Dictionary {
private:
    //! \brief ���-������� ��� �������� ������
    HashTable* _hashTable;

public:
    //! \brief ����������� ��� ������������� �������
    Dictionary();

    //! \brief ���������� ��� ������������ ������
    ~Dictionary();

    //! \brief �������� ���� ����-��������
    //! \param key ����
    //! \param value ��������
    bool Add(const std::string& key, const std::string& value);

    //! \brief ������� �������� �� �����
    //! \param key ����
    //! \param value ���������� ��� ���������� ��������� ��������
    //! \return true, ���� �������� ������� �������, ����� false
    bool Delete(const std::string& key, std::string& value);

    //! \brief ����� �������� �� �����
    //! \param key ����
    //! \param value ���������� ��� ���������� ���������� ��������
    //! \return true, ���� �������� �������, ����� false
    bool Search(const std::string& key, std::string& value);

    //! \brief �������� ������� ��������� ���-�������
    //! \return ��������� �� ���-�������
    HashTable* GetHashTable();
};
