#include "stdafx.h"
#include "txtData.h"
#include "Item.h"

HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{
}

void txtData::loadGame(Player* player)
{
	LPCWCHAR fileName = L"data/saveData";
	int pokemon = _wtoi(loadDataString2(fileName, L"player", L"pokemon", 128));
	int level = _wtoi(loadDataString2(fileName, L"player", L"level", 128));

	//���ϸ�, ����
	player->init(pokemon, level);

	//����ġ
	int exp = _wtoi(loadDataString2(fileName, L"player", L"exp", 128));
	player->setEXP(exp);

	//������
	WCHAR skill[128] = L"";
	lstrcatW(skill, loadDataString2(fileName, L"player", L"skill", 128));
	vector<LPCWCHAR> skillList = wcharArraySeparation(skill);
	vector<LPCWCHAR>::iterator skillIter = skillList.begin();
	for (; skillIter != skillList.end(); ++skillIter) {
		player->loadSkill(_wtoi(*skillIter));
	}

	////�κ� ���
	//WCHAR inven[128];
	//swprintf_s(inven, L"");
	//vector<Item*>* itemList = INVENTORYMANAGER->getVItem();
	//vector<Item*>::iterator itemIter = itemList->begin();
	//for (; itemIter != itemList->end(); ++itemIter) {
	//	WCHAR tmp[128];
	//	swprintf_s(tmp, L"%d@", (*itemIter)->getNum());
	//	lstrcatW(inven, tmp);
	//}
	//lstrcatW(inven, L"#");
	//addData(L"player", L"inven", inven);
	//
	////â�� ���
	//WCHAR storage[512];
	//swprintf_s(storage, L"");
	//itemList = INVENTORYMANAGER->getVitemStorage();
	//itemIter = itemList->begin();
	//for (; itemIter != itemList->end(); ++itemIter) {
	//	WCHAR tmp[128];
	//	swprintf_s(tmp, L"%d@", (*itemIter)->getNum());
	//	lstrcatW(storage, tmp);
	//}
	//lstrcatW(storage, L"#");
	//addData(L"player", L"storage", storage);
}

void txtData::saveGame(Player* player)
{
	//���ϸ�
	WCHAR pokemon[128];
	swprintf_s(pokemon, L"%d", player->getPokemon()->getNum());
	addData(L"player", L"pokemon", pokemon);

	//����
	WCHAR level[128];
	swprintf_s(level, L"%d", player->getLevel());
	addData(L"player", L"level", level);

	//����ġ
	WCHAR exp[128];
	swprintf_s(exp, L"%d", player->getEXP());
	addData(L"player", L"exp", exp);

	//������
	WCHAR skill[128];
	swprintf_s(skill, L"");
	for (int i = 0; i < 4; i++) {
		if (player->getSkill()[i]) {
			WCHAR tmp[128];
			swprintf_s(tmp, L"%d@", player->getSkill()[i]->getNum());
			lstrcatW(skill, tmp);
		}
	}
	lstrcatW(skill, L"#");
	addData(L"player", L"skill", skill);

	//�κ� ���
	WCHAR inven[128];
	swprintf_s(inven, L"");
	vector<Item*>* itemList = INVENTORYMANAGER->getVItem();
	vector<Item*>::iterator itemIter = itemList->begin();
	for (; itemIter != itemList->end(); ++itemIter) {
		WCHAR tmp[128];
		swprintf_s(tmp, L"%d@", (*itemIter)->getNum());
		lstrcatW(inven, tmp);
	}
	lstrcatW(inven, L"#");
	addData(L"player", L"inven", inven);

	//â�� ���
	WCHAR storage[512];
	swprintf_s(storage, L"");
	itemList = INVENTORYMANAGER->getVitemStorage();
	itemIter = itemList->begin();
	for (; itemIter != itemList->end(); ++itemIter) {
		WCHAR tmp[128];
		swprintf_s(tmp, L"%d@", (*itemIter)->getNum());
		lstrcatW(storage, tmp);
	}
	lstrcatW(storage, L"#");
	addData(L"player", L"storage", storage);

	iniSave(L"data/saveData");
}

void txtData::addData(LPCWCHAR subject, LPCWCHAR title, LPCWCHAR body)
{
	tagIniData iniData;
	iniData.subject = subject;
	iniData.title = title;
	iniData.body = body;

	arrIniData vIniData;
	vIniData.push_back(iniData);

	_vIniData.push_back(vIniData);
}

void txtData::iniSave(LPCWCHAR fileName)
{
	//���� ��� ����
	WCHAR str[256];
	WCHAR dir[256];

	ZeroMemory(dir, sizeof(dir));
	swprintf_s(dir, L"\\%s.ini", fileName);

	//���� ���丮 ��θ� �޾ƿ��ִ� �Լ�
	GetCurrentDirectoryW(256, str);
	lstrcatW(str, dir);

	//���� ����
	for (int i = 0; i < _vIniData.size(); ++i)
	{
		arrIniData vData = _vIniData[i];
		WritePrivateProfileStringW(vData[0].subject, vData[0].title, vData[0].body, str);

		vData.clear();
	}

	_vIniData.clear();
}

LPCWCHAR txtData::loadDataString(LPCWCHAR fileName, LPCWCHAR subject, LPCWCHAR title, int size)
{
	//���� ��� ����
	WCHAR str[256];
	WCHAR dir[256];

	ZeroMemory(dir, sizeof(dir));
	swprintf_s(dir, L"\\%s.ini", fileName);

	//���� ���丮 ��θ� �޾ƿ��ִ� �Լ�
	GetCurrentDirectoryW(256, str);
	lstrcatW(str, dir);

	//�о����
	ZeroMemory(_currentTxt, sizeof(_currentTxt));
	GetPrivateProfileStringW(subject, title, L"", _currentTxt, size, str);

	return _currentTxt;
}

LPCWCHAR txtData::loadDataString2(LPCWCHAR fileName, wstring subject, LPCWCHAR title, int size)
{
	//���� ��� ����
	WCHAR str[256];
	WCHAR dir[256];

	ZeroMemory(dir, sizeof(dir));
	swprintf_s(dir, L"\\%s.ini", fileName);

	//���� ���丮 ��θ� �޾ƿ��ִ� �Լ�
	GetCurrentDirectoryW(256, str);
	lstrcatW(str, dir);

	//�о����
	ZeroMemory(_currentTxt, sizeof(_currentTxt));
	GetPrivateProfileStringW(subject.c_str(), title, L"", _currentTxt, size, str);

	return _currentTxt;
}

int txtData::loadDataInterger(LPCWCHAR fileName, LPCWCHAR subject, LPCWCHAR title)
{
	//���� ��� ����
	WCHAR str[256];
	WCHAR dir[256];

	ZeroMemory(dir, sizeof(dir));
	swprintf_s(dir, L"\\%s.ini", fileName);

	GetCurrentDirectoryW(256, str);	//���� ���丮 ��θ� �޾ƿ��ִ� �Լ�
	lstrcatW(str, dir);


	//�о����
	return GetPrivateProfileIntW(subject, title, 0, str);
}

void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[128];

	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}

void txtData::wtxtSave(const char * saveFileName, vector<LPCWCHAR> vwStr)
{
	HANDLE file;
	DWORD write;

	WCHAR str[128];

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, wvectorArrayCombine(vwStr), 128, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	char str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		if (i + 1 < vArray.size()) strcat_s(str, ",");
	}

	return str;
}

LPCWCHAR txtData::wvectorArrayCombine(vector<LPCWCHAR> vArray)
{
	WCHAR str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); ++i)
	{
		lstrcatW(str, vArray[i]);
		if (i + 1 < vArray.size()) lstrcatW(str, L",");
	}

	return str;
}

vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	DWORD read;
	__int64 file_size = 0;

	char* str;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD temp_size = GetFileSize(file, (DWORD*)&file_size + 1);
	file_size |= temp_size;

	str = new char[file_size];

	ReadFile(file, str, file_size, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<LPCWCHAR> txtData::wtxtLoad(LPCWCHAR loadFileName)
{
	HANDLE file;
	DWORD read;
	__int64 file_size = 0;

	WCHAR* str;

	file = CreateFileW(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD temp_size = GetFileSize(file, (DWORD*)&file_size + 1);
	file_size |= temp_size;

	str = new WCHAR[file_size];
	ZeroMemory(str, sizeof(str));

	ReadFile(file, str, file_size, &read, NULL);

	CloseHandle(file);

	return wcharArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;
	char* temp;
	const char* separator = ",";
	char* token;

	token = strtok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}

vector<LPCWCHAR> txtData::wcharArraySeparation(WCHAR charArray[])
{
	vector<LPCWCHAR> vArray;
	WCHAR* temp;
	const WCHAR* separator = L"@";
	WCHAR* token;

	token = wcstok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = wcstok_s(NULL, separator, &temp)))
	{
		if (token[0] == L'#') break;
		vArray.push_back(token);
	}

	return vArray;
}
