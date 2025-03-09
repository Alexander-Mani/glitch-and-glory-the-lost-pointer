# Glitch & Glory - The lost pointer




---
title: Naming Conventions
---

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
