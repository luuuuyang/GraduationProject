// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperAICharacter.h"
#include "Widgets/HealthWidget.h"

APaperAICharacter::APaperAICharacter()
{
	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidgetComponent"));
}

void APaperAICharacter::BeginPlay()
{
	Super::BeginPlay();

	UHealthWidget* HealthWidget = Cast<UHealthWidget>(HealthWidgetComponent->GetUserWidgetObject());

	if (IsValid(HealthWidget))
	{
		HealthWidget->InitializeHealthWidget(HealthComponent->GetCurrentHealth(), HealthComponent->GetMaxHealth());
		HealthWidget->SetVisibility(ESlateVisibility::Hidden);
		HealthComponent->OnCurrentHealthChanged.BindUFunction(this, "OnHurt");
		HealthComponent->OnDeath.BindUFunction(this, "OnDeath");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GetUserWidgetObject Failure"))
	}
}

void APaperAICharacter::OnHurt(int32 NewCurrentHealth)
{
	UHealthWidget* HealthWidget = Cast<UHealthWidget>(HealthWidgetComponent->GetUserWidgetObject());
	if (!HealthWidget->IsVisible())
	{
		HealthWidget->SetVisibility(ESlateVisibility::Visible);
	}
	HealthWidget->OnCurrentHealthChanged(NewCurrentHealth);
}

void APaperAICharacter::OnDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("OnDeath"))
	Destroy();
}