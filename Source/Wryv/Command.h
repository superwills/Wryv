#pragma once

class AGameObject;
#include "Types.h"

// This structure contains a single command for a unit.
// Units can stack these in a series
struct Command
{
  static int64 NextCommandID;

  enum CommandType { Target, GoToGroundPosition, CreateBuilding, RepairBuilding, UseAbility };

  int64 CommandID;          // The numeric ID of the Command (these are in-order)
  int64 FrameID;
  CommandType commandType;  // The type of the command added here
  int64 srcObjectId;        // The ID of the object that this command concerns
  int64 targetObjectId;     // The target object that this command concerns (for Follow, Attack, Build commands)
  FVector pos;              // Location of the command (esp if ground position)

  Command();
  Command( CommandType cmd, int64 iSrcObjectId );
  Command( CommandType cmd, int64 iSrcObjectId, FVector iLocation );
  Command( CommandType cmd, int64 iSrcObjectId, int64 iTargetObjectId );
  Command( CommandType cmd, int64 iSrcObjectId, int64 iTargetObjectId, FVector iLocation );
  bool operator==( const Command& cmd ) {
    return CommandID == cmd.CommandID;
  }
  FString ToString() const;
};