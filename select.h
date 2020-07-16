bool turn(Hero *hero, Ninja *ninja, Monster *monster)
{
    int s;
    char flag;

    std::cout << "Who do you want to attack" << std::endl;
    std::cout << "For attack to ninja press 1" << std::endl;
    std::cout << "For attack to monster press 2" << std::endl;

    std::cin >> s;
    if (s = 1)
    {
        hero->attack(*ninja); //hero atacks to ninja
        ninja->attack(*hero); //ninja atacks to hero
    }
    else if (s = 2)
    {
        hero->attack(*monster); //again hero attack to monster
        monster->attack(*hero); //monster atacks to hero
    }

    std::cout << "Are you done?" << std::endl;
    std::cin >> flag;

    if (flag == 'd')
    {
        return false;
    }
    else
    {
        return true;
    }
}