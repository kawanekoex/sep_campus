// Fill out your copyright notice in the Description page of Project Settings.


#include "StageMgr.h"
#include "Engine/World.h"
#include"Public/Def.h"
#include"Mesh_Block.h"

// Sets default values
AStageMgr::AStageMgr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	block_draw[0][0].draw_frag = true;
}

// Called when the game starts or when spawned
void AStageMgr::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStageMgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	aaa += DeltaTime;
	if (aaa > 1.0f) {
		for (int y = 0; y < STAGE_MAX_Y; y++)
		{
			for (int x = 0; x < STAGE_MAX_X; x++)
			{
				//ê∂ê¨
				if (block_draw[y][x].draw_frag && !block_draw_check[y][x].draw_frag)
				{
					block_draw_check[y][x].draw_frag = true;
					block_draw_check[y][x].co = block_draw[y][x].co;

					AMesh_Block* obj = GetWorld()->SpawnActor<AMesh_Block>(draw_obj);
					obj->index = FVector2Int(x, y);
					obj->c = block_draw_check[y][x].co;
					obj->set();
					obj->SetActorScale3D(FVector(1, 1, 1));
					block_draw_check[y][x].obj = obj;
					obj->SetActorLocation(FVector((1.0f * x) * BLOCK_SIZE, 0.0f, (-1.0f * y) * BLOCK_SIZE));
					//obj->SetActorLocation(FVector(-230.0f, 220.0f, 80.0f));

					/*GameObject obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);

					obj.GetComponent<obj_mgr>().index = new Vector2Int(x, y);
					obj.GetComponent<obj_mgr>().c = block_draw_check[y][x].co;
					obj.transform.localScale = transform.localScale;



					obj.transform.parent = transform;
					obj.transform.localPosition = new Vector3(1.0f * x, -1.0f * y, 0.0f);*/
				}
				//çÌèú
				if (!block_draw[y][x].draw_frag && block_draw_check[y][x].draw_frag)
				{

					block_draw_check[y][x].draw_frag = false;
					GetWorld()->DestroyActor(block_draw_check[y][x].obj);
					/*foreach(Transform child in transform)
					{
						if (child.tag != "Block") continue;
						Vector2Int inst = new Vector2Int(x, y);
						if (frag_2d)
						{
							if (child.GetComponent<sprite_mgr>().index == inst)
							{
								Destroy(child.gameObject);
							}
						}
						else
						{
							if (child.GetComponent<obj_mgr>().index == inst)
							{
								Destroy(child.gameObject);
							}
						}

					}*/
				}
				//êFïœçX
				if (block_draw[y][x].co != block_draw_check[y][x].co)
				{
					block_draw_check[y][x].co = block_draw[y][x].co;
					/*foreach(Transform child in transform)
					{
						if (child.tag != "Block") continue;
						Vector2Int inst = new Vector2Int(x, y);
						if (frag_2d)
						{
							if (child.GetComponent<sprite_mgr>().index == inst)
							{
								child.GetComponent<sprite_mgr>().c = block_draw_check[y, x].co;
							}
						}
						else
						{
							if (child.GetComponent<obj_mgr>().index == inst)
							{
								child.GetComponent<obj_mgr>().c = block_draw_check[y, x].co;
							}
						}

					}*/
				}
			}
		}
	}

}

