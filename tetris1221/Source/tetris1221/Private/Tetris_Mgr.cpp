// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris_Mgr.h"
#include"random"
#include"time.h"

// Sets default values
ATetris_Mgr::ATetris_Mgr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATetris_Mgr::BeginPlay()
{
	Super::BeginPlay();
	game_time = 0;
	m_block.pos = FVector2Int(2, 0);
	m_block.move_time = 0;
	m_block.wait_time = 0;

	hold = -1;
	srand((unsigned)time(NULL));
	

	Load();
	for (int i = 0; i < RAND_NUM_MAX_SIZE; i++)
	{
		//乱数生成
		rand_num[i] = (unsigned short)rand() % BLOCK_TYPE;
	}
	rand_num_index = rand() % RAND_NUM_MAX_SIZE;

	for (int i = 0; i < 5; i++)
	{
		if (rand_num_index++ >= RAND_NUM_MAX_SIZE - 1)
		{
			rand_num_index = 0;
		}
		next[i] = rand_num[rand_num_index];
	}
	//ブロック生成
	spawn_block();
}

// Called every frame
void ATetris_Mgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 
	if (gane_over) return;
	game_time += DeltaTime;
	//m_block.move_time += Time.deltaTime;
	act_interface(DeltaTime);
	wait_block(DeltaTime);

	if (wall_judg_block())
	{
		m_block.wait_time += DeltaTime;
		if (m_block.wait_time >= 1.0f)
		{
			m_block.wait_time = 0.0f;
			for (int y = 0; y < BLOCK_MAX_Y; y++)
			{
				int index_y_num = (m_block.pos.y - 2) + y;
				if (index_y_num >= 0 && index_y_num < STAGE_MAX_Y + BLOCK_MAX_Y)
				{
					for (int x = 0; x < BLOCK_MAX_X; x++)
					{
						int index_x_num = (m_block.pos.x - 2) + x;
						if (index_x_num >= 0 && index_x_num < STAGE_MAX_X)
						{
							if (m_block.block_date[y][x])
							{
								block_stage[index_y_num][index_x_num].draw_frag = true;
								block_stage[index_y_num][index_x_num].co = m_block.co;
								block_stage[index_y_num][index_x_num].id = m_block.id;
							}
						}
					}
				}
			}

			for (int y = 0; y < STAGE_MAX_Y + BLOCK_MAX_Y; y++)
			{
				for (int x = 0; x < STAGE_MAX_X; x++)
				{
					if (!block_stage[y][x].draw_frag) break;


					if (x == STAGE_MAX_X - 1)
					{
						score += 1000;
						tumeru(y);
					}
				}
			}

			for (int y = 0; y < BLOCK_MAX_Y; y++)
			{
				for (int x = 0; x < STAGE_MAX_X; x++)
				{
					if (block_stage[y][x].draw_frag) gane_over = true;

				}
			}
			spawn_block();
		}
	}
	else
	{
		m_block.pos += m_block.v;
	}



	m_block.v = FVector2Int();

	//描画用に変換
	for (int y = 0; y < STAGE_MAX_Y; y++)
	{
		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			block_draw[0][y][x] = block_stage[y + 5][x];
		}
	}
	for (int y = 0; y < 5; y++)
	{
		int index_y_num = (m_block.pos.y - 2) + y - 5;
		if (index_y_num >= 0 && index_y_num < 20)
		{
			for (int x = 0; x < 5; x++)
			{
				int index_x_num = (m_block.pos.x - 2) + x;
				if (index_x_num >= 0 && index_x_num < STAGE_MAX_X)
				{
					if (m_block.block_date[y][x])
					{
						block_draw[0][index_y_num][index_x_num].draw_frag = true;
						block_draw[0][index_y_num][index_x_num].co = m_block.co;
						block_draw[0][index_y_num][index_x_num].id = m_block.id;
					}
				}
			}
		}
	}

	for (int y = 0; y < STAGE_MAX_Y; y++)
	{
		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			//stage_obj.GetComponent<stage_mgr>().block_draw[y, x] = block_draw[0, y, x];
			stage_obj->block_draw[y][x] = block_draw[0][y][x];
		}

	}
}

void ATetris_Mgr::wait_block(float DeltaTime) {
	m_block.move_time += DeltaTime;
	if (m_block.move_time >= MOVE_TIME_MAX)
	{
		m_block.move_time = 0.0f;
		m_block.v.y = 1;
	}
}

void ATetris_Mgr::spawn_block() {
	m_block.block_pos.clear();

	//ブロック生成
	for (int y = 0; y < BLOCK_MAX_Y; y++)
	{
		for (int x = 0; x < BLOCK_MAX_X; x++)
		{
			m_block.block_date[y][x] = n_block[next[0]].block_date[y][x];
			if (m_block.block_date[y][x])
			{
				m_block.block_pos.push_back(FVector2Int(x - 2, y - 2));
			}
		}
	}

	m_block.co = n_block[next[0]].co;
	m_block.id = next[0];


	//ai_step = Define.STEP.SPWAN;
	//初期位置設定
	m_block.pos.y = 2;
	m_block.pos.x = STAGE_MAX_X / 2;

	//乱数生成
	//int rand = Random.Range(0, Define.BLOCK_TYPE);
	for (int i = 1; i < 5; i++)
	{
		next[i - 1] = next[i];
	}
	if (rand_num_index++ >= RAND_NUM_MAX_SIZE - 1) rand_num_index = 0;
	next[4] = rand_num[rand_num_index];
}

void ATetris_Mgr::block_hold() {
	m_block.block_pos.clear();

	//ブロック生成
	for (int y = 0; y < BLOCK_MAX_Y; y++)
	{
		for (int x = 0; x < BLOCK_MAX_X; x++)
		{



			m_block.block_date[y][x] = n_block[hold].block_date[y][x];


			if (m_block.block_date[y][x])
			{
				m_block.block_pos.push_back(FVector2Int(x - 2, y - 2));
			}
		}

	}

	int num = m_block.id;

	m_block.co = n_block[hold].co;
	m_block.id = hold;
	hold = num;

	//当たり判定
	for (int i = 0; i < (int)m_block.block_pos.size(); i++)
	{
		FVector2Int a = m_block.block_pos[i] + m_block.pos;

		if (a.x < 0)
		{
			m_block.pos.x++;
			i = 0;
			continue;
		}
		else if (a.x >= STAGE_MAX_X)
		{
			m_block.pos.x--;
			i = 0;
			continue;
		}

		if (block_stage[a.y][a.x].draw_frag)
		{
			m_block.pos.y--;
			i = 0;
			continue;
		}
	}
}

void ATetris_Mgr::act_interface(float DeltaTime) {
	for (int i = 0; i < act.size(); i++)
	{
		if (act[i] == EACT::DOWN)
		{
			m_block.move_time += DeltaTime * 20.0f;
			m_block.wait_time = 1.0f;
		}
		else if (act[i] == EACT::LEFT)
		{
			m_block.v.x--;
			m_block.wait_time = 0;
		}
		else if (act[i] == EACT::RIGHT)
		{
			m_block.v.x++;
			m_block.wait_time = 0;
		}

		else if (act[i] == EACT::LEFT_ROLL)
		{
			kaitenn(false);
		}
		else if (act[i] == EACT::RIGHT_ROLL)
		{
			kaitenn(true);
		}
		else if (act[i] == EACT::HOLD)
		{
			if (hold != -1)
			{
				block_hold();
			}
			else
			{
				hold = m_block.id;
				FVector2Int inst = m_block.pos;
				spawn_block();
				m_block.pos = inst;
			}
		}
	}
	act.clear();
}

bool ATetris_Mgr::wall_judg_block() {
	for (int i = 0; i < (int)m_block.block_pos.size(); i++)
	{
		FVector2Int a = m_block.block_pos[i] + m_block.pos;
		{
			//外枠判定
			FVector2Int a2 = a + m_block.v;
			if (a2.x < 0)
			{
				m_block.v.x = 0;
			}
			if (a2.x >= STAGE_MAX_X)
			{
				m_block.v.x = 0;
			}

			if (a2.y >= STAGE_MAX_Y + BLOCK_MAX_Y)
			{
				m_block.v.y = 0;
				return true;
			}

		}
		//ブロック判定
		if (block_stage[a.y][a.x + m_block.v.x].draw_frag)
		{
			m_block.v.x = 0;
		}
		if (block_stage[a.y + m_block.v.y][a.x].draw_frag)
		{
			m_block.v.y = 0;
			return true;
		}

	}
	return false;
}

void ATetris_Mgr::kaitenn(bool right_f) {
	bool inst[5][5];

	memcpy(inst, m_block.block_date, sizeof(m_block.block_date));

	for (int y = 0; y < BLOCK_MAX_Y; y++)
	{
		for (int x = 0; x < BLOCK_MAX_X; x++)
		{

			if (right_f)
			{
				m_block.block_date[y][x] = inst[(BLOCK_MAX_Y - 1) - x][y];
			}
			else
			{
				m_block.block_date[y][x] = inst[x][(BLOCK_MAX_X - 1) - y];
			}
		}
	}

	m_block.block_pos.clear();

	for (int y = 0; y < BLOCK_MAX_Y; y++)
	{
		for (int x = 0; x < BLOCK_MAX_X; x++)
		{
			if (m_block.block_date[y][x])
			{
				m_block.block_pos.push_back(FVector2Int(x - 2, y - 2));
			}
		}
	}
	//当たり判定
	for (int i = 0; i < (int)m_block.block_pos.size();)
	{
		FVector2Int a = m_block.block_pos[i] + m_block.pos;

		if (a.x < 0)
		{
			m_block.pos.x++;
			i = 0;
			continue;
		}
		else if (a.x >= STAGE_MAX_X)
		{
			m_block.pos.x--;
			i = 0;
			continue;
		}
		else if (a.y < 0)
		{
			m_block.pos.y--;
			i = 0;
			continue;
		}

		if (block_stage[a.y][a.x].draw_frag)
		{
			for (int j = 0; j < (int)m_block.block_pos.size(); j++)
			{
				FVector2Int b = m_block.block_pos[i] + m_block.pos;

				if (right_f)
				{
					b += FVector2Int(1, -1);
				}
				else
				{
					b += FVector2Int(-1, -1);
				}

				if (block_stage[b.y][b.x].draw_frag)
				{
					m_block.pos.y--;
					i = 0;
					break;
				}
				else if (j >= (int)m_block.block_pos.size() - 1)
				{
					if (right_f)
					{
						m_block.pos += FVector2Int(1, -1);
					}
					else
					{
						m_block.pos += FVector2Int(-1, -1);
					}
					i = 0;
				}
			}

			continue;
		}
		i++;
	}
}

void ATetris_Mgr::tumeru(int d_y) {
	for (int y = d_y; y > BLOCK_MAX_Y; y--)
	{
		for (int x = 0; x < STAGE_MAX_X; x++)
		{
			block_stage[y][x] = block_stage[y - 1][x];
		}
	}

	//削除
	for (int i = 0; i < STAGE_MAX_X; i++)
	{
		block_stage[BLOCK_MAX_Y][i].draw_frag = false;
	}
}

void ATetris_Mgr::Load() {
	{
		bool inst[5][5] = {
			{false,false,false,false,false},
			{ false,true,true,false,false},
			{ false,true,true,false,false},
			{ false,false,false,false,false},
			{ false,false,false,false,false}
		};
		memcpy(n_block[0].block_date, inst, sizeof(inst));
		n_block[0].co = FColor(1.0f, 1.0f, 0.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			{false,false,false,false,false},
			{false,false,true,false,false},
			{false,false,true,false,false},
			{false,false,true,false,false},
			{false,false,true,false,false}
		};
		memcpy(n_block[1].block_date, inst, sizeof(inst));
		n_block[1].co = FColor(0.0f, 1.0f, 1.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			 {false,false,false,false,false},
			{false,false,true,false,false},
			{false,true,true,true,false},
			{false,false,false,false,false},
			{false,false,false,false,false}
		};
		memcpy(n_block[2].block_date, inst, sizeof(inst));
		n_block[2].co = FColor(1.0f, 0.0f, 1.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			{false,false,false,false,false},
			{false,false,false,false,false},
			{false,true,true,false,false},
			{false,false,true,true,false},
			{false,false,false,false,false}
		};
		memcpy(n_block[3].block_date, inst, sizeof(inst));
		n_block[3].co = FColor(0.0f, 1.0f, 0.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			 {false,false,false,false,false},
			{false,false,false,false,false},
			{false,false,true,true,false},
			{false,true,true,false,false},
			{false,false,false,false,false}
		};
		memcpy(n_block[4].block_date, inst, sizeof(inst));
		n_block[4].co = FColor(1.0f, 0.0f, 0.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			 {false,false,false,false,false},
			{false,true,false,false,false},
			{false,true,true,true,false},
			{false,false,false,false,false},
			{false,false,false,false,false}
		};
		memcpy(n_block[5].block_date, inst, sizeof(inst));
		n_block[5].co = FColor(1.0f, 0.5f, 0.0f, 1.0f);
	}
	{
		bool inst[5][5] = {
			{false,false,false,false,false},
			{false,false,false,true,false},
			{false,true,true,true,false},
			{false,false,false,false,false},
			{false,false,false,false,false}
		};
		memcpy(n_block[6].block_date, inst, sizeof(inst));
		n_block[6].co = FColor(0.0f, 0.0f, 1.0f, 1.0f);
	}

}