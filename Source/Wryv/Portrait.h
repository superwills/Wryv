#pragma once

#include "Border.h"
#include "ImageBorder.h"
#include "ProgressBar.h"

class AGameObject;

// Portrait of a unit (with border + mini hpbar)
class Portrait : public ImageBorder
{
public:
  AGameObject* Object; // The object related to the portrait
  ProgressBar* hpBar;

  Portrait( FString name, UTexture* tex, float thickness, FLinearColor color );
  void Set( AGameObject* go );
};

