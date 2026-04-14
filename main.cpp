#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ObjJuego : public ObjGrilla
{
  private:
    int xPos;
    int yPos;
    char spriteName[32];
  public:
    int getXPos();
    int getYPos();
    char *getSpriteName();
    void setXpos(int num);
    void setYpos(int num);
    void setSpriteName(const char *name);

};

class unit
{
  private:
    int faction;
    int type;
    int movement;
  public:
    int getFaction();
    int getType();
    int getMovement();
    int setFaction();
    int setType();
    int setMovement();
};


int main()
{
  //Esto declara la pantalla
  sf::RenderWindow window(sf::VideoMode({1024, 768}), "SFML 3");
  
  //Acá se declaran objetos que se pueden dibujar con window.draw(objeto);
  const sf::Font font("C:/WINDOWS/FONTS/CAMBRIA.TTC");
  sf::Text text(font, "Gato", 50);  
  const sf::Texture texture("sprite.bmp");
  sf::Sprite sprite(texture);
  sf::Vector2<float> s2Pos(100,200);
  while (window.isOpen())
  {
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
      //Acá se manejan los eventos
      if (event->is<sf::Event::Closed>())
      {
          window.close();
      }
      else if (event->is<sf::Event::KeyPressed>())
      {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
          s2Pos.x -= 32;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
          s2Pos.x += 32;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
          s2Pos.y -= 32;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
          s2Pos.y += 32;
        }
      }
    }
    //Acá le mandas los comandos a la ventana para que dibuje objetos
    window.clear(sf::Color::Blue); 
    sprite.setPosition(s2Pos);
    window.draw(text);
    window.draw(sprite);
    window.display();
  }

  return 0;
}
