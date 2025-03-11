# Glitch & Glory - The lost pointer




---
title: Naming Conventions
---
# TODO / Work deligation
*STANDARDS: [Task][User][branch][Affected files]*

## Phase 1

1. [ ] [Attack Logic][Franz][attack][AttackLogic, WeaponModel.h, EntityLogic(maybe), EntityModel (possibly other Entity models later on)]
    a. ✅ Finna út hvernig við breytum stats á Entities þegar það er ehv attack/defence [done]
        - Búum til methods fyrir entities sem getur breytt values
    b. ✅ Búa til weapon class með mismunandi attack stats [done]
        - EzPz
    c. ❓ Gera ehv simple algo sem gerir þetta fair, mögulega hafa low, med, high attack eins og í sword and sandals, annars er leikurinn 100% random [semi-done]
        - Fór aðeins aðra leið til að einfalda 
            I.  WeaponModel.hit_rate segir til um hvort þú hittir á óvin og 
            II.  WeaponModel.damage segir til um árásagetu þína. Damage er reiknað () 
    

2. [ ] [Battle Logic][Lexi][battles][Models*,]
 a. Komast inn í bardaga [solved WIP]
 b. Finna út hvernig við munum skiptast á milli characters [bool after actions][NOT Started]
 c.  Controls, finna út hvað er hægt að gera í Battle [Attack, Special, Forfit... yet to be thought out][NOT Started]
 d. Prenta win/loss skilaboð og exita leik [NOT Started]

## Phase 2

1. [ ] [Map / Storyline ][Tommi][game-loop][...]
 a. Semja smá söguþráð, ehv start skilaboð kannski og svo hver er tilgangurinn með leiknum, hvað er að frétta
 b. Finna út hvernig mappið mun líta út, hvernig ætlum við að display-a það og hvort við ætlum
 c. Transition til og frá battles
 d. Hvað verður hægt að gera, kaupa potions, weapons or smth? Finna útúr því


# Naming Conventions

Consistent naming conventions improve code readability and maintainability. Below are the standard naming conventions to follow in C++ projects.

## General Conventions

- **Classes**: Use `PascalCase`
- **Variables**: Use `snake_case`
- **Class Instances**: Use `camelCase`
- **Methods**: Use `snake_case`
- **Directories**: Use `PascalCase`
- **Class Files**: Use `PascalCase`
- **Other Files**: Use `snake_case`


## Directory and File Naming

Organize your directories and files using the proper naming conventions:

```sh
# Example directory and file structure
ProjectRoot/
└── UserManagement/  # Directory in PascalCase
    ├── UserAccount.h  # Class file in PascalCase
    ├── UserAccount.cpp
    ├── user_helpers.h  # Other file in snake_case
    └── user_helpers.cpp

```

Following these conventions ensures a structured and maintainable C++ codebase.




# PA4 - Notes from class for development

## Useful Header Libraries from class [10.03.2025]
- [Github Repo with header-only c++ libraries](https://github.com/p-ranav/awesome-hpp)
- [Github Repo fyrir TUI art (insane)](https://github.com/ArthurSonzogni/FTXUI)
_____________________________________

## Possibly Helpful
- Templating (one of requirements)
    - Type Alias
- Variants (one of requirements)
- Use compile-time checking such as `constexpr`
_____________________________________

## Project structure

### Game Ideas
- Maybe a final fantasy copy?
- Leveling system?

### Structure Ideas
Franz:
- Set up structure with templated values 
    - This will help us to set up test
    - Helps with unifying structure of program with all members
    - Possibly saves time long term, reducing the need to refactor code
_____________________________________

## Project Instructions

### Game Attributes
- At least three entities
    - The player should be able to choose from 3-7 entities
    - Each entity should have their own stats, commands etc.


### README requirements
- Needs to be designed around the player and developer going over it
- Player
    - Needs to have a feel of the game and controls by reading the README.
- Developer:
    - Needs to understand the structure of the code from the README.


### What can we use?
- Any C++ version we like
- We can include any library we want, but we need to state it in the README
_____________________________________
