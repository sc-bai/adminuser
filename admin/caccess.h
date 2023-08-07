#pragma once
#include "stdafx.h"
#include "content.h"

struct History {
	std::string strUserName;
	VideoContent ctx;
};

class CAccess {
public:
	CAccess() {
		m_ctxManager = nullptr;
		m_vecList.clear();
	}
	~CAccess() { m_vecList.clear(); }

	void SetManagerInfo(ContentManager* p, UserManager* pp) {
		m_ctxManager = p;
		m_pUserManager = pp;
	}

	void PushAccHistory(std::string strUserName, VideoContent cont) {
		m_vecList.push_back(History{ strUserName , cont });
	}

	// չʾ��ǰ�û� ��������Щ����
	void ShowUserAccHistory(std::string strUserName) {
		int iCount = 0;
		cout << "��ǰ�û��������������ݣ�" << endl;
		for (int i=0; i<m_vecList.size();i++)
		{
			if (m_vecList[i].strUserName == strUserName) {
				iCount++;
				cout << "���ƣ�" << m_vecList[i].ctx.getName();
				cout << "	ʱ����" << m_vecList[i].ctx.getDuration() << "����";
				cout << "	���ࣺ" << m_vecList[i].ctx.getCategory();
				cout << "	�Ƿ���ѣ�" << (m_vecList[i].ctx.getIsFree() ? "��" : "��");
				cout << endl;
			}
		}

		if (iCount == 0) {
			cout << "��δ�������ݣ�" << endl;
		}
	}

	void ShowAllHistory()
	{
		cout << "���ݷ��ʼ�¼��" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout << "�û�����" << m_vecList[i].strUserName<<" �����˸����ݣ�";
			cout << "���ƣ�" << m_vecList[i].ctx.getName();
			cout << "	ʱ����" << m_vecList[i].ctx.getDuration() << "����";
			cout << "	���ࣺ" << m_vecList[i].ctx.getCategory();
			cout << "	�Ƿ���ѣ�" << (m_vecList[i].ctx.getIsFree() ? "��" : "��");
			cout << endl;
		}
		if (m_vecList.size() == 0) {
			cout << "��" << endl;
		}
	}

	// ͳ�����з������

	void Statistics() {
		cout << "ͳ�ƣ�" << endl;

		int iCount = 0;
		// �û� ��������Щ���� 
		auto users = m_pUserManager->GetUserList();
		for (int i  =0;i< users.size();i++)
		{
			iCount = 0;
			cout << "���û���" << users[i]->getUsername() << " �������������ݣ�"<<endl;
			for (int j=0;j< m_vecList.size();j++)
			{
				if (users[i]->getUsername() == m_vecList[j].strUserName) {
					cout << "	���ƣ�" << m_vecList[j].ctx.getName();
					cout << "	ʱ����" << m_vecList[j].ctx.getDuration() << "����";
					cout << "	���ࣺ" << m_vecList[j].ctx.getCategory();
					cout << "	�Ƿ���ѣ�" << (m_vecList[j].ctx.getIsFree() ? "��" : "��");
					cout << endl;
					iCount++;
				}
			}
			if(iCount == 0){
				cout << "���û�û�з������ݣ�" << endl;
			}
			cout << endl;
			cout << endl;
		}

		// ���ݱ������˶��ٴ�
		iCount = 0;
		auto ctxs = m_ctxManager->GetContentList();
		for (int i = 0; i < ctxs.size(); i++)
		{
			iCount = 0;
			cout << "�����ݣ�" << ctxs[i]->getName() << " �������ˣ�";
			for (int j = 0; j < m_vecList.size(); j++)
			{
				if (ctxs[i]->getName() == m_vecList[j].ctx.getName()) {
					iCount++;
				}
			}
			cout << iCount << "��" << endl;
			cout << endl;
			cout << endl;
		}
	}
private:
	std::vector<History> m_vecList;
	ContentManager* m_ctxManager;
	UserManager* m_pUserManager;
};
