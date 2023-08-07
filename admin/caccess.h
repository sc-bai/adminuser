#pragma once
#include "stdafx.h"
#include "content.h"

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
		for (int i=0; i<m_vecList.size();i++)
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
			cout << "用户名：" << m_vecList[i].strUserName<<" 访问了该内容：";
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
		for (int i  =0;i< users.size();i++)
		{
			iCount = 0;
			cout << "该用户：" << users[i]->getUsername() << " 访问了以下内容："<<endl;
			for (int j=0;j< m_vecList.size();j++)
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
			if(iCount == 0){
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
