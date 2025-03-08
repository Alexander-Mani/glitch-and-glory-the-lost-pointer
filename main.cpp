#include "./models/EntityParentModel.h"
#include <iostream>
#include <vector>

int main() {
    TechnoOracle oracle;
    CyberGladiator gladiator;
    BioEnhancedBerserker berserker;

    std::vector<Entity*> party { &oracle, &gladiator, &berserker };

    for (auto* e : party) {
        e->displayStats();
    }

    return 0;
}
