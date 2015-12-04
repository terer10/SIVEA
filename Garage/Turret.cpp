#include "Turret.h"

Turret::Turret(TextureManager &_textures,TurretSettings _settings){
    Turret::settings = _settings;
    _texture = _textures.get(Textures::TURRET);
}
sf::Texture &Turret::getTexture(){
    return _texture;
}
