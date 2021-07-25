#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include<iostream>

enum class Direction{E, W, N, S, NE, NW, SE, SW};

inline std::ostream& operator<<(std::ostream & os, Direction & dir)
{
  switch (dir) {
    case Direction::E :
      os << "south";
      break;
    case Direction::W :
      os << "West";
      break;
    case Direction::S:
      os << "south";
      break;
    case Direction::N:
      os << "North";
      break;
    case Direction::NE :
      os << "north east";
      break;
    case Direction::NW :
      os << "north west";
      break;
    case Direction::SE:
      os << "south east";
      break;
    case Direction::SW:
      os << "South west";
      break;
    
  }
  return os;
}

#endif 