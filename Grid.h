#pragma once

#include "Position.h"
class Grid
{

  Position TopLeft, BottomRight;
  Color Background;
  int Index;
  public:
  
  Grid(Position TL,Position BR, Color c, int index):TopLeft(TL),BottomRight(BR),Background(c)
  {
    Index = index;
  }
  
  int GetIndex()
  {
    return Index;
  }
  
  bool BoxConfirmation(int x, int y)
  {
      return ((x >= TopLeft.x && x <= BottomRight.x) && (y >= TopLeft.y && y <= BottomRight.y));
  }
  
  Position getTopLeft()
  {
    return TopLeft;
  }
    
  Position getBottomRight()
  {
    return BottomRight;
  }
  
};

