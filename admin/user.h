#pragma once
#include <string>
using namespace std;

// �û���
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

// ����Ա��
class Admin : public User {
public:
	Admin(string username, string password) : User(username, password) {}
};

// ��ͨ�û���
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
		cout << "����û���" << endl;
		for (auto& item : users)
		{
			if (item->getUsername() == username) {
				cout << "���û��Ѵ���" << endl;
				return;
			}
		}

		users.push_back(new Member(username, password));
		cout << "�û������" << endl;
	}
	void addUser(User* user) {
		if (user != nullptr) {
			cout << "����û���" << endl;
			for (auto& item : users)
			{
				if (item->getUsername() == user->getUsername()) {
					cout << "���û��Ѵ���" << endl;
					return;
				}
			}
			users.push_back(user);
			cout << "�û������" << endl;
		}
	}

	void ModifyUser(User* user) {
		if (user != nullptr) {
			cout << "�޸��û����룺" << endl;
			for (auto& item : users)
			{
				if (item->getUsername() == user->getUsername()) {
					item->setPassword(user->getPassword());
					cout << "��ǰ�û��������޸�" << endl;
					return;
				}
			}
		}
	}
	
	void deleteUser(string username) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i]->getUsername() == username) {
				users.erase(users.begin() + i);
				cout << "�û���ɾ��" << endl;
				return;
			}
		}
		cout << "�û�������" << endl;
	}

	void showUserList() {
		cout << "�û��б�" << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "�û�����" << users[i]->getUsername() << endl;
		}
	}
	vector<User*> GetUserList() {
		return users;
	}
	
private:
	vector<User*> users;
};
