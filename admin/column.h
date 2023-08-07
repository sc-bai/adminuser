#pragma once
#include "stdafx.h"
/*
	栏目
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
			cout << "添加栏目：" << endl;
			for (auto &item : m_vecList)
			{
				if (item->GetColumnName() == c->GetColumnName()) {
					delete c;
					c = nullptr;
					cout << "该栏目已存在" << endl;
					return;
				}
			}
			m_vecList.push_back(c);
			cout << "添加栏目成功" << endl;
		}
	}

	void DeleteColumn(std::string strName) {
		
		cout << "删除栏目：" << strName << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			if (m_vecList[i]->GetColumnName() == strName) {

				m_vecList.erase(m_vecList.begin()+i);
				cout << "删除栏目成功" << endl;
				return;
			}
		}
		cout << "未查询到该栏目：" << strName << endl;
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
		cout << "栏目列表：" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout <<"栏目名称：" <<m_vecList[i]->GetColumnName() << endl;
		}
	}
private:
	std::vector<Column*> m_vecList;
};