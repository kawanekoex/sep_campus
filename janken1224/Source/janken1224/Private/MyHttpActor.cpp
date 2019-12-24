// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHttpActor.h"
#include "Json.h"
#include "Engine.h"


// Sets default values
AMyHttpActor::AMyHttpActor() : Super()
{
    Http = &FHttpModule::Get();
 
}

// Called when the game starts or when spawned
void AMyHttpActor::BeginPlay()
{
    MyHttpCall();
	Super::BeginPlay();
	
}

void AMyHttpActor::MyHttpCall()
{
    TSharedRef<IHttpRequest> Request = Http->CreateRequest();
    Request->OnProcessRequestComplete().BindUObject(this, &AMyHttpActor::OnResponseReceived);
    //This is the url on which to process the request
    Request->SetURL("http://www.kawaneko.shop/kawaneko.shop/sample.php");
    Request->SetVerb("GET");
    Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
    Request->SetHeader("Content-Type", TEXT("application/json"));
    Request->ProcessRequest();
}

// Called every frame
void AMyHttpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyHttpActor::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    //Create a pointer to hold the json serialized data
    TSharedPtr<FJsonObject> JsonObject;

    //Create a reader pointer to read the json data
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

    //Deserialize the json data given Reader and the actual object to deserialize
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        //Get the value of the json object by field name
        int32 recievedInt = JsonObject->GetIntegerField("customInt");

        //Output it to the engine
        GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
    }
}