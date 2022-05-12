#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
sf::Sprite backgroungSprite;
sf::Texture textureBackground;
sf::Sprite championSprite;
sf::Texture championTexture;
vector<sf::Sprite> wall;
sf::Texture wallTexture;
wallTexture.loadFromFile("wall.png");
for(int i = 0; i < 10; i++){
sf::Sprite temp;
temp.setTexture(wallTexture);
temp.setScale(0.33,0.33);
temp.setPosition(100 + 65 *i, 200);
wall.emplace_back(temp);

}
textureBackground.loadFromFile("grass.png");
championTexture.loadFromFile("guy.png");
backgroungSprite.setTexture(textureBackground);
championSprite.setTexture(championTexture);
backgroungSprite.setScale(5,5);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
window.setFramerateLimit(60);
float x = 0.0;
bool ground = false;
    while (window.isOpen())
     {
    sf::Event event;
      while (window.pollEvent(event))
       {
        if (event.type == sf::Event::Closed)
         {
          window.close();
         }
        if(event.type==sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(ground == true){
                x = -10.0;
                ground = false;


            }
        }
       }
      if(ground ==false){
    x = x + 0.1;
    championSprite.move(0,x);
      }




                  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                      championSprite.move(0,0);

          }
                  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                      championSprite.move(-3,0);
                  }
                  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                      championSprite.move(3,0);
  }
                  if(championSprite.getPosition().x+championSprite.getGlobalBounds().width > 800){
                          championSprite.move(-3,0);
                      }
                      if(championSprite.getPosition().x < 0){
                          championSprite.move(3,0);
                      }
                      if(championSprite.getPosition().y+championSprite.getGlobalBounds().height > 600){
                          championSprite.move(0,-3);
                          ground = true;
                          x = 0;
                      }
                      if(championSprite.getPosition().y < 0){
                          championSprite.move(0,3);

                      }
      for(int i = 0; i <10; i++){
          if(wall[i].getGlobalBounds().intersects(championSprite.getGlobalBounds())){
              if(championSprite.getPosition().x<wall[i].getPosition().x){
                  championSprite.move(-3,0);
              }
              else if(championSprite.getPosition().x>wall[i].getPosition().x){
                  championSprite.move(3,0);
              }
              if(championSprite.getPosition().y<wall[i].getPosition().y){
                  championSprite.move(0,-3);
                  ground = true;
                  x = 0;
              }
              else if(championSprite.getPosition().y>wall[i].getPosition().y){
                  championSprite.move(0,3);
                  x = 0;
              }
              if((championSprite.getPosition().y<wall[i].getPosition().y && ground == true) && !(wall[i].getGlobalBounds().intersects(championSprite.getGlobalBounds()))){
                      ground = false;
          }
          }
      }
      window.clear(sf::Color::Black);
      window.draw(backgroungSprite);
      window.draw(championSprite);
      for(int i = 0; i <10; i++){
          window.draw(wall[i]);
      }

      window.display();
     }

    return 0;
}

