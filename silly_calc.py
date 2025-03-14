import random

class Entity:
    def __init__(self, name, max_hp, atk, defense, evade):
        """
        Initialize an entity with a name, attack, defense, and evasion.
        """
        self.name = name
        self.max_hp = max_hp
        self.atk = atk
        self.defense = defense
        self.evade = evade

    def attack(self, target):
        """
        Simulate an attack on the target entity.
        
        The chance to hit is determined by the target's evasion.
        If the attack hits (random roll <= hit chance), damage is calculated as:
            damage = attacker's atk - target's defense
        Negative damage is clamped to 0.
        
        Parameters:
            target (Entity): The entity being attacked.
        
        Returns:
            int: The amount of damage dealt (0 if missed).
        """
        hit_chance = 100 - target.evade  # e.g., if evade is 50, hit chance is 50%
        hit_chance = max(hit_chance, 10)

        hit_roll = random.randint(1, 100)
        hit_roll = 0
        if hit_roll <= hit_chance:
            damage = int((self.atk*100) / target.defense)
            damage = max(damage, 10)
            print(f"{self.name} attacks {target.name} and hits (roll: {hit_roll} <= {hit_chance}) for {damage} damage.")
            return damage
        else:
            print(f"{self.name} attacks {target.name} but misses (roll: {hit_roll} > {hit_chance}).")
            return 0

    def __str__(self):
        """
        Return a string representation of the entity.
        """
        return f"{self.name}: ATK={self.atk}, DEF={self.defense}, EVADE={self.evade}"

def main():
    # Create instances of entities with initial stats.
    cyber_entity = Entity("Cyber Entity", max_hp=1000, atk=100, defense=10, evade=140)
    bio_entity   = Entity("Bio Entity", max_hp=1000, atk=100, defense=10,  evade=50)
    techno_entity = Entity("Techno Entity", max_hp=1000, atk=100, defense=10, evade=60)

    # Store entities in a list (optional, for iterating over them)
    entities = [cyber_entity, bio_entity, techno_entity]

    # Display each entity's stats
    print("Entities:")
    for entity in entities:
        print(entity)

    # Test attack formulas by simulating a few attacks
    print("\nSimulating Attacks:")
    # Example: Cyber Entity attacks Bio Entity
    print("\nCyber Entity")
    cyber_entity.attack(bio_entity)
    cyber_entity.attack(cyber_entity)
    # Bio Entity attacks Techno Entity
    print("\nBio Entity")
    bio_entity.attack(cyber_entity)
    bio_entity.attack(techno_entity)
    # Techno Entity attacks Cyber Entity
    print("\nTechno Entity")
    techno_entity.attack(cyber_entity)
    techno_entity.attack(bio_entity)

if __name__ == "__main__":
    main()
