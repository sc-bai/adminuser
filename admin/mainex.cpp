#include <iostream>
#include <vector>
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
	ColumnManager() { m_vecList.clear(); }
	~ColumnManager() {
		for (int i = 0; i < m_vecList.size(); i++)
		{
			delete m_vecList[i];
		}
		m_vecList.clear();
	}
	void AddColumn(Column* c) {
		if (c) {
			cout << "�����Ŀ��" << endl;
			for (auto& item : m_vecList)
			{
				if (item->GetColumnName() == c->GetColumnName()) {
					delete c;
					c = nullptr;
					cout << "����Ŀ�Ѵ���" << endl;
					return;
				}
			}
			m_vecList.push_back(c);
			cout << "�����Ŀ�ɹ�" << endl;
		}
	}

	void DeleteColumn(std::string strName) {

		cout << "ɾ����Ŀ��" << strName << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			if (m_vecList[i]->GetColumnName() == strName) {

				m_vecList.erase(m_vecList.begin() + i);
				cout << "ɾ����Ŀ�ɹ�" << endl;
				return;
			}
		}
		cout << "δ��ѯ������Ŀ��" << strName << endl;
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
		cout << "��Ŀ�б�" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout << "��Ŀ���ƣ�" << m_vecList[i]->GetColumnName() << endl;
		}
	}
private:
	std::vector<Column*> m_vecList;
};

// ��Ƶ���ݻ���
class VideoContent {
protected:
	string name;
	int duration;
	string category;
	bool isFree;

public:
	VideoContent() {}
	VideoContent(string name, int duration, string category, bool isFree) {
		this->name = name;
		this->duration = duration;
		this->category = category;
		this->isFree = isFree;
	}

	string getName() {
		return name;
	}

	int getDuration() {
		return duration;
	}

	string getCategory() {
		return category;
	}

	bool getIsFree() {
		return isFree;
	}
};
// ��Ӱ��
class Movie : public VideoContent {
public:
	Movie(string name, int duration, string category, bool isFree) : VideoContent(name, duration, category, isFree) {}
};

// ���Ӿ���
class TVSeries : public VideoContent {
public:
	TVSeries(string name, int duration, string category, bool isFree) : VideoContent(name, duration, category, isFree) {}
};

class ContentManager {
public:
	ContentManager() {
		m_vecContentList.clear();
	}
	~ContentManager() {
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]) {
				delete m_vecContentList[i];
			}
		}
		m_vecContentList.clear();
	}
	void addContent(string name, int duration, string category, bool isFree) {
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == name) {
				cout << "�������Ѵ���" << endl;
				return;
			}
		}
		m_vecContentList.push_back(new VideoContent(name, duration, category, isFree));
		cout << "���������" << endl;
	}

	bool AddContent(VideoContent* ctx) {
		if (ctx != nullptr) {
			for (int i = 0; i < m_vecContentList.size(); i++) {
				if (m_vecContentList[i]->getName() == ctx->getName()) {
					cout << "�������Ѵ���" << endl;
					return false;
				}
			}
			m_vecContentList.push_back(ctx);
			cout << "���������" << endl;
			return true;
		}
	}
	bool DeleteContent(string name) {
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == name) {
				m_vecContentList.erase(m_vecContentList.begin() + i);
				cout << "������ɾ��" << endl;
				return true;
			}
		}
		cout << "δ���ҵ�������" << endl;
		return false;
	}

	void showContentList() {
		cout << "�����б�" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			cout << "���ƣ�" << m_vecContentList[i]->getName() << endl;
			cout << endl;
		}
	}

	void ShowContentItemDetail(std::string strname) {
		cout << "�������飺" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == strname) {
				cout << "���ƣ�" << m_vecContentList[i]->getName();
				cout << "	ʱ����" << m_vecContentList[i]->getDuration() << "����";
				cout << "	���ࣺ" << m_vecContentList[i]->getCategory();
				cout << "	�Ƿ���ѣ�" << (m_vecContentList[i]->getIsFree() ? "��" : "��");
				cout << endl;
				return;
			}
		}
		cout << "����������δ���ҵ�" << endl;
	}

	bool FindCtxFormName(std::string strName, VideoContent& ctx) {
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == strName) {
				ctx = *(m_vecContentList[i]);
				return true;
			}
		}
		return false;
	}

	void showContentListDetail() {
		cout << "�����б�" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			cout << "���ƣ�" << m_vecContentList[i]->getName();
			cout << "	ʱ����" << m_vecContentList[i]->getDuration() << "����";
			cout << "	���ࣺ" << m_vecContentList[i]->getCategory();
			cout << "	�Ƿ���ѣ�" << (m_vecContentList[i]->getIsFree() ? "��" : "��");
			cout << endl;
		}
	}

	std::vector<VideoContent*> GetContentList() {
		return m_vecContentList;
	}
private:
	std::vector<VideoContent*> m_vecContentList;
};

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
		while (true) {
			cin >> choice;
			if (choice > 0 && choice < 7) {
				return choice;
			}
			cout << "��Ч��ѡ��, ����������" << endl;
		}
	}

	static int ShowColunmManagerMenu() {
		Clear();
		cout << "* ��ӭ������Ŀ����ģ�顭" << endl;
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
		for (int i = 0; i < m_vecList.size(); i++)
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
			cout << "�û�����" << m_vecList[i].strUserName << " �����˸����ݣ�";
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
		for (int i = 0; i < users.size(); i++)
		{
			iCount = 0;
			cout << "���û���" << users[i]->getUsername() << " �������������ݣ�" << endl;
			for (int j = 0; j < m_vecList.size(); j++)
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
			if (iCount == 0) {
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


class Work {
public:

	Work() {

		m_columnManager.AddColumn(new Column("��Ӱ"));
		m_columnManager.AddColumn(new Column("���Ӿ�"));
		m_columnManager.AddColumn(new Column("����Ƶ"));

		/*
		// for test
		m_columnManager.AddColumn(new Column("ni"));
		m_userManager.addUser(new User("mrbai", "123"));
		m_ctxManager.AddContent(new	VideoContent("hello1", 1, "ni", 1));
		m_ctxManager.AddContent(new	VideoContent("hello2", 2, "ni", 0));
		// end test
		*/

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
	User* m_CurrentUser = nullptr;	// ��ǰ�û�
	UserManager		m_userManager;
	ContentManager	m_ctxManager;
	ColumnManager	m_columnManager;
	CAccess			m_access;
};


class VideoSystem {
public:
	VideoSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {
		// Ĭ�����һ������Ա�����������û��Ͳ���ʹ��admin�����ˡ�
		//m_work.addAdminInfo(adminUsername, adminPassword);
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

					string username, password;
					cout << "���������Ա�û�����";
					cin >> username;
					cout << "���������Ա���룺";
					cin >> password;

					//string username="admin", password="123456";
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

					string username, password;
					cout << "�������û�����";
					cin >> username;
					cout << "���������룺";
					cin >> password;

					//string username = "mrbai", password = "123";
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