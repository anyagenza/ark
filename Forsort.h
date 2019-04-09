#include <string>
#include <vector>
#include <list>
#include <queue>
#include <D:/uroki/New/SFML-2.4.2/include/SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
using namespace sf;

class Mapa;
class myvect;
const int size_big1 = 400;
const int size_small1 = 70;

const int size_map1 = 20;

struct for_sort
{
public:
  int i;
  int j;
  int value;
};

 class for_sort_vezha
  {
  public:
    int max_value = 1000;
    int the_most_eff = 20;
    void ini_vezha(std::unique_ptr<Mapa> &);
    void ini_vezha_with_pass(std::unique_ptr<Mapa> &);
    int kl_v[size_map1][size_map1];
    std::list<myvect>::iterator it3;
    int radious;
    for_sort masiv_vezha_big[size_big1];
    void ini_masiv_vezha_big(std::unique_ptr<Mapa> &);
    for_sort masiv_vezha_small[size_small1];
    void ini_masiv_vezha_small(std::unique_ptr<Mapa> &);
    void sort(std::unique_ptr<Mapa> &);
    void sort_swap(std::unique_ptr<Mapa> &, int, int);
    void ini_masiv_vezha_big2(std::unique_ptr<Mapa> &);
  };