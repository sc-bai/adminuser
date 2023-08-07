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
		cout << "欢迎您普通用户！具有如下功能权限：" << endl;
		cout << "1) 内容列表" << endl;
		cout << "2) 查看内容详情" << endl;
		cout << "3) 访问内容" << endl;
		cout << "4) 修改密码" << endl;
		cout << "5) 返回上一级" << endl;
		cout << "请输入命令[1-5]: ";

		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 6) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}

	static int ShowAdminMenu() {
		Clear();
		cout << "欢迎您" << "，您的角色是管理员！具有如下功能权限：" << endl;
		cout << "1) 栏目管理" << endl;
		cout << "2) 内容管理" << endl;
		cout << "3) 用户管理" << endl;
		cout << "4) 用户访问记录管理" << endl;
		cout << "5) 统计" << endl;
		cout << "6) 退出" << endl;
		cout << "请输入命令[1-6]: ";

		int choice;
		while (true){
			cin >> choice;
			if (choice > 0 && choice < 7) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}

	static int ShowColunmManagerMenu() {
		Clear();
		cout << "* 欢迎进入栏目管理模块…"<<endl;
		cout << "1) 增加栏目" << endl;
		cout << "2) 栏目列表" << endl;
		cout << "3) 删除栏目" << endl;
		cout << "4) 返回上一级" << endl;
		cout << "请输入命令[1-4]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}
	static int ShowContentManagerMenuAdmin() {
		Clear();
		cout << "* 欢迎进入内容管理模块…" << endl;
		cout << "1) 增加内容" << endl;
		cout << "2) 内容列表" << endl;
		cout << "3) 删除内容" << endl;
		cout << "4) 返回上一级" << endl;
		cout << "请输入命令[1-4]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}
	static int ShowUserManagerMenu() {
		Clear();
		cout << "* 欢迎进入用户管理模块…" << endl;
		cout << "1) 增加用户" << endl;
		cout << "2) 用户列表" << endl;
		cout << "3) 删除用户" << endl;
		cout << "4) 返回上一级" << endl;
		cout << "请输入命令[1-4]: ";

		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 5) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}
	static int ShowUserVistorManagerMenu() {
		Clear();
		cout << "* 欢迎进入用户访问记录管理模块…" << endl;
		cout << "1) 查询" << endl;
		cout << "2) 返回上一级" << endl;
		cout << "请输入命令[1-2]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 3) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}
	static int ShowStatisticsManagerMenu() {
		Clear();
		cout << "* 欢迎进入统计管理模块…" << endl;
		cout << "1) 查询" << endl;
		cout << "2) 返回上一级" << endl;
		cout << "请输入命令[1-2]: ";
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 3) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}

};