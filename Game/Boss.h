#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"


class Boss : public Characters
{
public:
  Boss(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* enemyTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture);
  ~Boss();

  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow& window) override;
  void bossIntelligence(sf::Vector2f distance);

  sf::Vector2f getPosition() {return body.getPosition(); };

  Collider getCollider() { return Collider(body); };
  void onCollision(sf::Vector2f direction);


  void CheckIfHit(Bullet & bullet);
  std::vector<Bullet> bulletArray;
  bool bossActivated{ false };
  
int lives {15};
private:
  Animation animation;
  bool faceRight{ true };
  bool isFiring{ false };
  bool closeEnough{ false };
  bool passiveMode{true};
  int row{0};
  double rngNumCanJump{0};
  
  Bullet bullet;
  float gunPlacementX{ body.getPosition().x + 60 };
  float reloadTime{0};
  
  sf::Vector2f velocity;
  bool canJump;

  int hitDurationMin{ 0 };
  int hitDurationMax{ 15 };

};

#endif
