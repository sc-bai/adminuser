#pragma once
#include "stdafx.h"
/*
	��Ŀ
*/
class Column {
public:
	Column(std::string strName) :
		m_strColumn(strName) {

	}
	std::string GetColumnName() {
		return m_strColumn;
	}
private:
	std::string m_strColumn;
};

class ColumnManager {

public:
	ColumnManager(){ m_vecList.clear(); }
	~ColumnManager() {
		for (int i = 0; i < m_vecList.size(); i++)
		{
			delete m_vecList[i];
		}
		m_vecList.clear();
	}
	void AddColumn(Column* c) {
		if (c) {
			cout << "�����Ŀ��" << endl;
			for (auto &item : m_vecList)
			{
				if (item->GetColumnName() == c->GetColumnName()) {
					delete c;
					c = nullptr;
					cout << "����Ŀ�Ѵ���" << endl;
					return;
				}
			}
			m_vecList.push_back(c);
			cout << "�����Ŀ�ɹ�" << endl;
		}
	}

	void DeleteColumn(std::string strName) {
		
		cout << "ɾ����Ŀ��" << strName << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			if (m_vecList[i]->GetColumnName() == strName) {

				m_vecList.erase(m_vecList.begin()+i);
				cout << "ɾ����Ŀ�ɹ�" << endl;
				return;
			}
		}
		cout << "δ��ѯ������Ŀ��" << strName << endl;
	}

	bool existColumn(std::string strName) {
		for (auto& item : m_vecList)
		{
			if (item->GetColumnName() == strName) {
				return true;
			}
		}

		return false;
	}
	void ShowColumn() {
		cout << "��Ŀ�б�" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout <<"��Ŀ���ƣ�" <<m_vecList[i]->GetColumnName() << endl;
		}
	}
private:
	std::vector<Column*> m_vecList;
};