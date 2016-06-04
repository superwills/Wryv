#include "Wryv.h"

#include "ResourcesPanel.h"
#include "TextWidget.h"
#include "WryvGameInstance.h"
#include "WryvGameMode.h"

UTexture* ResourcesPanel::GoldTexture = 0;
UTexture* ResourcesPanel::LumberTexture = 0;
UTexture* ResourcesPanel::StoneTexture = 0;

ResourcesPanel::ResourcesPanel( FString name, int pxSize, int spacing ) :
  StackPanel( name, 0 ), Px( pxSize ), Spacing( spacing )
{
  resources = displayedResources = FCost( 0.f, 0.f, 0.f );

  // +-----------------+
  // |G1000 W1000 S1000|
  // +-----------------+
  // The 3 resource types
  StackRight( new ImageHS( "Gold icon", GoldTexture ), VCenter ); // icon
  StackRight( Gold = new TextWidget( FS("%d",displayedResources.Gold) ), VCenter );
  StackRight( new ImageHS( "Lumber icon", LumberTexture ), VCenter );
  StackRight( Lumber = new TextWidget( FS("%d",displayedResources.Lumber) ), VCenter );
  StackRight( new ImageHS( "Stone icon", StoneTexture ), VCenter );
  StackRight( Stone = new TextWidget( FS("%d",displayedResources.Stone) ), VCenter );

  recomputeSizeToContainChildren();
}

void ResourcesPanel::SetValues( FCost res )
{
  resources = res;
}

void ResourcesPanel::Update( float t )
{
  // spent=200, diff=-200
  //    diff = 200 - 400;
  FCost diff = resources - displayedResources;
  diff *= 0.1f; // jump by 10%
  displayedResources += diff;
  Gold->Set( displayedResources.Gold );
  Lumber->Set( displayedResources.Lumber );
  Stone->Set( displayedResources.Stone );
  Reflow();
}


