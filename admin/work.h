#pragma once
#include "column.h"
#include "content.h"
#include "user.h"
#include "caccess.h"

class Work {
public:

	Work() {
		// 默认增加三个栏目
		m_columnManager.AddColumn(new Column("电影"));
		m_columnManager.AddColumn(new Column("电视剧"));
		m_columnManager.AddColumn(new Column("短视频"));

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

	// 普通用户模块
	void doUserAction(int iAction) {

		cout << endl;

		if (iAction == 1) {
			// 内容列表
			m_ctxManager.showContentList();
		}
		else if (iAction == 2) {
			// 内容详情
			m_ctxManager.showContentListDetail();
		}
		else if (iAction == 3) {
			// 访问内容
			string strName;
			cout << "请输入内容名称：";
			cin >> strName;
			m_ctxManager.ShowContentItemDetail(strName);

			// 插入访问记录中
			VideoContent ctx;
			if (m_ctxManager.FindCtxFormName(strName, ctx)) {
				m_access.PushAccHistory(m_CurrentUser->getUsername(), ctx);
			}
		}
		else if (iAction == 4) {
			// 修改密码
			string str, str1;
			cout << "请输入新密码：";
			cin >> str;
			cout << "请再次输入新密码：";
			cin >> str1;
			if (str == str1) {
				m_CurrentUser->setPassword(str);
				m_userManager.ModifyUser(m_CurrentUser);
			}
		}
		Pause();
	}

	// 管理员-栏目管理
	void doAdminActionColumnModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// 增加栏目
			string strName;
			cout << "请输入栏目名称：";
			cin >> strName;
			m_columnManager.AddColumn(new Column(strName));
		}
		else if (action == 3) {
			// 删除栏目
			string strName;
			cout << "请输入栏目名称：";
			cin >> strName;
			m_columnManager.DeleteColumn(strName);
		}
		else if (action == 2) {
			// 查看栏目列表
			m_columnManager.ShowColumn();
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// 管理员-内容管理
	void doAdminActionContextModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// 增加内容
			string name, duration, category, isfree;
			cout << "请输入名称：";
			cin >> name;
			cout << "请输入时长(min)：";
			cin >> duration;
			cout << "请输入分类：";
			cin >> category;
			cout << "请输入是否免费(0,1)：";
			cin >> isfree;
			
			// 判断该栏目是否存在
			if (m_columnManager.existColumn(category)) {
				m_ctxManager.addContent(name, atoi(duration.c_str()), category, atoi(isfree.c_str()));
			}
			else {
				cout << "输入的分类栏目不存在" << endl;
			}
		}
		else if (action == 3) {
			// 删除内容
			string name;
			cout << "请输入名称：";
			cin >> name;
			m_ctxManager.DeleteContent(name);
		}
		else if (action == 2) {
			// 查看内容列表
			m_ctxManager.showContentListDetail();
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// 管理员-用户管理
	void doAdminActionUserModule(int action) {
		cout << endl;
		cout << endl;
		if (action == 1) {
			// 增加用户
			string username, password;
			cout << "请输入用户名：";
			cin >> username;
			cout << "请输入密码：";
			cin >> password;
			m_userManager.addUser(username, password);
		}
		else if (action == 2) {
			// 用户列表
			m_userManager.showUserList();
		}
		else if (action == 3) {
			// 删除用户
			string username;
			cout << "请输入用户名：";
			cin >> username;
			m_userManager.deleteUser(username);
		}
		else if (action == 4) {
			// back
		}
		Pause();
	}

	// 管理员-用户访问记录管理
	void doAdminActionVisitorModule(int action) {
		cout << endl;
		cout << endl;
		m_access.ShowAllHistory();
		Pause();
	}
	// 管理员-统计
	void doAdminActionTJModule(int action) {
		cout << endl;
		cout << endl;
		m_access.Statistics();
		Pause();
	}

private:
	User*			m_CurrentUser;	// 当前用户
	UserManager		m_userManager;
	ContentManager	m_ctxManager;
	ColumnManager	m_columnManager;
	CAccess			m_access;
};
