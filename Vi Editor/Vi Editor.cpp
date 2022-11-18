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
	void insertString(int lineLocation, int rowLocation, const string insertionString);
	void deleteString(int lineLocation, int rowLocation, int deleteSize);
	void changeString(const string targetString, const string changeString);
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
	string lineContent;
	getline(*targetFile, txt);
	while (1) {
		if (txt[75] != ' ' || txt[75] != '\n') {
			for (int i = 74; i >= 0; i--) {
				if (txt[i] == ' ' || txt[i] == ' ') {

				}
			}
		}
	}
	/*
	string txt;
	string lineContent = "";
	char separator = ' ';
	int count = 0;
	while (getline(*targetFile, txt, separator)) {
		lineContent += txt;
		if (txt[txt.size() - 1] != '\n') {
			lineContent += " ";
		}
		if (count + txt.size() + 1 > 75) {
			this->content.push_back(lineContent);
			lineContent = "";
			lineSize += 1;
		}
		count += txt.size() + 1;
	}
	*/
}

void ViEditor::draw(string* cmdLine, string consoleMassage) {
	for (int i = 0; i < 20; i++) {
		cout << right << setw(2) << i+1;
		cout << "| ";
		if (i+header < content.size()) {
			cout << content.at(i+header);
		}
		cout << endl;
		
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
	this->header = content.size() - 19;
}

void ViEditor::previousPage() {

}

void ViEditor::insertString(int lineLocation, int rowLocation, const string insertionString) {

}

void ViEditor::deleteString(int lineLocation, int rowLocation, int deleteSize) {

}

void ViEditor::changeString(const string targetString, const string changeString) {

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
	istringstream iss(cmdLine);

	if (!parseLine.at(0).compare("n")) {
		if (cmdLine.size() != 1) {
			return "[Error] 잘못된 명령어입니다\n";
		}
		nextPage();
	}
	else if (!parseLine.at(0).compare("n")) {
		if (cmdLine.size() != 1) {
			return "[Error] 잘못된 명령어입니다\n";
		}
		previousPage();
	}
	else if (!parseLine.at(0).compare("p")) {

	}
	else if (!parseLine.at(0).compare("i")) {

	}
	else if (!parseLine.at(0).compare("d")) {

	}
	else if (!parseLine.at(0).compare("c")) {

	}
	else if (!parseLine.at(0).compare("s")) {

	}
	else if (!parseLine.at(0).compare("t")) {
		if (cmdLine.size() != 1) {
			return "[Error] 잘못된 명령어입니다\n";
		}
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