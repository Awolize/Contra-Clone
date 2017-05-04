#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Characters : public Entity
{
public:
	Characters(float health, float attackDamage, float movementSpeed, float jumpHeight,
		sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
	~Characters();

	// Var
	float health{ 100.0f };
	float attackDamage{ 100.0f };
	float movementSpeed{ 100.0f };
	float jumpHeight{ 10.0f };
};

#endif


/*
struct vehicle {
	virtual std::string lineage() const { return "vehicle"; }
};
struct aircraft : vehicle {
	typedef vehicle base;
	virtual std::string lineage() const { return base::lineage() + "--aircraft"; }
};
struct biplane : aircraft {
	typedef aircraft base;
	virtual std::string lineage() const { return base::lineage() + "--biplane"; }
};
struct nieuport17 : biplane {
	typedef biplane base;
	virtual std::string lineage() const { return base::lineage() + "--nieuport17"; }
};
int main() {
	biplane b;
	aircraft const & a = b;
	std::cout << a.lineage() << std::endl;
}
*/