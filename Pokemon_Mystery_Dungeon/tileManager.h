#pragma once
#include "singletonBase.h"
#include <vector>

#define TILESIZE 48
#define MINITILESIZE 6

#define TILEX 80	//���� Ÿ�� ����
#define TILEY 45	//���� Ÿ�� ����



#define TILESIZEX TILESIZE * TILEX	//560 28 * 20
#define TILESIZEY TILESIZE * TILEY	//620 31 * 20

//Ÿ�ϼ� ����
#define SAMPLETILEX 18
#define SAMPLETILEY 12

//��Ʈ�ʵ�
#define ATTR_UNMOVE 0x00000016	//������ Ÿ��
#define ATTR_SWAMP	0x00000032	//������ �������� Ÿ��
#define ATTR_POISON	0x00000064	//�� �� �� ������~
#define ATTR_FROZEN 0x00000128	//������~
#define ATTR_WATER	0x00000256  //��


//����
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK2, OBJ_BLOCK3, OBJ_BLOCK4, OBJ_BLOCK5, OBJ_BLOCK6, OBJ_BLOCK7, OBJ_BLOCK8,
	OBJ_TRAP, OBJ_TRAP1,
	OBJ_SPAWN, OBJ_UPSTAIR,
	OBJ_WATER,
	OBJ_NONE
};

//��Ʈ��
enum CTRL
{
	CTRL_SAVE,			//���̺�		
	CTRL_LOAD,			//�ε�		
	CTRL_RANDOM,		//����		
	CTRL_TERRAINDRAW,	//����		
	CTRL_OBJDRAW,		//������Ʈ	
	CTRL_ERASER,		//���찳		
	CTRL_END
};

//Ÿ�� ����Ÿ��
enum Tile
{
	Unused = ' ',
	Floor = '.',
	Corridor = ',',
	Wall = '#',
	ClosedDoor = '+',
	OpenDoor = '-',
	UpStairs = '<',
	DownStairs = '>',
	Monster = 'M',
	Trap = 'T'
};

//����ü ����
enum Direction
{
	North,
	South,
	West,
	East,
	DirectionCount
};

//Ÿ�� ���� ���� ����ü
typedef struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
}TILE,*PTILE;

//Ÿ�ϼ� ���� ���� ����ü
typedef struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
}STILE,*PSTILE;

//���� Ÿ�� �޾ƿ� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};

class tileManager: public singletonBase<tileManager>
{
private:
	vector<tagTile*>					_vTile;
	vector<tagSampleTile*>				_vSampleTile;
	vector<DWORD*>						_vAttribute;

	vector<char>						_vChar;
	vector<RECT>						_vRoom;
	vector<RECT>						_vExit;

	dImage* _Mapbase;
	dImage*	_Obbase;

	int _initX;
	int _endX;
	int _initY;
	int _endY;

	int _width;
	int _height;


public: 	
	tileManager();
	~tileManager();

	HRESULT init();
	HRESULT init(int width, int height);
	void release();
	void update();
	void render();
	void setup();

	//void save(const char* mapName);
	//void load(const char* mapName);
	void minimap();

	void dungeon(int width, int height);
	void generate(int maxFeatures);
	bool createFeature();
	bool createFeature(int x, int y, Direction dir);
	bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
	bool makeCorridor(int x, int y, Direction dir);
	bool placeRect(RECT rc, char Char);
	bool placeObject(char Char);
	   
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	
	
	void setChar(int x, int y, char Char) { _vChar[x + y * _width] = Char; }
	void setWidth(int Width) { _width = Width; }
	void setHeight(int Height) { _height = Height; }
	
	int getWidth() { return _width; }
	int getHeight() { return _height; }
	char getChar(int x, int y) { return _vChar[x + y * _width]; }
	vector<tagTile*>* getvTile() { return &_vTile; }

};

