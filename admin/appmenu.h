#pragma once
#include "stdafx.h"
#include "user.h"
class AppMenu {
public:
	static void Clear() {
		system("cls");
	}
	static int ShowUserMeun() {
		Clear();
		cout << "��ӭ����ͨ�û����������¹���Ȩ�ޣ�" << endl;
		cout << "1) �����б�" << endl;
		cout << "2) �鿴��������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) �޸�����" << endl;
		cout << "5) ������һ��" << endl;
		cout << "����������[1-5]: ";

		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 6) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}

	static int ShowAdminMenu() {
		Clear();
		cout << "��ӭ��" << "�����Ľ�ɫ�ǹ���Ա���������¹���Ȩ�ޣ�" << endl;
		cout << "1) ��Ŀ����" << endl;
		cout << "2) ���ݹ���" << endl;
		cout << "3) �û�����" << endl;
		cout << "4) �û����ʼ�¼����" << endl;
		cout << "5) ͳ��" << endl;
		cout << "6) �˳�" << endl;
		cout << "����������[1-6]: ";

		int choice;
		while (true){
			cin >> choice;
			if (choice > 0 && choice < 7) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}

	static int ShowColunmManagerMenu() {
		Clear();
		cout << "* ��ӭ������Ŀ����ģ�顭"<<endl;
		cout << "1) ������Ŀ" << endl;
		cout << "2) ��Ŀ�б�" << endl;
		cout << "3) ɾ����Ŀ" << endl;
		cout << "4) ������һ��" << endl;
		cout << "����������[1-4]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}
	static int ShowContentManagerMenuAdmin() {
		Clear();
		cout << "* ��ӭ�������ݹ���ģ�顭" << endl;
		cout << "1) ��������" << endl;
		cout << "2) �����б�" << endl;
		cout << "3) ɾ������" << endl;
		cout << "4) ������һ��" << endl;
		cout << "����������[1-4]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}
	static int ShowUserManagerMenu() {
		Clear();
		cout << "* ��ӭ�����û�����ģ�顭" << endl;
		cout << "1) �����û�" << endl;
		cout << "2) �û��б�" << endl;
		cout << "3) ɾ���û�" << endl;
		cout << "4) ������һ��" << endl;
		cout << "����������[1-4]: ";

		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}
	static int ShowUserVistorManagerMenu() {
		Clear();
		cout << "* ��ӭ�����û����ʼ�¼����ģ�顭" << endl;
		cout << "1) ��ѯ" << endl;
		cout << "2) ������һ��" << endl;
		cout << "����������[1-2]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 3) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}
	static int ShowStatisticsManagerMenu() {
		Clear();
		cout << "* ��ӭ����ͳ�ƹ���ģ�顭" << endl;
		cout << "1) ��ѯ" << endl;
		cout << "2) ������һ��" << endl;
		cout << "����������[1-2]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 3) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}

};