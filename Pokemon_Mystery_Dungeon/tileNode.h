#pragma once

#define TILESIZE 48
#define MINITILESIZE 6

#define TILEX 80	//가로 타일 갯수
#define TILEY 45	//세로 타일 갯수



#define TILESIZEX TILESIZE * TILEX	//560 28 * 20
#define TILESIZEY TILESIZE * TILEY	//620 31 * 20

//타일셋 정의
#define SAMPLETILEX 18
#define SAMPLETILEY 12

//비트필드
#define ATTR_UNMOVE 0x00000016	//못가는 타일
#define ATTR_SWAMP	0x00000032	//밟으면 느려지는 타일
#define ATTR_POISON	0x00000064	//유 아 마 포이즌~
#define ATTR_FROZEN 0x00000128	//레릿꼬~
#define ATTR_WATER	0x00000256  //물


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

//포지션
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//컨트롤
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

//타일 정보 담은 구조체
struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};

//타일셋 정보 담을 구조체
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//현재 타일 받아올 구조체
struct tagCurrentTile
{
	int x;
	int y;
};

