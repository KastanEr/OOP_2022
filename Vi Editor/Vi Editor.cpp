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
	string contentText;
	vector<string> content;
	int header;
	string consoleMassage;

	ViEditor(fstream* targetFile) {
		this->targetFile = targetFile;
		this->header = 0;
	}
public:
	void run();
	void readContent();
	void refreshContent();
	void draw(string* cmdLine);
	string nextPage();
	string previousPage();
	string insertString(int lineLocation, int index, const string insertionString);
	string deleteString(int lineLocation, int index, int deleteSize);
	string changeString(const string targetString, const string newString);
	string searchString(const string tarrgetString);
	string saveAndExit();
	string parseCmd(string cmdLine);
	static ViEditor* getInstance(fstream* targetFile);
};

ViEditor* ViEditor::instance = nullptr;

void ViEditor::run() {
	targetFile->open("test.txt", ios::in | ios::out | ios::app);
	string cmdLine;
	if (!targetFile->is_open()) {
		cout << "[Error] 파일을 여는데 실패하였습니다\n";
		exit(1);
	}
	readContent();
	while (1) {
		cmdLine = "";
		draw(&cmdLine);
		consoleMassage = parseCmd(cmdLine);
	}
}

void ViEditor::readContent() {
	string txt;
	vector<string> words;
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

void ViEditor::refreshContent() {
	contentText = "";
	for (int i = 0; i < content.size(); i++) {
		contentText += content.at(i);
	}
	vector<string> words;
	int begin = 0;
	for (int i = 0; i < contentText.size(); i++) {
		if (contentText[i] == ' ' || contentText[i] == '\n') {
			words.push_back(contentText.substr(begin, i - begin + 1));
			begin = i + 1;
		}
		if (contentText[i] == '\0') {
			words.push_back(contentText.substr(begin, i - begin + 1));
		}
	}
	int countSize = 0;
	string lineContent;
	content.clear();
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

void ViEditor::draw(string* cmdLine) {
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
	cout << "(콘솔메시지) " << consoleMassage << endl;
	cout << "-------------------------------------------------------------------------------\n";
	cout << "입력: ";
	cin >> *cmdLine;
	cout << "-------------------------------------------------------------------------------\n";
}

string ViEditor::nextPage() {
	if (content.size() == header + 20 || content.size() <= 20) {
		return "This is last page!";
	}
	else if (content.size() - (header + 20) >= 20) {
		header += 20;
		return "";
	}
	else if (content.size() - (header + 20) < 20) {
		header = content.size() - 20;
		return "";
	}
	return "Error!";
}

string ViEditor::previousPage() {
	if (header == 0) {
		return "This is first page!";
	}
	else if (header - 20 > 0) {
		header -= 20;
		return "";
	}
	else if (header - 20 < 0) {
		header = 0;
		return "";
	}
	return "Error!";
}

string ViEditor::insertString(int lineLocation, int index, const string insertionString) {
	if (lineLocation > 0 && lineLocation < 21 && index >= 0 && index < content.at(lineLocation).size()) {
		content.at(lineLocation - 1).insert(index, insertionString);
		refreshContent();
		return "";
	}
	else {
		return "Invalid command!";
	}
}

string ViEditor::deleteString(int lineLocation, int index, int deleteSize) {
	if (lineLocation > 0 && lineLocation < 21 && index >= 0 && index < content.at(lineLocation).size() && index + deleteSize <= content.at(lineLocation).size()) {
		content.at(lineLocation - 1).erase(index, deleteSize);
		refreshContent();
		return "";
	}
	return "Invalid command!";
}

string ViEditor::changeString(const string targetString, const string newString) {
	for(int i = 0; i < content.size(); i++){
		while (content.at(i).find(targetString) != string::npos) {

		}
	}
	refreshContent();
	return "";
}

string ViEditor::searchString(const string tarrgetString) {
	return "";
}

string ViEditor::saveAndExit() {
	targetFile->close();
	exit(1);
}

string ViEditor::parseCmd(string cmdLine) {
	cmdLine.erase(remove(cmdLine.begin(), cmdLine.end(), ' '), cmdLine.end());
	cmdLine.erase(remove(cmdLine.begin(), cmdLine.end(), '\n'), cmdLine.end());
	vector<string> parseLine;
	int begin = 0;
	for (int i = 0; i < cmdLine.size(); i++) {
		if (cmdLine[i] == '(' || cmdLine[i] == ',' || cmdLine[i] == ')') {
			parseLine.push_back(cmdLine.substr(begin, i - begin));
			begin = i + 1;
		}
		if (parseLine.size() == 0 && i == cmdLine.size()-1) {
			parseLine.push_back(cmdLine);
		}
	}
	if (cmdLine.size() == 0) {
		return "Invalid command!";
	}
	if (parseLine.at(0).size() != 1) {
		return "Invalid command!";
	}

	// 명령어 실행
	if (!parseLine.at(0).compare("n")) {
		return nextPage();
	}
	else if (!parseLine.at(0).compare("p")) {
		return previousPage();
	}
	else if (!parseLine.at(0).compare("i")) {
		int lineLocation, index;
		string insertionString;
		if (parseLine.size() == 4) {
			insertionString = parseLine.at(3);
			try {
				lineLocation = stoi(parseLine.at(1));
				index = stoi(parseLine.at(2));
			}
			catch (exception& e) {
				 return "Invalid command!";
			}
			return insertString(lineLocation, index, insertionString);
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("d")) {
		int lineLocation, index, deletSize;
		if (parseLine.size() == 4) {
			try {
				lineLocation = stoi(parseLine.at(1));
				index = stoi(parseLine.at(2));
				deletSize = stoi(parseLine.at(3));
			}
			catch (exception& e) {
				return "Invalid command!";
			}
			return deleteString(lineLocation, index, deletSize);
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("c")) {
		if (parseLine.size() == 3) {
			return changeString(parseLine.at(1), parseLine.at(2));
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("s")) {
		if (parseLine.size() == 2) {
			return searchString(parseLine.at(1));
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("t")) {
		saveAndExit();
	}
	else {
		return "Invalid command!";
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