// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJanken.h"
#include "Json.h"
#include "Engine.h"

// Sets default values
AMyJanken::AMyJanken()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Http = &FHttpModule::Get();             //httpクラスセット
}

// Called when the game starts or when spawned
void AMyJanken::BeginPlay()
{
	Super::BeginPlay();

}

void AMyJanken::MyHttpCall(int you)
{

	//// Jsonデータの作成
	//TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	//JsonObject->SetStringField("myText", "1");

	//// OutputStringにJson書き出し
	//FString OutputString;
	//TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	//FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	FString ur = "http://www.kawaneko.shop/kawaneko.shop/sample.php";

	//URLに値追加
	ur += FString("?");
	ur += FString("you=");
	if (you == 0) {
		ur += FString("0");
	}
	else if (you == 1) {
		ur += FString("1");
	}
	else if (you == 2) {
		ur += FString("2");
	}

	//リクエスト
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyJanken::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL(ur);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	// Request->SetContentAsString(OutputString);
	Request->ProcessRequest();
	request_frag = true;
}

//http://www.kawaneko.shop/kawaneko.shop/sql.php
void AMyJanken::MyHttpCall2()
{
	FString ur = "http://www.kawaneko.shop/kawaneko.shop/sql.php";

	//リクエスト
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyJanken::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL(ur);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	// Request->SetContentAsString(OutputString);
	Request->ProcessRequest();
	request_frag = true;
}


void AMyJanken::MyHttpCall3()
{

	//// Jsonデータの作成
	//TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	//JsonObject->SetStringField("myText", "1");

	//// OutputStringにJson書き出し
	//FString OutputString;
	//TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	//FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	FString ur = "http://www.kawaneko.shop/kawaneko.shop/push.php";

	//URLに値追加
	ur += FString("?");
	ur += FString("name=");
	ur += player.name;
	ur += FString("&");
	ur += FString("score=");
	ur += FString::FromInt(player.combo);
	
	player.combo = 0;

	//リクエスト
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AMyJanken::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL(ur);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	// Request->SetContentAsString(OutputString);
	Request->ProcessRequest();
	request_frag = true;
}



// Called every frame
void AMyJanken::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyJanken::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		int32 req_t = JsonObject->GetIntegerField("req_t");
		if (req_t == 0) {
			computer = JsonObject->GetIntegerField("computer");
			if (computer == 0) {
				computer_s = FString(TEXT("gu-"));
			}
			else if (computer == 1) {
				computer_s = FString(TEXT("tyoki"));
			}
			else if (computer == 2) {
				computer_s = FString(TEXT("pa-"));
			}
			mes = JsonObject->GetStringField("message");
			if (mes == FString("win")) {
				player.combo++;
			}
			else if (mes == FString("loss")) {
				MyHttpCall3();
			}

		}
		else {
			use_rank[0].name = JsonObject->GetStringField("name0");
			use_rank[0].combo = JsonObject->GetIntegerField("score0");
			use_rank[1].name = JsonObject->GetStringField("name1");
			use_rank[1].combo = JsonObject->GetIntegerField("score1");
			use_rank[2].name = JsonObject->GetStringField("name2");
			use_rank[2].combo = JsonObject->GetIntegerField("score2");
			use_rank[3].name = JsonObject->GetStringField("name3");
			use_rank[3].combo = JsonObject->GetIntegerField("score3");
			use_rank[4].name = JsonObject->GetStringField("name4");
			use_rank[4].combo = JsonObject->GetIntegerField("score4");
			UE_LOG(LogTemp, Warning, TEXT("call"));
		}
	}
	request_frag = false;
	UE_LOG(LogTemp, Warning, TEXT("call"));
}
