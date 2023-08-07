#include "stdafx.h"
#include "appmenu.h"
#include "user.h"
#include "content.h"
#include "column.h"
#include "work.h"

class VideoSystem {
public:
	VideoSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {
		// Ĭ�����һ������Ա�����������û��Ͳ���ʹ��admin�����ˡ�
		m_work.addAdminInfo(adminUsername, adminPassword);
	}
	void StartSystem() {
		while (true) {
			int choice = 0, ret = 0;
			while (true)
			{
				AppMenu::Clear();
				cout << "��ӭ��ʹ��������Ƶϵͳ" << endl;
				cout << "1) ����Ա" << endl;
				cout << "2) ��ͨ�û�" << endl;
				cout << "3) �˳�ϵͳ" << endl;
				cout << "��ѡ���¼�û�����[1-3]: ";

				cin >> choice;

				// ����Աģ��
				if (choice == 1) {

					// admin login
					/*
					string username, password;
					cout << "���������Ա�û�����";
					cin >> username;
					cout << "���������Ա���룺";
					cin >> password;
					*/
					string username="admin", password="123456";
					if (username == admin.getUsername() && password == admin.getPassword()) {
						m_work.SetCurrentUser(username, password);
						DoWithAdmin();
					}
					else {
						cout << "��¼ʧ��,�û���������������";
					}
				}

				// ��ͨ�û�ģ��
				else if (choice == 2) {
					/*
					string username, password;
					cout << "�������û�����";
					cin >> username;
					cout << "���������룺";
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
						cout << "�û���¼ʧ��" << endl;
						break;
					}
				}
				else if (choice == 3) {
					cout << "ϵͳ���˳�" << endl;
					return;
				}
				else {
					cout << "��Ч��ѡ��, �������������" << endl;
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

			// ��Ŀ����
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
			// ���ݹ���
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
			// �û�����
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

			// ���ʹ���
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
			// ͳ��
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
			// �˵���һ��
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