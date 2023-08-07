#pragma once
#include <string>
using namespace std;

// 用户类
class User {
protected:
	string username;
	string password;

public:
	User(string username, string password) {
		this->username = username;
		this->password = password;
	}
	void setUserName(std::string str) {
		username = str;
	}
	string getUsername() {
		return username;
	}

	string getPassword() {
		return password;
	}

	void setPassword(string password) {
		this->password = password;
	}
};

// 管理员类
class Admin : public User {
public:
	Admin(string username, string password) : User(username, password) {}
};

// 普通用户类
class Member : public User {
public:
	Member(string username, string password) : User(username, password) {}
};

class UserManager {
public:

	~UserManager() {
		for (int i = 0; i < users.size(); i++) {
			if (users[i]) {
				delete users[i];
			}
		}
		users.clear();
	}

	bool UserLogin(string username, string password) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i]->getUsername() == username && users[i]->getPassword() == password) {
				return true;
			}
		}
		return false;
	}
	void addUser(string username, string password) {
		cout << "添加用户：" << endl;
		for (auto& item : users)
		{
			if (item->getUsername() == username) {
				cout << "该用户已存在" << endl;
				return;
			}
		}

		users.push_back(new Member(username, password));
		cout << "用户已添加" << endl;
	}
	void addUser(User* user) {
		if (user != nullptr) {
			cout << "添加用户：" << endl;
			for (auto& item : users)
			{
				if (item->getUsername() == user->getUsername()) {
					cout << "该用户已存在" << endl;
					return;
				}
			}
			users.push_back(user);
			cout << "用户已添加" << endl;
		}
	}

	void ModifyUser(User* user) {
		if (user != nullptr) {
			cout << "修改用户密码：" << endl;
			for (auto& item : users)
			{
				if (item->getUsername() == user->getUsername()) {
					item->setPassword(user->getPassword());
					cout << "当前用户密码已修改" << endl;
					return;
				}
			}
		}
	}
	
	void deleteUser(string username) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i]->getUsername() == username) {
				users.erase(users.begin() + i);
				cout << "用户已删除" << endl;
				return;
			}
		}
		cout << "用户不存在" << endl;
	}

	void showUserList() {
		cout << "用户列表：" << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "用户名：" << users[i]->getUsername() << endl;
		}
	}
	vector<User*> GetUserList() {
		return users;
	}
	
private:
	vector<User*> users;
};
