#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <iostream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
namespace Textures{
    enum ID{
        CAR,
        SPORTS_CAR,
        TURRET,
        ROAD
    };
}
namespace Fonts{
    enum ID{
        FONT
    };
}
template<typename Resource,typename ID> class ResourceManager{
    public:
        void load(const std::string &path,ID id);{
            std::unique_ptr<Resource> res(new Resource);
            res->loadFromFile(path);
            _map.insert(std::make_pair(id,std::move(res)));
            std::cout << "Loading " << path << "..." << std::endl;
        }
        Resource &get(ID id){
            return *_map[id];
        }
    private:
        std::map<ID,std::unique_ptr<Resource>> _map;
};
typedef ResourceManager<sf::Texture,Textures::ID> TextureManager;
typedef ResourceManager<sf::Font,Fonts::ID> FontManager;

#endif // RESOURCEMANAGER_H
