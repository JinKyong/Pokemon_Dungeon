#pragma once

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

//������
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//��Ʈ��
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

//Ÿ�� ���� ���� ����ü
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

//Ÿ�ϼ� ���� ���� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ÿ�� �޾ƿ� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};

