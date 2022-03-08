#include "pch.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
textEditor::textEditor(string inName, string outName):inFile(inName.c_str()), outFile(outName.c_str()) {
	infName = inName;
	if (!inFile  ) throw "�������ļ�ʧ��!";
	if (!outFile ) throw "������ļ�ʧ��!";	
	readFile();
}


//-*-*-*-*-*-*-*-IO*--*-*-*--*-*-*-*-*-*
void textEditor::readFile(){
	string s;
	textBuffer.clear();
	inFile.seekg(0);
	int lineNo = 1;
	cout << "��ȡ�ļ��ɹ�" << endl;
	while (getline(inFile, s)) {
		textBuffer.insert(lineNo++, s);
	}
	if (textBuffer.empty())curLineNo = 0;
	else curLineNo = 1;
	inFile.clear();
}

void textEditor::writeFile() {
	string s;
	if (textBuffer.empty())
		cout << "-Error: �ı�Ϊ��" << endl;
	else {
		for (int i = 1; i <= textBuffer.length(); i++) {
			s = textBuffer.getElem(i);
			outFile << s << endl;
		 }
		cout << "-д������ļ����" << endl;
	}
}

void textEditor::outInself() {
	ofstream outSelf(infName.c_str());
	string s;
	if (textBuffer.empty())
		cout << "-Error: �ı�Ϊ��" << endl;
	else {
		for (int i = 1; i <= textBuffer.length(); i++) {
			s = textBuffer.getElem(i);
			outSelf << s << endl;
		}
		cout << "-�����������ļ����" << endl;
	}
}
//-*-*-*-*-*-*-*-IO END*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-* Line Op-*-*-*-*-*-*-*-*-*-*-*
bool textEditor::nextLine(){
	if (curLineNo >= textBuffer.length())
	{	// ��ǰ�к��������һ��
		return 0;
	}
	else
	{	// ��ǰ�кŲ������һ��
		curLineNo++;
		cout << "-�Ѿ��ƶ�����һ��" << endl;
		return 1;
	}
}

bool textEditor::previousLine(){
	if (curLineNo <= 1)
	{	
		return 0;
	}
	else
	{	
		curLineNo--;
		cout << "-�Ѿ��ƶ�����һ��" << endl;
		return 1;
	}
}

bool textEditor::gotoLine(){
	int lineNumber;
	cout << "-����ָ�����к�: ";
	cin >> lineNumber;
	getchar();
	if (lineNumber < 1 || lineNumber > textBuffer.length())
	{	// �кŷ�Χ��
		return 0;
	}
	else
	{
		curLineNo = lineNumber;
		cout << "-�Ѿ��ƶ���ָ����" << endl;
		return 1;
	}
}
//*-*-*-*-*-*-*Line Op END--*-*-*-*--*-*-*-*

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void textEditor::showCurline() {
	cout << "-��ǰ������Ϊ��";
	cout << textBuffer.getElem(curLineNo)<<endl;
}

bool textEditor::insertLine()
{
	int lineNumber;
	cout << "-��������ָ���к�: ";
	cin >> lineNumber;
	cout << "-�����²������ı���: ";
	getchar();
	string s;
	getline(cin, s);
	if (textBuffer.insert(lineNumber, s) == 1)
	{	// ����ɹ�
		curLineNo = lineNumber;
		cout << "-�������" << endl;
		return 1;
	}
	else
	{	// ����ʧ��
		return 0;
	}
}

bool textEditor::changeLine() {

	cout << "-����Ҫ���滻��ָ���ı���: ";
	string oldString;
	getline(cin, oldString);
	string newString;
	cout << "-�������ı���:";
	getline(cin, newString);
	string curString = textBuffer.getElem(curLineNo);
	size_t position = curString.find(oldString);
	if (position < 0) {
		cout << "-�����ڸô�" << endl;
		return 0;
	}
	else {
		curString.erase(position, oldString.size());
		curString.insert(position, newString);
		textBuffer.setElem(curLineNo , curString);
		cout << "-�滻���" << endl;
		return 1;
	}
}  

void textEditor::substitude() {
	 string s;
	 getline(cin, s);
	 textBuffer.setElem(curLineNo, s);
	 cout << "-�滻���" << endl;
}

void textEditor::findString() {
	cout << "-����Ҫ���ҵĴ���";
	string findStr;
	getline(cin, findStr);
	int lineNumber = 1;
	while (lineNumber <= textBuffer.length())
	{
		string temStr = textBuffer.getElem(lineNumber);
		if (temStr.find(findStr) >= 0) {
			cout << "-�ô���һ�γ������У�" << lineNumber << endl;
			return;
		}
	}
	cout << "-δ�ҵ�Ŀ�괮" << endl;
}
//*-*-*-*-*-*-  END   -*-*-*-*-*-*-

//-*-*-*-*-*-*- RUN -*-*-*-*-*-*-*-*-*-*
void textEditor::run() {
	string userCommand;
	do
	{
		cout << "���������";
		getline(cin, userCommand);
		if (userCommand.size() > 1)
			cout << "-Warning: �����Ϊһ����ĸ" << endl;
		else {
			switch (userCommand[0])
			{
			case 'a':
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������ " << endl;
				}
				else {
					cout << "-���У�"<< textBuffer.length() <<" ��" << endl;
					cout << "-���У�" << textBuffer.statistic() << " �ַ�" << endl;
				}
				break;

			case 'b':
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������ " << endl;
				}
				else
				{
					curLineNo = 1;
					cout << "-�Ѿ����ص�һ��" << endl;
				}
				break;

			case 'c':
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������" << endl;
				}
				else if (!changeLine())
				{
					cout << "-Warning: �滻ʧ�� " << endl;
				}
				
				break;

			case 'd':
				if (!textBuffer.Delete(curLineNo))
				{
					cout << "-Error: ɾ��ʧ�� " << endl;
				}
				else {
					cout << "-ɾ���ɹ�" << endl;
				}
				break;

			case 'e':
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������ " << endl;
				}
				else
				{
					curLineNo = textBuffer.length();
					cout << "-�Ѿ��ƶ������һ��" << endl;
				}
				break;

			case 'f':
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������ " << endl;
				}
				else
				{
					findString();
				}
				break;

			case 'g':
				if (!gotoLine())
				{
					cout << "-Warning: û�и���" << endl;
				}
				break;

			case '?':
			case 'h':
				showHelp();
				break;

			case 'i':
				if (!insertLine())
					cout << "-Error�������г��� " << endl;
				break;
			case 'm':
				outInself();
				break;
			case 'n':
				if (!nextLine())
				{
					cout << "-Warning: ��ǰ���������һ��" << endl;
				}
				break;

			case 'p':
				if (!previousLine())
				{
					cout << "-Warning: ��ǰ�����ǵ�һ��" << endl;
				}
				break;

			case 'r':
				readFile();
				break;
			case 's':
				showCurline();
				break;
			case 'v':	// ��ʾ�ı�v(iew)
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������" << endl;
				}
				else
				{
					cout << "-�����ı�Ϊ��" << endl;
					textBuffer.view();
				}
				break;

			case 'w':	// д�ı����浽����ļ���w(rite)
				if (textBuffer.empty())
				{
					cout << "-Warning: �ı������" << endl;
				}
				else
				{	// д�ı����浽����ļ���
					writeFile();
				}
				break;
			default:
				cout << "����h��?��ð�����������Ч�����ַ�: \n";
			}
		}
	} while (userCommand[0] != 'q');
}
//-*-*-*-*-*-*-*-END RUN-*-*-*-*--*-*-*-*


//-*-*-*-*-*-*-*-  HELP  -*-*-*-*--*-*-*-*
void textEditor::showHelp() {
	cout << "-------------------help--------------------" << endl;
	cout << "����(ȫ��)    ���ý���   " << endl;
	cout << " a (Analyze) ͳ�Ƶ�ǰ�ı�����Ϣ" << endl;
	cout << " b (Begin)   �ƶ�����ʼ��" << endl;
	cout << " c (Change)  �滻����ĳһ����" << endl;
	cout << " d (Delete)  ɾ����ǰ�в��ƶ�����һ��" << endl;
	cout << " e (End)     �ƶ���������" << endl;
	cout << " f (Find)    ���Ұ���Ŀ�괮�ĵ�һ��" << endl;
	cout << " g (Goto)    ǰ��ָ����" << endl;
    //help
	cout << " i (Insert)  ��ָ���в��뵥������" << endl;
	cout << " m (Memory)  �����޸ĺ���ı�" << endl;
	cout << " n (Next)    �ƶ�����ǰ����һ��" << endl;
	cout << " p (Previous)�ƶ�����ǰ����һ�� " << endl;
	cout << " q (Quit)    �˳��༭��" << endl;
	cout << " r (Read)    ��ȡ�ı�" << endl;
	cout << " s (Show)    ��ʾ��ǰ������" << endl;
	cout << " t (replace) �滻��ǰ������" << endl;
	cout << " v (View)    �鿴ȫ������" << endl;
	cout << " w (Write)   ������������д���ı��ļ�" << endl;
	cout << "----------------help End--------------------" << endl;
}
