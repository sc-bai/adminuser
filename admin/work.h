#pragma once
#include "column.h"
#include "content.h"
#include "user.h"
#include "caccess.h"

class Work {
public:

	Work() {
		// Ĭ������������Ŀ
		m_columnManager.AddColumn(new Column("��Ӱ"));
		m_columnManager.AddColumn(new Column("���Ӿ�"));
		m_columnManager.AddColumn(new Column("����Ƶ"));

		// for test
		m_columnManager.AddColumn(new Column("ni"));
		m_userManager.addUser(new User("mrbai", "123"));
		m_ctxManager.AddContent(new	VideoContent("hello1", 1, "ni", 1));
		m_ctxManager.AddContent(new	VideoContent("hello2", 2, "ni", 0));
		// end test

		m_access.SetManagerInfo(&m_ctxManager, &m_userManager);
	}
	~Work() {
		if (m_CurrentUser) {
			delete m_CurrentUser;
			m_CurrentUser = nullptr;
		}
	}

	void Pause() {
		fflush(stdin);
		getchar();
		getchar();
		return;
	}
	void SetCurrentUser(std::string strUserName, std::string strPasswd) {
		if (m_CurrentUser == NULL) {
			m_CurrentUser = new User(strUserName, strPasswd);
		}
		m_CurrentUser->setUserName(strUserName);
		m_CurrentUser->setPassword(strPasswd);
	}
	void addAdminInfo(std::string name, std::string strpsw) {
		m_userManager.addUser(name, strpsw);
	}
	bool doUserLogin(std::string name, std::string strpsw) {
		return m_userManager.UserLogin(name, strpsw);
	}

	// ��ͨ�û�ģ��
	void doUserAction(int iAction) {

		cout << endl;

		if (iAction == 1) {
			// �����б�
			m_ctxManager.showContentList();
		}
		else if (iAction == 2) {
			// ��������
			m_ctxManager.showContentListDetail();
		}
		else if (iAction == 3) {
			// ��������
			string strName;
			cout << "�������������ƣ�";
			cin >> strName;
			m_ctxManager.ShowContentItemDetail(strName);

			// ������ʼ�¼��
			VideoContent ctx;
			if (m_ctxManager.FindCtxFormName(strName, ctx)) {
				m_access.PushAccHistory(m_CurrentUser->getUsername(), ctx);
			}
		}
		else if (iAction == 4) {
			// �޸�����
			string str, str1;
			cout << "�����������룺";
			cin >> str;
			cout << "���ٴ����������룺";
			cin >> str1;
			if (str == str1) {
				m_CurrentUser->setPassword(str);
				m_userManager.ModifyUser(m_CurrentUser);
			}
		}
		Pause();
	}

	// ����Ա-��Ŀ����
	void doAdminActionColumnModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// ������Ŀ
			string strName;
			cout << "��������Ŀ���ƣ�";
			cin >> strName;
			m_columnManager.AddColumn(new Column(strName));
		}
		else if (action == 3) {
			// ɾ����Ŀ
			string strName;
			cout << "��������Ŀ���ƣ�";
			cin >> strName;
			m_columnManager.DeleteColumn(strName);
		}
		else if (action == 2) {
			// �鿴��Ŀ�б�
			m_columnManager.ShowColumn();
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// ����Ա-���ݹ���
	void doAdminActionContextModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// ��������
			string name, duration, category, isfree;
			cout << "���������ƣ�";
			cin >> name;
			cout << "������ʱ��(min)��";
			cin >> duration;
			cout << "��������ࣺ";
			cin >> category;
			cout << "�������Ƿ����(0,1)��";
			cin >> isfree;
			
			// �жϸ���Ŀ�Ƿ����
			if (m_columnManager.existColumn(category)) {
				m_ctxManager.addContent(name, atoi(duration.c_str()), category, atoi(isfree.c_str()));
			}
			else {
				cout << "����ķ�����Ŀ������" << endl;
			}
		}
		else if (action == 3) {
			// ɾ������
			string name;
			cout << "���������ƣ�";
			cin >> name;
			m_ctxManager.DeleteContent(name);
		}
		else if (action == 2) {
			// �鿴�����б�
			m_ctxManager.showContentListDetail();
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// ����Ա-�û�����
	void doAdminActionUserModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// �����û�
			string username, password;
			cout << "�������û�����";
			cin >> username;
			cout << "���������룺";
			cin >> password;
			m_userManager.addUser(username, password);
		}
		else if (action == 2) {
			// �û��б�
			m_userManager.showUserList();
		}
		else if (action == 3) {
			// ɾ���û�
			string username;
			cout << "�������û�����";
			cin >> username;
			m_userManager.deleteUser(username);
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// ����Ա-�û����ʼ�¼����
	void doAdminActionVisitorModule(int action) {
		cout << endl;
		cout << endl;
		m_access.ShowAllHistory();
		Pause();
	}
	// ����Ա-ͳ��
	void doAdminActionTJModule(int action) {
		cout << endl;
		cout << endl;
		m_access.Statistics();
		Pause();
	}

private:
	User*			m_CurrentUser;	// ��ǰ�û�
	UserManager		m_userManager;
	ContentManager	m_ctxManager;
	ColumnManager	m_columnManager;
	CAccess			m_access;
};
