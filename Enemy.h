#include <string>
#include <vector>
#include <list>
#include <queue>
#include <D:/uroki/New/SFML-2.4.2/include/SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
using namespace sf;

class myvect
{
public:
  int x;
  int y;
};

class Mapa;

class Enemy
  {
  public:
    //Enemy();
    int flag = 0;
    Image hero_image;
    Texture hero;
    Sprite s_hero;
    int **visited = new int *[size_map];
    int **path = new int *[size_map];
    int **path_chisel = new int *[size_map];
    std::list<myvect> new_pass2;
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int x;
    int y;
    std::queue<int> plan;
    std::list<myvect>::iterator it_x;
    std::list<int>::iterator it;
    std::list<myvect>::iterator it2;
    std::list<myvect>::iterator it_for_hero;
    std::list<myvect>::iterator it_y;
    std::list<myvect>::iterator it_x_pop;
    std::list<myvect>::iterator it_y_pop;
    std::list<myvect>::iterator it_dod;
    void inihero(std::unique_ptr<Mapa> &, int, size_t, Singleton &);
    void hero_draw(std::unique_ptr<Mapa> &, RenderWindow &, int);
    void hero_draw1(std::unique_ptr<Mapa> &, RenderWindow &, int, int);
    void hero_k(std::unique_ptr<Mapa> &, RenderWindow &, int **, int);
    void find_path(std::unique_ptr<Mapa> &, int, int, int);
    void restor_path(std::unique_ptr<Mapa> &, int);
    void ini_pass(std::unique_ptr<Mapa> &, int);
    void draw_pass(std::unique_ptr<Mapa> &, int);
    void ini_pass_insert(std::unique_ptr<Mapa> &, int, int, int);
    void find_path_push(std::unique_ptr<Mapa> &, int, int, int, int, int);
    void draw_pass_push(std::unique_ptr<Mapa> &, int, myvect, int, int);
    void draw_pass_case(std::unique_ptr<Mapa> &, int, myvect);
    void pass_reverse(std::unique_ptr<Mapa> &, int, myvect);
    void pass_ini_end(std::unique_ptr<Mapa> &, int, myvect);
    void animation(std::unique_ptr<Mapa> &, RenderWindow &, int, int, int);
    void hero_draw_change_iter(std::unique_ptr<Mapa> &, RenderWindow &, int);
    void hero_draw_for_start_track(std::unique_ptr<Mapa> &, RenderWindow &, int);
    void hero_draw_after_anim(std::unique_ptr<Mapa> &, RenderWindow &, int, int);
  };