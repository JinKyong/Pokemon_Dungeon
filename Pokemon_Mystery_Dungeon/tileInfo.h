#pragma once


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
	Trap = 'T',
	LeftCorner = '!',
	RightCorner = '~',
	LeftBottom = '$',
	RightBottom = '%',
	VerticalWall = '^',
	HorizontalWall = '*'
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