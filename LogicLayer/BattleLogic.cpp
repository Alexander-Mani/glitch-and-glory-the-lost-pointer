#include "BattleLogic.h"
#include <iostream>

BattleLogic::BattleLogic() {
    this->attack_options = {"attack", "rest"};
    // Constructor left empty for simplicity.
}

int BattleLogic::calculate_damage(EntityModel* attacker, EntityModel* defender) {
    // Simple damage calculation: attacker's attack minus defender's defense.
    int damage = attacker->get_atk() - defender->get_def();
    
    // Make sure damage is not negative.
    if (damage < 0) {
        damage = 0;
    }
    
    return damage;
}

void BattleLogic::perform_attack(EntityModel* attacker, EntityModel* defender) {
    // Calculate how much damage to deal.
    int damage = calculate_damage(attacker, defender);
    
    cout << "\n----- BEFORE TAKE_DAMAGE() -----\n";
    
    cout << "Test";
    
    cout << "\n----- AFTER TAKE_DAMAGE() -----\n";
    // If your EntityModel supports modifying HP (like a take_damage method),
    // you could call that here instead of just printing.
    // defender->take_damage(damage);
}
