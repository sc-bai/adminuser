
#include "stdafx.h"
#include "user.h"
#include "content.h"

using namespace std;

// 视频管理系统类
class VideoManagementSystem {
private:
    Admin admin;
    
    vector<VideoContent*> contents;

public:
    VideoManagementSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {}

    

   

    

    void start() {
        cout << "欢迎您使用在线视频系统" << endl;
        cout << "1) 管理员" << endl;
        cout << "2) 普通用户" << endl;
        cout << "3) 退出系统" << endl;
        cout << "请选择登录用户类型[1-3]: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            adminMenu();
        } else if (choice == 2) {
            memberMenu();
        } else if (choice == 3) {
            cout << "系统已退出" << endl;
            return;
        } else {
            cout << "无效的选择" << endl;
            start();
        }
    }

    void adminMenu() {
        cout << "欢迎您" << admin.getUsername() << "，您的角色是管理员！具有如下功能权限：" << endl;
        cout << "1) 栏目管理" << endl;
        cout << "2) 内容管理" << endl;
        cout << "3) 用户管理" << endl;
        cout << "4) 用户访问记录管理" << endl;
        cout << "5) 统计" << endl;
        cout << "6) 退出" << endl;
        cout << "请输入命令[1-6]: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            columnManagement();
        } else if (choice == 2) {
            contentManagement();
        } else if (choice == 3) {
            userManagement();
        } else if (choice == 4) {
            accessRecordManagement();
        } else if (choice == 5) {
            statistics();
        } else if (choice == 6) {
            start();
        } else {
            cout << "无效的选择" << endl;
            adminMenu();
        }
    }

    void columnManagement() {
        cout << "栏目管理：" << endl;
        // 实现栏目管理的相关功能
    }

    void contentManagement() {
        cout << "内容管理：" << endl;
        // 实现内容管理的相关功能
    }

    void userManagement() {
        cout << "用户管理：" << endl;
        cout << "1) 增加用户" << endl;
        cout << "2) 用户列表" << endl;
        cout << "3) 删除用户" << endl;
        cout << "4) 返回上一级" << endl;
        cout << "请输入命令[1-4]: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "请输入用户名：";
            cin >> username;
            cout << "请输入密码：";
            cin >> password;
            addUser(username, password);
            userManagement();
        } else if (choice == 2) {
            showUserList();
            userManagement();
        } else if (choice == 3) {
            string username;
            cout << "请输入要删除的用户名：";
            cin >> username;
            deleteUser(username);
            userManagement();
        } else if (choice == 4) {
            adminMenu();
        } else {
            cout << "无效的选择" << endl;
            userManagement();
        }
    }

    void accessRecordManagement() {
        cout << "用户访问记录管理：" << endl;
        // 实现用户访问记录管理的相关功能
    }

    void statistics() {
        cout << "统计：" << endl;
        // 实现统计的相关功能
    }

    void memberMenu() {
        cout << "欢迎您普通用户！具有如下功能权限：" << endl;
        cout << "1) 内容列表" << endl;
        cout << "2) 查看内容详情" << endl;
        cout << "3) 访问内容" << endl;
        cout << "4) 修改密码" << endl;
        cout << "请输入命令[1-4]: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            showContentList();
            memberMenu();
        } else if (choice == 2) {
            // 实现查看内容详情的相关功能
        } else if (choice == 3) {
            // 实现访问内容的相关功能
        } else if (choice == 4) {
            string newPassword;
            cout << "请输入新密码：";
            cin >> newPassword;
            admin.setPassword(newPassword);
            memberMenu();
        } else {
            cout << "无效的选择" << endl;
            memberMenu();
        }
    }
};

int main() {
    VideoManagementSystem system("admin", "123456");
    system.start();

    return 0;
};
