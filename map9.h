#include <string>
#include <vector>
#include <list>
#include <queue>
#include <D:/uroki/New/SFML-2.4.2/include/SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
using namespace sf;

const int size_big = 400;
const int size_small = 70;
const int kilkist_kletok = 10;
const int kilkist_hero = 3;
const int size_map = 20;

class Singleton;
class myvect;
class Enemy;
class for_sort_vezha;

class Mapa
{
public:
  int HEIGHT_MAP;
  int WIDTH_MAP;
  int anim_lich;
  int **mas_chisel = new int *[size_map];
  Sprite **mas = new Sprite *[size_map];
  Image map_image;
  Texture map;
  Sprite s_map;

  void draw(std::unique_ptr<Mapa> &, RenderWindow &);
  void write(std::unique_ptr<Mapa> &, std::string);
  void read(std::unique_ptr<Mapa> &);
  std::unique_ptr<for_sort_vezha> vezha;

  //public:
  Enemy *mas_enemy;
  Mapa(int **masiv_c, int he, int wi, size_t, Singleton &);
  ~Mapa();
  void draw_all_enemy(std::unique_ptr<Mapa> &, RenderWindow &window);
  void call_different_funk(std::unique_ptr<Mapa> &, size_t, Singleton &);
};
