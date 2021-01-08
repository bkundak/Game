#pragma once

struct Message
{
    enum
    {
        HEALTH_RESTORED,
        UPGRADE_ARMOR,
        UPGRADE_WEAPON,
        ATTACK,
        HAS_HEALTH_REMAINING,
        HAS_DIED,
        YOU_DIED,
        RETREATING,
        INPUT_NAME
    };
};

std::array<const char *, 10> Messages = {{
    "Health restored to: %d\n",
    "Armor increased to: %d\n",
    "Attack increased to: %d\n",
    "%s attacking %s for %d damage.\n",
    "%s has %d health remaining.\n",
    "%s has died.\n",
    "You have died.\n",
    "Retreating\n",
    "What's your name?"
}};
