#include "grilla.h"

Grilla::Grilla(int ladoCeldaEnPixeles, int xMaximo, int yMaximo)
{
  celda = nullptr;
  tamCeldaPixeles = ladoCeldaEnPixeles;
  maxX = xMaximo;
  maxY = yMaximo;
  celda = new Celda* [maxY * maxX];
  if(celda == nullptr)
  {
    maxX = 0;
    maxY = 0;
    return;
  }
}


int Grilla::getMaxX()
{
  return maxX;
}
int Grilla::getMaxY()
{
  return maxY;
}
int Grilla::getTamCeldaPixeles()
{
  return tamCeldaPixeles;
}
Celda* Grilla::getCelda(int x, int y)
{
  if(x >= maxX || y >= maxY)
    return nullptr;
  return celda[y * maxY + x];
}
Grilla::~Grilla()
{
  for(int i = 0; i < maxY; i++)
    delete [] celda[i];
  delete [] celda;
}
