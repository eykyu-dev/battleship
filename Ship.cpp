//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"

Ship::Ship(point originPoint, direction o, int l){
  point temp;
  temp = originPoint;
  origin = originPoint;
  orientation = o;
  length = l;
  points.add(origin);
  for(int i = 0; i < length-1; i++){
    if(orientation == HORIZONTAL){
      temp.setX(temp.getX() + 1);
      points.add(temp);
    }
    else if(orientation == VERTICAL){
      temp.setY(temp.getY()+ 1);
      points.add(temp);
    }
  }
}

Ship::Ship(const Ship& s){
  origin = s.origin;
  orientation = s.orientation;
  length = s.length;

  //copys both hits and points
  for(int i = 0; i < s.points.getSize(); i++){
    points.add(s.points[i]);
  }
  for(int i = 0; i < s.hits.getSize(); i++){
    hits.add(s.hits[i]);
  }
}


bool Ship::containsPoint(const point& p) const{
  for(int i = 0; i < length; i++){
    if(points.contains(p)){
      return true;
    }
    else{
      return false;
    }
  }
  return false;
}

bool Ship::collidesWith(const Ship& s) const{
  for(int i = 0; i < length; i++){
    for(int c = 0; c < length; c++){
      if(points.get(i) == s.points.get(c)){
        return true;
      }
    }
  }
  return false;
}


void Ship::shotFiredAtPoint(const point& p){
  if(containsPoint(p)){
    hits.add(p);
  }
}

bool Ship::isHitAtPoint(const point& p){
  if(containsPoint(p)){
    return true;
  }
  else{
    return false;
  }
}


int Ship::hitCount() const{
  return hits.getSize();
}

const Ship& Ship::operator=(const Ship& s){
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;

  for(int i = 0; i < s.points.getSize(); i++){
    points.add(s.points[i]);
  }
  for(int i = 0; i < s.hits.getSize(); i++){
    hits.add(s.hits[i]);
  }
	return *this;
}

bool Ship::isSunk() {
  if(length == hits.getSize()){
    return true;
  }
  else{
	  return false;	
  }
}