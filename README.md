# Glitch & Glory: 
## The Lost Pointer

A Cyberpunk JRPG.

# For Players

In this turn based JRPG inspired by the Cyberpunk genre and Swords And Sandals the objective is to storm the HQ and defeat the final boss.

To achieve this the you will want to head to the arena to sharpen your game skills, gain EXP and Money so you can increase the parties stats
and buy fancy new equipment from the Ripper and Shop.

The gameplay loop is simple but offers some depth Explore the maps many options while increasing your power all for the final goal
of finally defeating the boss in hq.

On your journey you will get random encounters that can increase or decrease your stats, choose wisely how to deal with these.

If you need a rest and some health back stay a night at the appartments to refuel for the next day of grinding.

The Combat it self is simple but does provide the Player with choices to maximize the chance of success, will you go for the swift
high hit low damage attack or will you gamble on the heavy wind up to deal more damage but leave your self open to dodges and counters,
the choice is yours, you can even try to outsmart your opponents by hacking into there bio-mechanics or you can flee like a coward, everything
is fair play if it means achieving your goal of overthrowing the tyrant.

How fast can you beat the game?

Go ahead give it your best shot!

# For Devs
Glitch & Glory: The Lost Pointer is a simple turn-based JRPG framework designed to demonstrate basic polymorphic gameplay. 
The codebase allows multiple types of entities (both allies and foes), with inheritance or variants to create diversified characters and behaviors. 
It also includes optional features for overworld travel, random encounters, leveling, and more.

## 1. Game Loop
1. Taversal: Player navigates the overworld map with their party to duel, level and buy equipment, untill they are powerfull enough to beat the boss in hq.

2. Dueling: Players select one mercenary character from their party to face off against an enemy. Each character has these stats:
- Max Health (max_hp)
- Health (hp)
- Attack (atk)
- Defense (def)
- Accuracy (acc)
- Evaasion (evade)
- Magic / Hacking Points (magic)
- Critical Hit Chance (crit)

Once enemies are beaten, players gain experience points and money.

## 2. Code Structure
**Overview of the Layered Architecture**

```bash
├── Art
│   └── (Contains art not directly used in the game but for devlopment, and a handy asciiflipper.py)
├── data
│   └── project_description.md
├── debug.h
├── glitch-and-glory.out
├── LogicLayer
│   ├── AttackLogic.cpp
│   ├── AttackLogic.h
│   ├── BattleLogic.cpp
│   ├── BattleLogic.h
│   ├── EncounterLogic.cpp
│   ├── EncounterLogic.h
│   ├── EntityLogic.cpp
│   ├── EntityLogic.h
│   ├── GameLogic.cpp
│   ├── GameLogic.h
│   ├── LogicWrapper.cpp
│   └── LogicWrapper.h
├── main.cpp
├── makefile
├── Models
│   ├── AllEntities.h
│   ├── AllEquipment.h
│   ├── BattleModel.cpp
│   ├── BattleModel.h
│   ├── Entities
│   │   ├── BioEnhancedBerserkerModel.h
│   │   ├── CyberGladiatorModel.h
│   │   ├── ElonoTronPhase1Model.h
│   │   ├── ElonoTronPhase2Model.h
│   │   ├── EnemyModel.h
│   │   ├── EntityModel.cpp
│   │   ├── EntityModel.h
│   │   └── TechnoOracleModel.h
│   ├── Equipment
│   │   ├── ArmorModel.h
│   │   ├── CyberGear
│   │   ├── EquipmentFactory.cpp
│   │   ├── EquipmentFactory.h
│   │   ├── EquipmentModel.h
│   │   ├── ImplantModel.h
│   │   └── WeaponModel.h
│   ├── OverworldModel.cpp
│   ├── OverworldModel.h
│   ├── PartyModel.cpp
│   ├── PartyModel.h
├── TODO.md
└── UILayer
    ├── AsciiHandler.cpp
    ├── AsciiHandler.h
    ├── BattleHandler.cpp
    ├── BattleHandler.h
    ├── EncounterHandler.cpp
    ├── EncounterHandler.h
    ├── IOHandler.cpp
    ├── IOHandler.h
    ├── OverworldHandler.cpp
    ├── OverworldHandler.h
    ├── StoryHandler.cpp
    ├── StoryHandler.h
    ├── UIHandler.cpp
    └── UIHandler.h
```

**Description classes**:

**Logic Layer**

### LogicWrapper
- A container that instantiates and ties together various logic classes such as `BattleLogic`, `EntityLogic`, `GameLogic`, etc.
- Provides high-level access to game logic from one place.

### BattleLogic
- Governs how battles are handled turn by turn.
- Exposes methods for processing player/computer actions (e.g., Attack, Heavy Attack, Flee, Special).
- Manages turn toggling, battle completion checks, and outcomes.

### AttackLogic
- Specifically calculates damage, hit chance, critical hits and other attack specific logic.
- Contains `attack()`, `heavy_attack()`, `calculate_damage()`, and supporting methods for accuracy.

### EncounterLogic
- Handles random or scripted “encounters” outside of direct combat, allowing non-battle events or stat changes.
- Each encounter has a accept and decline, triggered by user choice.

### EntityLogic
- Creates, retrieves, or modifies entity objects party members, enemies and the boss.
- Manages stats, inheritance-based differences, and boss-phase transitions if desired.

### GameLogic
- Manages overworld-level activities: leveling up, awarding money or XP, and “stay the night” healing logic.

**UI Layer**

### IOHandler
- Responsible for raw input/output operations.
  - Reads user input from standard in (or other sources).
  - Prints text to the console and structures the console interface.

### ASCIIHandler
- Specialized utility for loading, storing, and rendering ASCII art.
  - Manages the ASCII strings or files for characters, maps, or special effects.
  - May provide methods to stylize or position ASCII content in the terminal.

### OverworldHandler
- UI or logic helper specifically for overworld navigation and display.
  - Handles user interactions while traveling across maps or exploring hubs.
  - Displays or updates location-based information, including random encounters.

### BattleHandler
- UI for orchestrating battles from a front-end perspective.
  - Interprets user decisions in combat, forwards them to `BattleLogic`, and displays battle states.
  - Could manage turn prompts, show HP bars, or track ephemeral UI feedback (like damage pop-ups).

**Model Layer/ Game data-structures**

### BattleModel
- Holds a single battle’s state.
### PartyModel
- Party composition, level, and XP threshold tracking.
### OverworldModel
- For location and progression details.
- Traversal
### EntityModel (and subclasses) 
- Holds character’s stats and art.
### EquipmentModel (and subclasses)
- Eqiupment stats.
### EquipmentFactory
- Creates ingame armors, weapons and implants.

## 3. Features
1. **Turn-Based Battles:** Each turn, the active character may choose to do a normal attack, heavy attack, special/hack attack, flee, or bribe.
2. **Multiple Entity Types:** CyberGladiator, TechnoOracle, BioEnhancedBerserker, custom enemies, and bosses, using inheritance for distinct stats and behaviors.
3. **Random Encounters:** Optional triggers while traveling in the overworld that can modify stats or offer story flavor.
4. **Leveling & XP:** Defeating foes awards XP and money; leveling up raises stats.
5. **Simple CLI/TUI Interaction:** The game runs as a console application, so no heavy dependencies are needed.

## 4. How to Build & Run
1. Clone or Download the repository.
2. Ensure a modern C++ compiler (C++17 or later).
3. Compile all with make file in the root directory:
```bash
make
```
4. Execute the resulting binary:
```bash
./glitch_and_glory
```

- or Compile and run:
```bash
make run
```


## 5. Standards
- Naming
    - **Classes**: Use `PascalCase`
    - **Variables**: Use `snake_case`
    - **Class Instances**: Use `camelCase`
    - **Methods**: Use `snake_case`
    - **Directories**: Use `PascalCase`
    - **Class Files**: Use `PascalCase`
    - **Other Files**: Use `snake_case`
