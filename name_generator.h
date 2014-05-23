#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <random>
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <string>

template<
    class Engine = std::default_random_engine
>
class name_generator
{
    std::random_device rd;
    Engine engine;
    std::uniform_int_distribution<> dist{0, 5};
    std::map<int, std::string> names;
    int teams[6] = {0};
    int index = 0;

    template<class... Args>
    void init_map(Args&&...);

    void init_teams();
public:
    template<class... Args>
    name_generator(Args&&...);

    template<class E>
    friend std::ostream& operator<<(std::ostream&, name_generator<E>&);
};

template<class Engine>
template<class... Args>
name_generator<Engine>::name_generator(Args&&... args)
    : engine(rd())
{
    init_map(args...);
    init_teams();
}

template<class Engine>
template<class... Args>
void name_generator<Engine>::init_map(Args&&... args)
{
    names.insert({std::make_pair(index++, args)...});
}

template<class Engine>
void name_generator<Engine>::init_teams()
{
    int indicies[6] = {0, 1, 2, 3, 4, 5};

    for (int index, counter = 0;;)
    {
        index = dist(engine);
        if (indicies[index] != -1)
        {
            teams[counter] = index;
            indicies[index] = -1;
            ++counter;
        }
        if (counter == 6)
        {
            break;
        }
    }
}

template<class E>
std::ostream& operator<<(std::ostream& os, name_generator<E>& gen)
{
    std::cout << "How many teams, 2 or 3?" << std::endl;
    int answer;

    if (!(std::cin >> answer))
        return os;

    if (answer == 2)
    {
        /*output teams. First 3 are team 1 + second 3 are team 2*/
        os << "Team 1:" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            os << '\t' << gen.names[gen.teams[i]] << std::endl;
        }
        os << std::endl << "Team 2:" << std::endl;
        for (int i = 3; i < 6; i++)
        {
            os << '\t' << gen.names[gen.teams[i]] << std::endl;
        }
        os << std::endl;
    }
    else if (answer == 3)
    {
        os << "Team 1:" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            os << '\t' << gen.names[gen.teams[i]] << std::endl;
        }
        os << std::endl << "Team 2:" << std::endl;
        for (int i = 2; i < 4; i++)
        {
            os << '\t' << gen.names[gen.teams[i]] << std::endl;
        }
        os << std::endl << "Team 3:" << std::endl;
        for (int i = 4; i < 6; i++)
        {
            os << '\t' << gen.names[gen.teams[i]] << std::endl;
        }
    }
    else
    {
        os << "Please enter either 2 or 3 only." << std::endl;
    }
    return os;
}

#endif // NAME_GENERATOR_H
