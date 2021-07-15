#pragma once

enum CTRL
{
	CTRL_SAVE,			//세이브		버튼
	CTRL_LOAD,			//로드		버튼
	CTRL_RANDOM,		//랜덤		버튼
	CTRL_TERRAINDRAW,	//지형		버튼
	CTRL_OBJDRAW,		//오브젝트	버튼
	CTRL_ERASER,		//지우개		버튼
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

	//HRESULT 마소 전용 반환형식인데
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//초기화 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 함수
	virtual void render();			//그리기 함수

	void cursorOnWindow();

	virtual void setMap();

	virtual void save();
	virtual void load();

	void setCtrlSelect(int num) { _ctrSelect = num; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};