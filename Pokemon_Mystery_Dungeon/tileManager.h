#pragma once
#include "singletonBase.h"
#include "tileInfo.h"
#include <vector>

#define TILESIZE 48
#define MINITILESIZE 6

#define TILEX 80	//가로 타일 갯수
#define TILEY 45	//세로 타일 갯수



#define TILESIZEX TILESIZE * TILEX	//560 28 * 20
#define TILESIZEY TILESIZE * TILEY	//620 31 * 20

//타일셋 정의
#define SAMPLETILEX 15
#define SAMPLETILEY 4

//비트필드
#define ATTR_UNMOVE 0x00000016	//못가는 타일
#define ATTR_SWAMP	0x00000032	//밟으면 느려지는 타일
#define ATTR_POISON	0x00000064	//유 아 마 포이즌~
#define ATTR_FROZEN 0x00000128	//레릿꼬~
#define ATTR_WATER	0x00000256  //물


class tileManager : public singletonBase<tileManager>
{
private:
	vector<tagTile*>					_vTile;
	vector<tagSampleTile*>				_vSampleTile;
	vector<DWORD*>						_vAttribute;

	vector<char>						_vChar;
	vector<RECT>						_vRoom;
	vector<RECT>						_vExit;

	dImage* _Mapbase[8];
	dImage*	_Obbase;

	tagTile _tiles[TILEX*TILEY];
	DWORD _attribute[TILEX*TILEY];

	int _initX;
	int _endX;
	int _initY;
	int _endY;

	int _width;
	int _height;
	int _type;
	int _trapCount;

public:
	tileManager();
	~tileManager();

	HRESULT init();										//기본 이니셜라이즈
	HRESULT init(int width, int height);				//맵로드용 이니셜라이즈
	HRESULT init(int width, int height, int type);		//던전용 이니셜라이즈
	void release();
	void update();
	void render();
	void maprender();
	void setup();

	void load(const char* mapName);
	void minimap();

	void dungeon(int width, int height);
	void generate(int maxFeatures);
	bool createFeature();
	bool createFeature(int x, int y, Direction dir);
	bool makeRoom(int x, int y, Direction dir);
	bool makeCorridor(int x, int y, Direction dir);
	bool placeRect(RECT rc, char Char);
	bool placeObject(char Char);

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);



	void setChar(int x, int y, char Char) { _vChar[x + y * _width] = Char; }
	void setWidth(int Width) { _width = Width; }
	void setHeight(int Height) { _height = Height; }
	void setType(int type) { _type = type; }

	int getWidth() { return _width; }
	int getHeight() { return _height; }
	int getType() { return _type; }
	char getChar(int x, int y) { return _vChar[x + y * _width]; }

	vector<tagTile*>* getvTile() { return &_vTile; }
	vector<RECT>* getvRoom() { return &_vRoom; }

};

