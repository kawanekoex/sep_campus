// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJanken.h"
#include "Json.h"
#include "Engine.h"

// Sets default values
AMyJanken::AMyJanken()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Http = &FHttpModule::Get();             //http�N���X�Z�b�g
}

// Called when the game starts or when spawned
void AMyJanken::BeginPlay()
{
	Super::BeginPlay();

}

void AMyJanken::MyHttpCall(int you)
{

	//// Json�f�[�^�̍쐬
	//TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	//JsonObject->SetStringField("myText", "1");

	//// OutputString��Json�����o��
	//FString OutputString;
	//TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	//FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	FString ur = "http://www.kawaneko.shop/kawaneko.shop/sample.php";

	//URL�ɒl�ǉ�
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

	//���N�G�X�g
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

	}
	request_frag = false;
}
