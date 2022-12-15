#include "ECS.h"
#include <queue>
#include <array>
#include <assert.h>

class EntityManager
{
public:

	EntityManager();
	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	void SetSignature(Entity entity, Signature signature);
	Signature GetSignature(Entity entity);
	
private:
	std::queue<Entity> availableEntitiesId{};

	std::array<Signature, MAX_ENTITIES> signatures{};
	uint32_t livingEntityCount{};
};
