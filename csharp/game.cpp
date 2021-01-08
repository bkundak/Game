#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>

#include "prompt.h"
#include "menu.h"
#include "game.h"
#include "data.h"

namespace blur
{

    int RandomRange(int minInclusive, int maxInclusive)
    {
        std::random_device device;
        std::mt19937 generator(device());
        std::uniform_int_distribution<int> distribution(minInclusive, maxInclusive);
        return distribution(generator);
    }

    Character &RandomMonster(GameState &game)
    {
        auto index = RandomRange(0, game.monsters.size() - 1);
        return game.monsters[index];
    }

    GameState Create(std::string playerName)
    {
        GameState game;
        game.player = Character{playerName, Role::hero, 100, 10, 1};
        game.state = State::main;
        game.monsters.push_back(Character{"Monster", Role::monster, 100, 1, 1});
        game.monsters.push_back(Character{"Ninja", Role::monster, 100, 1, 1});

        return game;
    }

    // Shop
    State RestoreHealth(Character &character)
    {
        character.health = 100;
        blur::Printf(Messages[Message::HEALTH_RESTORED], character.health);
        return State::shop;
    }

    State UpgradeArmor(Character &character)
    {
        character.armor += 2;
        blur::Printf(Messages[Message::UPGRADE_ARMOR], character.armor);
        return State::shop;
    }

    State UpgradeWeapon(Character &character)
    {
        // if(character.gold > upgradeWeaponCost) {}
        character.attack += 1;
        blur::Printf(Messages[Message::UPGRADE_WEAPON], character.attack);
        return State::shop;
    }

    State ShowStats(const Character &character)
    {
        blur::Printf("Health: %d\nArmor: %d\nAttack: %d\n", character.health, character.armor, character.attack);
        return State::shop;
    }

    // Forrest
    bool Attack(Character &attacker, Character &target)
    {
        auto damageTaken = RandomRange(1, 1 + attacker.attack);
        blur::Printf(Messages[Message::ATTACK], attacker.name.data(), target.name.data(), damageTaken);
        target.health -= damageTaken;
        blur::Printf(Messages[Message::HAS_HEALTH_REMAINING], target.name.data(), target.health);
        return (target.health <= 0);
    }

    State Attack(GameState &game)
    {
        auto enemy = RandomMonster(game);
        if (Attack(game.player, enemy))
        {
            blur::Printf(Messages[Message::HAS_DIED], enemy.name.data());
        }
        if (Attack(enemy, game.player))
        {
            // restart game
            blur::Printf(Messages[Message::YOU_DIED], game.player.name.data());
        }

        //  Timing stuff inbetweeen attacks and repeating attacks per turn
        return State::forrest;
    }

    State Retreat(Character &player)
    {
        blur::Printf(Messages[Message::RETREATING]);
        // 50% chance to take a random amount of damage while retreating
        return State::main;
    }
} // namespace blur

int main(int argc, char **argv)
{
    using namespace blur;

    auto name = blur::InputString(Messages[Message::INPUT_NAME]);
    auto game = blur::Create(name);

    auto forrest_menu = make_menu(
        Option{"Attack", [&game] { return Attack(game); }},
        Option{"Retreat", [&game] { return Retreat(game.player); }});

    auto shop_menu = make_menu(
        Option{"Restore health", [&game] { return RestoreHealth(game.player); }},
        Option{"Upgrade armor", [&game] { return UpgradeArmor(game.player); }},
        Option{"Upgrade weapon", [&game] { return UpgradeWeapon(game.player); }},
        Option{"Show character stats", [&game] { return ShowStats(game.player); }},
        Option{"Leave shop", [] { return State::main; }});

    auto main_menu = make_menu(
        Option{"Enter forrest", [] { return State::forrest; }},
        Option{"Enter shop", [] { return State::shop; }},
        Option{"Exit game", [] { return State::exit; }});

    State state = State::main;

    do
    {
        if (state == State::main)
        {
            state = main_menu.prompt("Where to?");
        }
        else if (state == State::forrest)
        {
            state = forrest_menu.prompt("What do you want to do?");
        }
        else if (state == State::shop)
        {
            state = shop_menu.prompt("What can i get for you?");
        }
    } while (state != State::exit);

    return 0;
}