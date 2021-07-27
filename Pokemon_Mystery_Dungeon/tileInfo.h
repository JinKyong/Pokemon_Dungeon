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
	OBJ_TRAP, OBJ_TRAP1, OBJ_TRAP2,
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
	Unused = '~',
	Floor = '!',
	Corridor = '#',
	Wall = '$',
	ClosedDoor = '%',
	UpStairs = '&',
	DownStairs = '(',
	LeftTriWall = ')',
	RightTriWall = '*',
	TopTriWall = '+',
	BottomTriWall = ',',
	LeftOpenWall = '-',
	RightOpenWall = '.',
	TopOpenWall = '/',
	BottomOpenWall = '0',
	LeftOpenCorner = '1',
	LeftCorner = '2',
	RightOpenCorner = '3',
	RightCorner = '4',
	LeftOpenBottom = '5',
	LeftBottom = '6',
	RightOpenBottom = '7',
	RightBottom = '8',
	VerticalWall = '9',
	VerticalLeftWall = ':',
	VerticalRightWall = ';',
	HorizontalTopWall = '<',
	HorizontalBottomWall = '=',
	HorizontalWall = '>',
	LeftBlockWall = '?',
	RightBlockWall = '@',
	TopBlockWall = 'A',
	BottomBlockWall = 'B',
	VerticalTopRight = 'C',
	VerticalTopLeft = 'D',
	VerticalBottomRight = 'E',
	VerticalBottomLeft = 'F',
	HorizontalTopRight = 'G',
	HorizontalTopLeft = 'H',
	HorizontalBottomRight = 'I',
	HorizontalBottomLeft = 'J',
	AllOpenRight = 'K',
	AllOpenLeft = 'L',
	OpenConnectTopLeft = 'M',
	OpenConnectTopRight = 'N',
	OpenConnectBottomLeft = 'O',
	OpenConnectBottomRight = 'P',
	LeftTopBlockCorner = 'Q',
	RightTopBlockCorner = 'R',
	LeftBottomBlockCorner = 'S',
	RightBottomBlockCorner = 'T',
	ClearTrap = 'U',
	PowerTrap = 'V'

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