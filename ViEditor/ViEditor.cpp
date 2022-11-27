#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <memory>

using namespace std;

class ViEditor {
	static shared_ptr<ViEditor> instance;
	fstream targetFile;
	string content;
	vector<string> lineContent;
	int header;
	bool recoveryFlag;

	ViEditor();
public:
	int getHeader() const;
	vector<string> getLineContent() const;
	void openFile();
	void readContent();
	void refreshContent();
	void refreshLineContent();
	void saveAndExit();
	string nextPage();
	string previousPage();
	string insertString(int lineLocation, int index, const string insertionString);
	string deleteString(int lineLocation, int index, int deleteSize);
	string changeString(const string targetString, const string newString);
	string searchString(const string targetString);
	static shared_ptr<ViEditor> getInstance();
};

class AppView {
public:
	string viewContentAndInputCmd(vector<string> lineContent, string consoleMessage, int header);
};

class AppController {
	weak_ptr<ViEditor> viEditor;
	AppView appView;
public:
	AppController(weak_ptr<ViEditor> viEditor, AppView appView);
	void run();
	string parseCmd(string cmdLine);

};

shared_ptr<ViEditor> ViEditor::instance = nullptr;

ViEditor::ViEditor() {
	this->header = 0;
	this->recoveryFlag = false;
}

int ViEditor::getHeader() const {
	return this->header;
}

vector<string> ViEditor::getLineContent() const {
	return this->lineContent;
}

void ViEditor::openFile() {
	targetFile.open("test.txt", ios::in);
	if (!targetFile.is_open()) {
		cout << "Failed to open file!\n";
		exit(0);
	}
}

void ViEditor::readContent() {
	vector<string> words;
	targetFile.seekg(0, std::ios::end);
	int size = targetFile.tellg();
	content.resize(size);
	targetFile.seekg(0, std::ios::beg);
	targetFile.read(&content[0], size);
	targetFile.close();
	int begin = 0;
	for (int i = 0; i < content.size(); i++) {
		if (content[i] == ' ' || content[i] == '\n') {
			words.push_back(content.substr(begin, i - begin + 1));

			begin = i + 1;
		}
		if (content[i] == '\0') {
			words.push_back(content.substr(begin, i - begin + 1));
		}
		if (i == content.size() - 1) {
			words.push_back(content.substr(begin, i - begin + 1) + '\0');
		}
	}

	int countSize = 0;
	string readLine;
	for (int i = 0; i < words.size(); i++) {
		if (countSize + words.at(i).size() > 76) {
			lineContent.push_back(readLine);
			countSize = 0;
			readLine = "";
		}
		if (words.at(i)[words.at(i).size() - 1] == '\n') {
			readLine += words.at(i);
			lineContent.push_back(readLine);
			countSize = 0;
			readLine = "";
			continue;
		}
		if (words.at(i)[words.at(i).size() - 1] == '\0') {
			readLine += words.at(i);
			lineContent.push_back(readLine);
			break;
		}
		countSize += words.at(i).size();
		readLine += words.at(i);
	}
}

void ViEditor::refreshContent() {
	content = "";
	for (int i = 0; i < lineContent.size(); i++) {
		content += lineContent.at(i);
	}
}

void ViEditor::refreshLineContent() {
	vector<string> words;
	int begin = 0;
	for (int i = 0; i < content.size(); i++) {
		if (content[i] == ' ' || content[i] == '\n') {
			words.push_back(content.substr(begin, i - begin + 1));
			begin = i + 1;
		}
		if (content[i] == '\0') {
			words.push_back(content.substr(begin, i - begin + 1));
		}
	}
	int countSize = 0;
	string readline;
	lineContent.clear();
	for (int i = 0; i < words.size(); i++) {
		if (countSize + words.at(i).size() > 76) {
			lineContent.push_back(readline);
			countSize = 0;
			readline = "";
		}
		if (words.at(i)[words.at(i).size() - 1] == '\n') {
			readline += words.at(i);
			lineContent.push_back(readline);
			countSize = 0;
			readline = "";
			continue;
		}
		if (words.at(i)[words.at(i).size() - 1] == '\0') {
			readline += words.at(i);
			lineContent.push_back(readline);
			break;
		}
		countSize += words.at(i).size();
		readline += words.at(i);
	}
}

string ViEditor::nextPage() {
	if (recoveryFlag) {
		refreshLineContent();
		recoveryFlag = false;
	}
	if (lineContent.size() == header + 20 || lineContent.size() <= 20) {
		return "This is last page!";
	}
	else if (header + 40 < lineContent.size()) {
		header += 20;
		return "";
	}
	else if (header + 40 >= lineContent.size()) {
		header = lineContent.size() - 20;
		return "";
	}
	return "Error!";
}

string ViEditor::previousPage() {
	if (recoveryFlag) {
		refreshLineContent();
		recoveryFlag = false;
	}
	if (header == 0) {
		return "This is first page!";
	}
	else if (header - 20 > 0) {
		header -= 20;
		return "";
	}
	else if (header - 20 <= 0) {
		header = 0;
		return "";
	}
	return "Error!";
}

string ViEditor::insertString(int lineLocation, int index, const string insertionString) {
	if (lineLocation > 0 && lineLocation < 21 && lineLocation <= lineContent.size() && index >= 0 && index < lineContent.at(header + lineLocation - 1).size()) {
		lineContent.at(header + lineLocation - 1).insert(index, insertionString);
		refreshContent();
		refreshLineContent();
		recoveryFlag = false;
		return "";
	}
	else {
		return "Invalid command! : Please enter a valid location";
	}
}

string ViEditor::deleteString(int lineLocation, int index, int deleteSize) {
	if (lineLocation > 0 && lineLocation < 21 && lineLocation <= content.size() && index >= 0 && index < lineContent.at(header + lineLocation - 1).size() && index + deleteSize <= lineContent.at(header + lineLocation - 1).size()) {
		lineContent.at(header + lineLocation - 1).erase(index, deleteSize);
		refreshContent();
		refreshLineContent();
		recoveryFlag = false;
		return "";
	}
	return "Invalid command! : Please enter a valid location";
}

string ViEditor::changeString(const string targetString, const string newString) {
	int count = 0;
	int begin = 0;
	while ((begin = content.find(targetString)) != string::npos) {
		content.replace(begin, targetString.size(), newString);
		count++;
	}
	if (count == 0) {
		return "No matching string found!";
	}
	else {
		refreshLineContent();
		recoveryFlag = false;
		header = 0;
		return "";
	}
}
/*
string ViEditor::searchString(const string targetString) {
	int index = 0;
	for (int i = 0; i < lineContent.size(); i++) {
		index = lineContent.at(i).find(targetString);
		if (index != string::npos) {
			if (index == 0) {
				header = i;
			}
			else {
				string recoveryString = lineContent.at(i);
				recoveryFlag = true;
				lineContent.at(i) = recoveryString.substr(0, index);
				string text = "";
				text += recoveryString.substr(index, recoveryString.size());
				for (int j = i+1; j < lineContent.size(); j++) {
					text += lineContent.at(j);
				}
				while (lineContent.size() > i + 1) {
					lineContent.pop_back();
				}
				vector<string> words;
				int begin = 0;
				for (int j = 0; j < text.size(); j++) {
					if (text[j] == ' ' || text[j]== '\n') {
						words.push_back(text.substr(begin, j - begin + 1));
						begin = j + 1;
					}
					if (text[j] == '\0') {
						words.push_back(text.substr(begin, j - begin + 1));
					}
				}
				int countSize = 0;
				string readline;
				for (int j = 0; j < words.size(); j++) {
					if (countSize + words.at(j).size() > 76) {
						lineContent.push_back(readline);
						countSize = 0;
						readline = "";
					}
					if (words.at(j)[words.at(j).size() - 1] == '\n') {
						readline += words.at(j);
						lineContent.push_back(readline);
						countSize = 0;
						readline = "";
						continue;
					}
					if (words.at(j)[words.at(j).size() - 1] == '\0') {
						readline += words.at(j);
						lineContent.push_back(readline);
						break;
					}
					countSize += words.at(j).size();
					readline += words.at(j);
				}
				header = i + 1;
			}
			return "";
		}
	}
	if (index == string::npos) {
		return "No matching string found!";
	}
	return "Error!";
}*/

string ViEditor::searchString(const string targetString) {
	int index = content.find(targetString);
	if (index != string::npos) {
		int lineIndex = 0;
		while (lineContent.at(lineIndex).size() < index && lineIndex < lineContent.size()) {
			index -= lineContent.at(lineIndex).size();
			lineIndex++;
		}
		if (index == 0) {
			header = lineIndex;
		}
		else {
			string recoveryString = lineContent.at(lineIndex);
			recoveryFlag = true;
			lineContent.at(lineIndex) = recoveryString.substr(0, index);
			string text = "";
			text += recoveryString.substr(index, recoveryString.size());
			for (int j = lineIndex + 1; j < lineContent.size(); j++) {
				text += lineContent.at(j);
			}
			while (lineContent.size() > lineIndex + 1) {
				lineContent.pop_back();
			}
			vector<string> words;
			int begin = 0;
			for (int j = 0; j < text.size(); j++) {
				if (text[j] == ' ' || text[j] == '\n') {
					words.push_back(text.substr(begin, j - begin + 1));
					begin = j + 1;
				}
				if (text[j] == '\0') {
					words.push_back(text.substr(begin, j - begin + 1));
				}
			}
			int countSize = 0;
			string readline;
			for (int j = 0; j < words.size(); j++) {
				if (countSize + words.at(j).size() > 76) {
					lineContent.push_back(readline);
					countSize = 0;
					readline = "";
				}
				if (words.at(j)[words.at(j).size() - 1] == '\n') {
					readline += words.at(j);
					lineContent.push_back(readline);
					countSize = 0;
					readline = "";
					continue;
				}
				if (words.at(j)[words.at(j).size() - 1] == '\0') {
					readline += words.at(j);
					lineContent.push_back(readline);
					break;
				}
				countSize += words.at(j).size();
				readline += words.at(j);
			}
			header = lineIndex + 1;
		}
		return "";
	}
	else {
		return "No matching string found!";
	}
}

void ViEditor::saveAndExit() {
	refreshContent();
	targetFile.open("test.txt", ios::out);
	if (targetFile.is_open()) {
		targetFile << content;
	}
	targetFile.close();
	exit(0);
}

shared_ptr<ViEditor> ViEditor::getInstance() {
	if (instance == nullptr) {
		instance = shared_ptr<ViEditor>(new ViEditor());
	}
	return instance;
}

string AppView::viewContentAndInputCmd(vector<string> lineContent, string consoleMessage, int header) {
	string cmdLine;
	for (int i = 0; i < 20; i++) {
		cout << right << setw(2) << i + 1;
		cout << "| ";
		if (i + header < lineContent.size()) {
			cout << lineContent.at(i + header);
			if (lineContent.at(i + header)[lineContent.at(i + header).size() - 1] != '\n') {
				cout << endl;
			}
		}
		if (i + header >= lineContent.size()) {
			cout << endl;
		}
	}
	cout << "-------------------------------------------------------------------------------\n";
	cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "(콘솔메시지) " << consoleMessage << endl;
	cout << "-------------------------------------------------------------------------------\n";
	cout << "입력: ";
	getline(cin, cmdLine);
	cout << "-------------------------------------------------------------------------------\n";
	if (cmdLine.size() == 0) {
		return " ";
	}
	else {
		return cmdLine;
	}
}

AppController::AppController(weak_ptr<ViEditor> viEditor, AppView appView) {
	this->viEditor = viEditor;
	this->appView = appView;
}

void AppController::run() {
	viEditor.lock()->openFile();
	viEditor.lock()->readContent();
	string cmdLine;
	string consoleMessage;
	while (1) {
		cmdLine = "";
		cmdLine = appView.viewContentAndInputCmd(viEditor.lock()->getLineContent(), consoleMessage, viEditor.lock()->getHeader());
		consoleMessage = parseCmd(cmdLine);
	}
}

string AppController::parseCmd(string cmdLine) {
	vector<string> parseLine;
	int begin = 0;
	for (int i = 0; i < cmdLine.size(); i++) {
		if (cmdLine[i] == '(' || cmdLine[i] == ',' || cmdLine[i] == ')') {
			parseLine.push_back(cmdLine.substr(begin, i - begin));
			begin = i + 1;
		}
		if (parseLine.size() == 0 && i == cmdLine.size() - 1) {
			parseLine.push_back(cmdLine);
		}
	}
	parseLine.at(0).erase(remove(parseLine.at(0).begin(), parseLine.at(0).end(), ' '), parseLine.at(0).end());
	if (cmdLine.size() == 0) {
		return "Invalid command!";
	}
	if (parseLine.at(0).size() != 1) {
		return "Invalid command! : please enter the command in the list";
	}
	// 명령어 실행
	if (!parseLine.at(0).compare("n")) {
		return viEditor.lock()->nextPage();
	}
	else if (!parseLine.at(0).compare("p")) {
		return viEditor.lock()->previousPage();
	}
	else if (!parseLine.at(0).compare("i")) {
		int lineLocation, index;
		string insertionString;
		if (parseLine.size() == 4) {
			insertionString = parseLine.at(3);
			parseLine.at(1).erase(remove(parseLine.at(1).begin(), parseLine.at(1).end(), ' '), parseLine.at(1).end());
			parseLine.at(2).erase(remove(parseLine.at(2).begin(), parseLine.at(2).end(), ' '), parseLine.at(2).end());
			try {
				lineLocation = stoi(parseLine.at(1));
				index = stoi(parseLine.at(2));
			}
			catch (exception& e) {
				return "Invalid command! : You entered a letter in the number part";
			}
			return viEditor.lock()->insertString(lineLocation, index, insertionString);
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("d")) {
		int lineLocation, index, deletSize;
		if (parseLine.size() == 4) {
			parseLine.at(1).erase(remove(parseLine.at(1).begin(), parseLine.at(1).end(), ' '), parseLine.at(1).end());
			parseLine.at(2).erase(remove(parseLine.at(2).begin(), parseLine.at(2).end(), ' '), parseLine.at(2).end());
			parseLine.at(3).erase(remove(parseLine.at(3).begin(), parseLine.at(3).end(), ' '), parseLine.at(3).end());
			try {
				lineLocation = stoi(parseLine.at(1));
				index = stoi(parseLine.at(2));
				deletSize = stoi(parseLine.at(3));
			}
			catch (exception& e) {
				return "Invalid command! : You entered a letter in the number part";
			}
			return viEditor.lock()->deleteString(lineLocation, index, deletSize);
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("c")) {
		if (parseLine.size() == 3) {
			return viEditor.lock()->changeString(parseLine.at(1), parseLine.at(2));
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("s")) {
		if (parseLine.size() == 2) {
			return viEditor.lock()->searchString(parseLine.at(1));
		}
		return "Invalid command!";
	}
	else if (!parseLine.at(0).compare("t")) {
		viEditor.lock()->saveAndExit();
	}
	else {
		return "Invalid command! : please enter the command in the list";
	}
}

int main() {
	weak_ptr<ViEditor> viEditor = ViEditor::getInstance();
	AppView appView;
	AppController appController(viEditor, appView);
	appController.run();
}