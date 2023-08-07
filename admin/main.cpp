#include "stdafx.h"
#include "appmenu.h"
#include "user.h"
#include "content.h"
#include "column.h"
#include "work.h"

class VideoSystem {
public:
	VideoSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {
		// 默认添加一个管理员，这样其他用户就不能使用admin名称了。
		m_work.addAdminInfo(adminUsername, adminPassword);
	}
	void StartSystem() {
		while (true) {
			int choice = 0, ret = 0;
			while (true)
			{
				AppMenu::Clear();
				cout << "欢迎您使用在线视频系统" << endl;
				cout << "1) 管理员" << endl;
				cout << "2) 普通用户" << endl;
				cout << "3) 退出系统" << endl;
				cout << "请选择登录用户类型[1-3]: ";

				cin >> choice;

				// 管理员模块
				if (choice == 1) {

					// admin login
					/*
					string username, password;
					cout << "请输入管理员用户名：";
					cin >> username;
					cout << "请输入管理员密码：";
					cin >> password;
					*/
					string username="admin", password="123456";
					if (username == admin.getUsername() && password == admin.getPassword()) {
						m_work.SetCurrentUser(username, password);
						DoWithAdmin();
					}
					else {
						cout << "登录失败,用户名或者密码有误";
					}
				}

				// 普通用户模块
				else if (choice == 2) {
					/*
					string username, password;
					cout << "请输入用户名：";
					cin >> username;
					cout << "请输入密码：";
					cin >> password;
					*/
					string username = "mrbai", password = "123456";
					if (m_work.doUserLogin(username, password)) {
						m_work.SetCurrentUser(username, password);
						while (true)
						{
							ret = AppMenu::ShowUserMeun();
							if (ret == 5) {
								break;
							}
							m_work.doUserAction(ret);
						}
					}
					else {
						cout << "用户登录失败" << endl;
						break;
					}
				}
				else if (choice == 3) {
					cout << "系统已退出" << endl;
					return;
				}
				else {
					cout << "无效的选择, 请重新输入命令：" << endl;
				}
			}
		}
	}

	void DoWithAdmin() {
		int ret = 0;
		while (true)
		{
			AppMenu::Clear();
			ret = AppMenu::ShowAdminMenu();

			// 栏目管理
			if (ret == 1) {
				while (true)
				{
					AppMenu::Clear();
					int naction = AppMenu::ShowColunmManagerMenu();
					if (naction == 4) {
						break;
					}
					m_work.doAdminActionColumnModule(naction);
				}
			}
			// 内容管理
			else if (ret == 2) {
				while (true)
				{
					AppMenu::Clear();
					int naction = AppMenu::ShowContentManagerMenuAdmin();
					if (naction == 4) {
						break;
					}
					m_work.doAdminActionContextModule(naction);
				}
			}
			// 用户管理
			else if (ret == 3) {
				while (true)
				{
					AppMenu::Clear();
					int naction = AppMenu::ShowUserManagerMenu();
					if (naction == 4) {
						break;
					}
					m_work.doAdminActionUserModule(naction);
				}
			}

			// 访问管理
			else if (ret == 4) {
				while (true)
				{
					AppMenu::Clear();
					int naction = AppMenu::ShowUserVistorManagerMenu();
					if (naction == 2) {
						break;
					}
					m_work.doAdminActionVisitorModule(1);
				}
			}
			// 统计
			else if (ret == 5) {
				while (true)
				{
					AppMenu::Clear();
					int naction = AppMenu::ShowStatisticsManagerMenu();
					if (naction == 2) {
						break;
					}
					m_work.doAdminActionTJModule(0);
				}
			}
			// 退到上一层
			else if (ret == 6) {
				break;
			}
		}
	}

private:
	Admin admin;
	Work m_work;
};


int main() {
	VideoSystem vsystem("admin", "123456");
	vsystem.StartSystem();
	system("pause");
	return 0;
}