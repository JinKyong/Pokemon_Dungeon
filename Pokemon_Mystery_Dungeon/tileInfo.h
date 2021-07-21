#pragma once


//����
enum TERRAIN
{
	TR_BLOCK, TR_WATER, TR_GRASS, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK,
	OBJ_TRAP, OBJ_TRAP1,
	OBJ_STAIR,
	OBJ_NONE
};

//��Ʈ��
enum CTRL
{	
	CTRL_TERRAINDRAW,	//����		
	CTRL_OBJDRAW,		//������Ʈ	
	CTRL_ERASER,		//���찳		
	CTRL_END
};

//Ÿ�� ����Ÿ��
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
	int			x;
	int			y;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
}TILE, *PTILE;

//Ÿ�ϼ� ���� ���� ����ü
typedef struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
}STILE, *PSTILE;

//���� Ÿ�� �޾ƿ� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};