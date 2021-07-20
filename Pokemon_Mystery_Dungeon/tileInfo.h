#pragma once


//지형
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK2, OBJ_BLOCK3, OBJ_BLOCK4, OBJ_BLOCK5, OBJ_BLOCK6, OBJ_BLOCK7, OBJ_BLOCK8,
	OBJ_TRAP, OBJ_TRAP1,
	OBJ_SPAWN, OBJ_UPSTAIR,
	OBJ_WATER,
	OBJ_NONE
};

//컨트롤
enum CTRL
{
	CTRL_SAVE,			//세이브		
	CTRL_LOAD,			//로드		
	CTRL_RANDOM,		//랜덤		
	CTRL_TERRAINDRAW,	//지형		
	CTRL_OBJDRAW,		//오브젝트	
	CTRL_ERASER,		//지우개		
	CTRL_END
};

//타일 글자타입
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
	Trap = 'T',
	LeftCorner = '!',
	RightCorner = '~',
	LeftBottom = '$',
	RightBottom = '%',
	VerticalWall = '^',
	HorizontalWall = '*'
};

//각객체 방향
enum Direction
{
	North,
	South,
	West,
	East,
	DirectionCount
};

//타일 정보 담은 구조체
typedef struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
}TILE, *PTILE;

//타일셋 정보 담을 구조체
typedef struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
}STILE, *PSTILE;

//현재 타일 받아올 구조체
struct tagCurrentTile
{
	int x;
	int y;
};