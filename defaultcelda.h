#ifndef DEFAULTCELDA_H
#define DEFAULTCELDA_H
  
  #include"celda.h"
  class DefaultCelda : public Celda
  {
    private:
      sf::Sprite sprite;
    public:
      DefaultCelda(int x, int y, int costo, sf::Texture &tex);
      sf::Sprite getSprite();
      void render(sf::RenderWindow &window, int ladoCeldaEnPixeles);
      ~DefaultCelda();
  };

#endif
