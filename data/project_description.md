2 Introduction
You may be familiar with a genre of video games known as JRPG, which means
Japanese Role-playing Game. Japanese Role-Playing Games are often split into
two main gameplay aspects: turn-based battle and overworld travel.
In the turn-based battle, the player has a team of characters fighting another
team of characters, often monsters. The characters can each perform an action
such as Attack, Defend, or a variety of special actions the character possesses,
such as healing an ally.
There may be more gameplay aspects within the games but these are the
common ones. Some notable examples are the Pok´emon games and the Final
Fantasy series. A lesser known example is Guardian’s Crusade, which is my
favourite Playstation game. Another more recent example is Darkest Dungeon.
In order to encode the behaviour of multiple different types of characters,
some form of polymorphism in the code is required. When a character is commanded by the player to attack, there is some function in the code that is called, no matter what kind of character is. The same holds true for the different actions, as well as displaying which actions are available.


3 Turn-based Battle (50%)
Implement a basic turn-based battle system similar to those found in JRPG
games. You can choose the theme of the game and the details of the mechanics,
but a simple point to start at is an extremely basic duel game. The interface
can be simple plain-text, without any fancy formatting or other type of fluff.
Simply provide information, prompt the user, and allow for taking action using
standard in and standard out.
Two entities meet to duel, each with some stats such as Health, Attack,
Defence. The entities take turns making actions, one of which should be to
attack the opposing entity, causing damage to the Health. An example of a
damage mechanic is to compute damage = attacker.attack
defender.defence with some sort of
rounding and subtracting that value from the defender’s health. You are free
to deviate from this example. When one of the entities’ health reaches 0, the
other entity is victorious and the game ends. Again, you are free to describe a
different mechanic, but it must be clear what is the intended behaviour in your
README. Having some pseudo-randomisation in the gameplay is strongly
recommended.
For example:
A wild PIDGEY appears!
You select PIKACHU! Go PIKACHU!
PIKACHU (15/15) | PIDGEY (18/18)
PIKACHU’s turn!
Choose an action.
1. Attack
2. Flee
1
Pikachu uses THUNDERBOLT dealing 10 damage!
PIKACHU (15/15) | PIDGEY (8/18)
PIDGEY’s turn!
PIDGEY uses GUST dealing 6 damage!
PIKACHU (9/15) | PIDGEY (8/18)
PIKACHU’s turn!
Choose an action.
1. Attack
2. Flee
1
PIKACHU uses THUNDERBOLT dealing 12 damage!
PIDGEY has fainted! PIKACHU wins!
You should have many different types of entities which have different behaviours. The simplest form for this is to have different values of their stats, but note that you must implement this difference using inheritance, templates
or variants. The user should be able to select which entities partake in a duel
somehow, for example, using command line arguments or a menu


4 Additions
Here are some suggestions for how you can add on to the project. This is not
an exhaustive list and you are free to do something else which is not mentioned.
Each feature that you add or change from the base should be mentioned in the
README file. Each feature you add will provide a boost to your grade.
Suggestions:
• Multiple entities per team. Can additionally allow the player to configure
the team by picking 3 out of 7 characters or similar.
• Special abilities / more actions based on the entity type. Maybe the
special ability requires charging up within a battle. Ability targeting can
be single target, random target, area of effect, and many more.
• More stats such as mana, power points, energy, or other resources for
actions. There are also different types of health, such as physical health,
hunger, thirst, sanity, and more.
• Distinct damage types and resistances to damage types.
• Richer UI, for example, ASCII art of the entities duelling.
• Overworld map where player can move and have random encounters (duels).
• Persistence with save / load game options.
• Levelling system for characters.
• Equipment and items. You can have different types of equipment that fits
in certain slots.
• Formations, such as those in Darkest Dungeon, where each entity has a
location on the battle area and this affects gameplay.
• Boss encounter. Perhaps the boss is split into different phases or has a
specific rotation of abilities.