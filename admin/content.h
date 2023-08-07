#pragma once

#include <string>

using namespace std;

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
		for (int i=0;i<m_vecContentList.size(); i++){
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
				cout << "���ƣ�" << m_vecContentList[i]->getName() ;
				cout << "	ʱ����" << m_vecContentList[i]->getDuration() << "����";
				cout << "	���ࣺ" << m_vecContentList[i]->getCategory() ;
				cout << "	�Ƿ���ѣ�" << (m_vecContentList[i]->getIsFree() ? "��" : "��") ;
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
			cout << "���ƣ�" << m_vecContentList[i]->getName() ;
			cout << "	ʱ����" << m_vecContentList[i]->getDuration() << "����" ;
			cout << "	���ࣺ" << m_vecContentList[i]->getCategory() ;
			cout << "	�Ƿ���ѣ�" << (m_vecContentList[i]->getIsFree() ? "��" : "��") ;
			cout << endl;
		}
	}

	std::vector<VideoContent*> GetContentList() {
		return m_vecContentList;
	}
private:
	std::vector<VideoContent*> m_vecContentList;
};