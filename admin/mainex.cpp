
#include "stdafx.h"
#include "user.h"
#include "content.h"

using namespace std;

// ��Ƶ����ϵͳ��
class VideoManagementSystem {
private:
    Admin admin;
    
    vector<VideoContent*> contents;

public:
    VideoManagementSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {}

    

   

    

    void start() {
        cout << "��ӭ��ʹ��������Ƶϵͳ" << endl;
        cout << "1) ����Ա" << endl;
        cout << "2) ��ͨ�û�" << endl;
        cout << "3) �˳�ϵͳ" << endl;
        cout << "��ѡ���¼�û�����[1-3]: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            adminMenu();
        } else if (choice == 2) {
            memberMenu();
        } else if (choice == 3) {
            cout << "ϵͳ���˳�" << endl;
            return;
        } else {
            cout << "��Ч��ѡ��" << endl;
            start();
        }
    }

    void adminMenu() {
        cout << "��ӭ��" << admin.getUsername() << "�����Ľ�ɫ�ǹ���Ա���������¹���Ȩ�ޣ�" << endl;
        cout << "1) ��Ŀ����" << endl;
        cout << "2) ���ݹ���" << endl;
        cout << "3) �û�����" << endl;
        cout << "4) �û����ʼ�¼����" << endl;
        cout << "5) ͳ��" << endl;
        cout << "6) �˳�" << endl;
        cout << "����������[1-6]: ";

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
            cout << "��Ч��ѡ��" << endl;
            adminMenu();
        }
    }

    void columnManagement() {
        cout << "��Ŀ����" << endl;
        // ʵ����Ŀ�������ع���
    }

    void contentManagement() {
        cout << "���ݹ���" << endl;
        // ʵ�����ݹ������ع���
    }

    void userManagement() {
        cout << "�û�����" << endl;
        cout << "1) �����û�" << endl;
        cout << "2) �û��б�" << endl;
        cout << "3) ɾ���û�" << endl;
        cout << "4) ������һ��" << endl;
        cout << "����������[1-4]: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "�������û�����";
            cin >> username;
            cout << "���������룺";
            cin >> password;
            addUser(username, password);
            userManagement();
        } else if (choice == 2) {
            showUserList();
            userManagement();
        } else if (choice == 3) {
            string username;
            cout << "������Ҫɾ�����û�����";
            cin >> username;
            deleteUser(username);
            userManagement();
        } else if (choice == 4) {
            adminMenu();
        } else {
            cout << "��Ч��ѡ��" << endl;
            userManagement();
        }
    }

    void accessRecordManagement() {
        cout << "�û����ʼ�¼����" << endl;
        // ʵ���û����ʼ�¼�������ع���
    }

    void statistics() {
        cout << "ͳ�ƣ�" << endl;
        // ʵ��ͳ�Ƶ���ع���
    }

    void memberMenu() {
        cout << "��ӭ����ͨ�û����������¹���Ȩ�ޣ�" << endl;
        cout << "1) �����б�" << endl;
        cout << "2) �鿴��������" << endl;
        cout << "3) ��������" << endl;
        cout << "4) �޸�����" << endl;
        cout << "����������[1-4]: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            showContentList();
            memberMenu();
        } else if (choice == 2) {
            // ʵ�ֲ鿴�����������ع���
        } else if (choice == 3) {
            // ʵ�ַ������ݵ���ع���
        } else if (choice == 4) {
            string newPassword;
            cout << "�����������룺";
            cin >> newPassword;
            admin.setPassword(newPassword);
            memberMenu();
        } else {
            cout << "��Ч��ѡ��" << endl;
            memberMenu();
        }
    }
};

int main() {
    VideoManagementSystem system("admin", "123456");
    system.start();

    return 0;
};
