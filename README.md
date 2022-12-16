# DataOrientedSpaceShooter

The ECS system is rarely doing heap allocations and prioritises data organization & manipulation over object-oriented approaches such as inheritance and polymorphism. Components carry most of the data and some helper functions, while the systems are responsible for manipulating the data. The data is also tightly packed into memory, which makes it possible to iterate through the data without having to check for empty memory, this also makes entire cache line's worth of data possible to load at once.

Each system has a signature which is decided by which components that it has registered. If an Entity matches with a system signature it will get loaded into the system's entities array. 

Additionally, the QuadTreeCollision allows for efficient collision checking, as well as the collision mask that uses bitsets and bitwise operators to compare.