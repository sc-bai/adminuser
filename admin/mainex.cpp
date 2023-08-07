#include <iostream>
#include <vector>
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
			cout << "添加栏目：" << endl;
			for (auto& item : m_vecList)
			{
				if (item->GetColumnName() == c->GetColumnName()) {
					delete c;
					c = nullptr;
					cout << "该栏目已存在" << endl;
					return;
				}
			}
			m_vecList.push_back(c);
			cout << "添加栏目成功" << endl;
		}
	}

	void DeleteColumn(std::string strName) {

		cout << "删除栏目：" << strName << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			if (m_vecList[i]->GetColumnName() == strName) {

				m_vecList.erase(m_vecList.begin() + i);
				cout << "删除栏目成功" << endl;
				return;
			}
		}
		cout << "未查询到该栏目：" << strName << endl;
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
		cout << "栏目列表：" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout << "栏目名称：" << m_vecList[i]->GetColumnName() << endl;
		}
	}
private:
	std::vector<Column*> m_vecList;
};

// 视频内容基类
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
// 电影类
class Movie : public VideoContent {
public:
	Movie(string name, int duration, string category, bool isFree) : VideoContent(name, duration, category, isFree) {}
};

// 电视剧类
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
				cout << "该内容已存在" << endl;
				return;
			}
		}
		m_vecContentList.push_back(new VideoContent(name, duration, category, isFree));
		cout << "内容已添加" << endl;
	}

	bool AddContent(VideoContent* ctx) {
		if (ctx != nullptr) {
			for (int i = 0; i < m_vecContentList.size(); i++) {
				if (m_vecContentList[i]->getName() == ctx->getName()) {
					cout << "该内容已存在" << endl;
					return false;
				}
			}
			m_vecContentList.push_back(ctx);
			cout << "内容已添加" << endl;
			return true;
		}
	}
	bool DeleteContent(string name) {
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == name) {
				m_vecContentList.erase(m_vecContentList.begin() + i);
				cout << "内容已删除" << endl;
				return true;
			}
		}
		cout << "未查找到该内容" << endl;
		return false;
	}

	void showContentList() {
		cout << "内容列表：" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			cout << "名称：" << m_vecContentList[i]->getName() << endl;
			cout << endl;
		}
	}

	void ShowContentItemDetail(std::string strname) {
		cout << "内容详情：" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			if (m_vecContentList[i]->getName() == strname) {
				cout << "名称：" << m_vecContentList[i]->getName();
				cout << "	时长：" << m_vecContentList[i]->getDuration() << "分钟";
				cout << "	分类：" << m_vecContentList[i]->getCategory();
				cout << "	是否免费：" << (m_vecContentList[i]->getIsFree() ? "是" : "否");
				cout << endl;
				return;
			}
		}
		cout << "该内容详情未查找到" << endl;
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
		cout << "内容列表：" << endl;
		for (int i = 0; i < m_vecContentList.size(); i++) {
			cout << "名称：" << m_vecContentList[i]->getName();
			cout << "	时长：" << m_vecContentList[i]->getDuration() << "分钟";
			cout << "	分类：" << m_vecContentList[i]->getCategory();
			cout << "	是否免费：" << (m_vecContentList[i]->getIsFree() ? "是" : "否");
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
		while (true) {
			cin >> choice;
			if (choice > 0 && choice < 7) {
				return choice;
			}
			cout << "无效的选择, 请重新输入" << endl;
		}
	}

	static int ShowColunmManagerMenu() {
		Clear();
		cout << "* 欢迎进入栏目管理模块…" << endl;
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

	// 展示当前用户 访问了哪些内容
	void ShowUserAccHistory(std::string strUserName) {
		int iCount = 0;
		cout << "当前用户访问了以下内容：" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			if (m_vecList[i].strUserName == strUserName) {
				iCount++;
				cout << "名称：" << m_vecList[i].ctx.getName();
				cout << "	时长：" << m_vecList[i].ctx.getDuration() << "分钟";
				cout << "	分类：" << m_vecList[i].ctx.getCategory();
				cout << "	是否免费：" << (m_vecList[i].ctx.getIsFree() ? "是" : "否");
				cout << endl;
			}
		}

		if (iCount == 0) {
			cout << "尚未访问内容：" << endl;
		}
	}

	void ShowAllHistory()
	{
		cout << "内容访问记录：" << endl;
		for (int i = 0; i < m_vecList.size(); i++)
		{
			cout << "用户名：" << m_vecList[i].strUserName << " 访问了该内容：";
			cout << "名称：" << m_vecList[i].ctx.getName();
			cout << "	时长：" << m_vecList[i].ctx.getDuration() << "分钟";
			cout << "	分类：" << m_vecList[i].ctx.getCategory();
			cout << "	是否免费：" << (m_vecList[i].ctx.getIsFree() ? "是" : "否");
			cout << endl;
		}
		if (m_vecList.size() == 0) {
			cout << "无" << endl;
		}
	}

	// 统计所有访问情况

	void Statistics() {
		cout << "统计：" << endl;

		int iCount = 0;
		// 用户 访问了哪些内容 
		auto users = m_pUserManager->GetUserList();
		for (int i = 0; i < users.size(); i++)
		{
			iCount = 0;
			cout << "该用户：" << users[i]->getUsername() << " 访问了以下内容：" << endl;
			for (int j = 0; j < m_vecList.size(); j++)
			{
				if (users[i]->getUsername() == m_vecList[j].strUserName) {
					cout << "	名称：" << m_vecList[j].ctx.getName();
					cout << "	时长：" << m_vecList[j].ctx.getDuration() << "分钟";
					cout << "	分类：" << m_vecList[j].ctx.getCategory();
					cout << "	是否免费：" << (m_vecList[j].ctx.getIsFree() ? "是" : "否");
					cout << endl;
					iCount++;
				}
			}
			if (iCount == 0) {
				cout << "该用户没有访问内容：" << endl;
			}
			cout << endl;
			cout << endl;
		}

		// 内容被访问了多少次
		iCount = 0;
		auto ctxs = m_ctxManager->GetContentList();
		for (int i = 0; i < ctxs.size(); i++)
		{
			iCount = 0;
			cout << "该内容：" << ctxs[i]->getName() << " 被访问了：";
			for (int j = 0; j < m_vecList.size(); j++)
			{
				if (ctxs[i]->getName() == m_vecList[j].ctx.getName()) {
					iCount++;
				}
			}
			cout << iCount << "次" << endl;
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

		m_columnManager.AddColumn(new Column("电影"));
		m_columnManager.AddColumn(new Column("电视剧"));
		m_columnManager.AddColumn(new Column("短视频"));

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
	User* m_CurrentUser = nullptr;	// 当前用户
	UserManager		m_userManager;
	ContentManager	m_ctxManager;
	ColumnManager	m_columnManager;
	CAccess			m_access;
};


class VideoSystem {
public:
	VideoSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {
		// 默认添加一个管理员，这样其他用户就不能使用admin名称了。
		//m_work.addAdminInfo(adminUsername, adminPassword);
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

					string username, password;
					cout << "请输入管理员用户名：";
					cin >> username;
					cout << "请输入管理员密码：";
					cin >> password;

					//string username="admin", password="123456";
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

					string username, password;
					cout << "请输入用户名：";
					cin >> username;
					cout << "请输入密码：";
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