#pragma once


//지형
enum TERRAIN
{
	TR_BLOCK, TR_WATER, TR_GRASS, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK,
	OBJ_TRAP, OBJ_TRAP1,
	OBJ_STAIR,
	OBJ_NONE
};

//컨트롤
enum CTRL
{	
	CTRL_TERRAINDRAW,	//지형		
	CTRL_OBJDRAW,		//오브젝트	
	CTRL_ERASER,		//지우개		
	CTRL_END
};

//타일 글자타입
enum Tile
{
	Unused = ' ',
	Floor = '!',
	Corridor = '#',
	Wall = '$',
	ClosedDoor = '%',
	UpStairs = '&',
	DownStairs = '(',
	LeftOpenCorner = ')',
	LeftCorner = '*',
	RightOpenCorner = '+',
	RightCorner = ',',
	LeftOpenBottom = '-',
	LeftBottom = '.',
	RightOpenBottom = '/',
	RightBottom = '0',
	VerticalWall = '1',
	VerticalTopWall = '2',
	VerticalBottomWall = '3',
	HorizontalLeftWall = '4',
	HorizontalRightWall = '5',
	HorizontalWall = '6',
	LeftBlockWall='7',
	RightBlockWall='8',
	
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
	int			x;
	int			y;
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