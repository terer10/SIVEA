#ifndef TURRET_H
#define TURRET_H
#include "../ResourceManager.h"
typedef struct{
    float firerate = 0;
    float torque = 0;
}TurretSettings;
class Turret{
    public:
        Turret(TextureManager &_textures,TurretSettings _settings);
        sf::Texture &getTexture();
        TurretSettings settings;
    private:
        sf::Texture _texture;
};

#endif // TURRET_H
