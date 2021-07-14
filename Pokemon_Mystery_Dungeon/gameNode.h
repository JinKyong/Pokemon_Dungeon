#pragma once

enum CTRL
{
	CTRL_SAVE,			//���̺�		��ư
	CTRL_LOAD,			//�ε�		��ư
	CTRL_RANDOM,		//����		��ư
	CTRL_TERRAINDRAW,	//����		��ư
	CTRL_OBJDRAW,		//������Ʈ	��ư
	CTRL_ERASER,		//���찳		��ư
	CTRL_END
};

class gameNode
{
private:
	bool _managerInit;

public:
	gameNode();
	virtual ~gameNode();

	int _ctrSelect;

	//HRESULT ���� ���� ��ȯ�����ε�
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render();			//�׸��� �Լ�

	void cursorOnWindow();

	virtual void setMap();

	virtual void save();
	virtual void load();

	void setCtrlSelect(int num) { _ctrSelect = num; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};