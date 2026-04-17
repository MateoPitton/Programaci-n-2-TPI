#include <cstdio>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "grilla.h"
#include "defaultcelda.h"

/*
class AdminTextura
{
  private:
    sf::texture tex[10]; //por ahora no más de 10 terrenos
    char tipoCelda[10];
  public:
    Admin
    
};
*/

int cargarMapa(Grilla &grilla, const char* nomArch, sf::Texture *tex)
{
  const int tamFila = grilla.getMaxX();
  int i = 0;
  char tipoCelda; 
  int error = 0;
  FILE *archMapa = nullptr;
  archMapa = fopen(nomArch, "rb");
  if(archMapa == nullptr)
  {
    error = -1;
    return error;
  }
  while(fread(&tipoCelda, 1, 1, archMapa) && (i < (grilla.getMaxX() * grilla.getMaxY())))
  {
    //printf("celda: %x %ld\n", tipoCelda, ftell(archMapa));
    switch(tipoCelda)
    {
      case '\n':
      case '\r':
        break;
      case '0':
        grilla.setCelda(new DefaultCelda(i % tamFila, i / tamFila, 255, tex[0]));
        i++;
        break;
      default:
        i++;
    }
  }
  error = fclose(archMapa);
  if(error)
  {
    return error;
  }
  
  return 0;
}

int main()
{
  int err;
  //Esto declara la pantalla
  sf::RenderWindow window(sf::VideoMode({1024, 768}), "SFML 3");
  sf::Texture texCelda[10];
  err = texCelda[0].loadFromFile("Tiles/defaulttile.bmp");
  if(!err)
    return -1;
  Grilla tablero(64, 4, 4);
  cargarMapa(tablero, "testmap.txt",texCelda);
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
          
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
         
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
        
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
       
        }
      }
    }
    //Acá le mandas los comandos a la ventana para que dibuje objetos
    window.clear(sf::Color::Blue); 
    tablero.render(window);
    window.display();
  }

  return 0;
}
