#pragma once

#define TILESIZE 48

#define TILEX 30	//���� Ÿ�� ����
#define TILEY 30	//���� Ÿ�� ����

#define TILESIZEX TILESIZE * TILEX	//560 28 * 20
#define TILESIZEY TILESIZE * TILEY	//620 31 * 20

//Ÿ�ϼ� ����
#define SAMPLETILEX 18
#define SAMPLETILEY 12

//��Ʈ�ʵ�
#define ATTR_UNMOVE 0x00000001	//������ Ÿ��
#define ATTR_SWAMP	0x00000002	//������ �������� Ÿ��
#define ATTR_POISON	0x00000004	//�� �� �� ������~
#define ATTR_FROZEN 0x00000008	//������~


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
	OBJ_NONE
};

//������
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
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

