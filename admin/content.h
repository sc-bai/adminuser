#pragma once

#include <string>

using namespace std;

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
		for (int i=0;i<m_vecContentList.size(); i++){
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
				cout << "名称：" << m_vecContentList[i]->getName() ;
				cout << "	时长：" << m_vecContentList[i]->getDuration() << "分钟";
				cout << "	分类：" << m_vecContentList[i]->getCategory() ;
				cout << "	是否免费：" << (m_vecContentList[i]->getIsFree() ? "是" : "否") ;
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
			cout << "名称：" << m_vecContentList[i]->getName() ;
			cout << "	时长：" << m_vecContentList[i]->getDuration() << "分钟" ;
			cout << "	分类：" << m_vecContentList[i]->getCategory() ;
			cout << "	是否免费：" << (m_vecContentList[i]->getIsFree() ? "是" : "否") ;
			cout << endl;
		}
	}

	std::vector<VideoContent*> GetContentList() {
		return m_vecContentList;
	}
private:
	std::vector<VideoContent*> m_vecContentList;
};