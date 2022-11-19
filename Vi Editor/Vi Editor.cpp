#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class ViEditor {
	static ViEditor* instance;
	fstream* targetFile;
	vector<string> words;
	vector<string> content;
	int header;

	ViEditor(fstream* targetFile) {
		this->targetFile = targetFile;
		this->header = 0;
	}
public:
	void run();
	void readContent();
	void draw(string* cmdLine, string consoleMassage);
	void nextPage();
	void previousPage();
	void insertString(int lineLocation, int index, const string insertionString);
	void deleteString(int lineLocation, int index, int deleteSize);
	void changeString(const string targetString, const string newString);
	void searchString(const string tarrgetString);
	void saveAndExit();
	string parseCmd(string cmdLine);
	static ViEditor* getInstance(fstream* targetFile);
};

ViEditor* ViEditor::instance = nullptr;

void ViEditor::run() {
	targetFile->open("test.txt", ios::in | ios::out | ios::app);
	string cmdLine;
	string consoleMassage;
	if (!targetFile->is_open()) {
		cout << "[Error] 파일을 여는데 실패하였습니다\n";
		exit(1);
	}
	while (1) {
		cmdLine = "";
		readContent();
		draw(&cmdLine, consoleMassage);
		consoleMassage = parseCmd(cmdLine);
	}
}

void ViEditor::readContent() {
	string txt;
	targetFile->seekg(0, std::ios::end);
	int size = targetFile->tellg();
	txt.resize(size);
	targetFile->seekg(0, std::ios::beg);
	targetFile->read(&txt[0], size);
	int begin = 0;
	for (int i = 0; i < txt.size(); i++) {
		if (txt[i] == ' ' || txt[i] == '\n') {
			words.push_back(txt.substr(begin, i - begin + 1));
			
			begin = i+1;
		}
		if (txt[i] == '\0') {
			words.push_back(txt.substr(begin, i - begin + 1));
		}
		if (i == txt.size()-1) {
			words.push_back(txt.substr(begin, i - begin + 1) + '\0');
		}
	}
	int countSize = 0;
	string lineContent;
	for (int i = 0; i < words.size(); i++) {
		if (countSize + words.at(i).size() > 76) {
			content.push_back(lineContent);
			countSize = 0;
			lineContent = "";
		}
		if (words.at(i)[words.at(i).size() - 1] == '\n') {
			lineContent += words.at(i);
			content.push_back(lineContent);
			countSize = 0;
			lineContent = "";
			continue;
		}
		if (words.at(i)[words.at(i).size() - 1] == '\0') {
			lineContent += words.at(i);
			content.push_back(lineContent);
			break;
		}
		countSize += words.at(i).size();
		lineContent += words.at(i);
	}
}

void ViEditor::draw(string* cmdLine, string consoleMassage) {
	for (int i = 0; i < 20; i++) {
		cout << right << setw(2) << i+1;
		cout << "| ";
		if (i+header < content.size()) {
			cout << content.at(i+header);
			if (content.at(i + header)[content.at(i + header).size() - 1] != '\n') {
				cout << endl;
			}
		}
		if (i + header >= content.size()) {
			cout << endl;
		}
	}
	cout << "-------------------------------------------------------------------------------\n";
	cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "(콘솔메시지)" << consoleMassage << endl;
	cout << "-------------------------------------------------------------------------------\n";
	cout << "입력:";
	cin >> *cmdLine;
	cout << "-------------------------------------------------------------------------------\n";
}

void ViEditor::nextPage() {
	if (content.size() - header > 20) {
		header += 20;
		if (content.size() - header < 20) {

		}
	}
}

void ViEditor::previousPage() {

}

void ViEditor::insertString(int lineLocation, int index, const string insertionString) {

}

void ViEditor::deleteString(int lineLocation, int index, int deleteSize) {

}

void ViEditor::changeString(const string targetString, const string newString) {

}

void ViEditor::searchString(const string tarrgetString) {

}

void ViEditor::saveAndExit() {
	targetFile->close();
	exit(1);
}

string ViEditor::parseCmd(string cmdLine) {
	cmdLine.erase(remove(cmdLine.begin(), cmdLine.end(), ' '), cmdLine.end());
	vector<string> parseLine;
	int begin = 0;
	for (int i = 0; i < cmdLine.size(); i++) {
		if (cmdLine[i] == '(' || cmdLine[i] == ',' || cmdLine[i] == ')') {
			parseLine.push_back(cmdLine.substr(begin, i - begin));
			begin = i + 1;
		}
	}

	if (parseLine.at(0).size() != 1) {
		return "잘못된 명령어입니다";
	}

	if (!parseLine.at(0).compare("n")) {
		nextPage();
	}
	else if (!parseLine.at(0).compare("p")) {
		previousPage();
	}
	else if (!parseLine.at(0).compare("i")) {
		if(parseLine.size())
		int lineLocation, index;
		string insertionString;

	}
	else if (!parseLine.at(0).compare("d")) {
		int lineLocation, index, deletSize;
	}
	else if (!parseLine.at(0).compare("c")) {
		string targetString, newString;
	}
	else if (!parseLine.at(0).compare("s")) {
		string targetString;
	}
	else if (!parseLine.at(0).compare("t")) {
		saveAndExit();
	}
}

ViEditor* ViEditor::getInstance(fstream* targetFile) {
	if (instance == nullptr) {
		instance = new ViEditor(targetFile);
		return instance;
	}
	else {
		return instance;
	}
}

int main() {
	fstream targetFile;
	ViEditor* viEditor = ViEditor::getInstance(&targetFile);
	viEditor->run();
}