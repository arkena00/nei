#include <iostream>

using namespace std;

class entity;

class ability;

class concept
{
    name;

    type sense_observable abstract composition;
    understanding_level 0.9;
    sense_buffer_list;
    virtual_representation;
};

class atomic_concept
{
    entity;
};

class atomic_ability
{
    compare();
    analyse(sens_buffer);
};

analyse sense buffer loop
    check sense parameters
    check buffer entities
    process atomic operation (comp xor and)
            operation with sense buffer & current buffer
            operation with sense buffer & other buffer
            operation with sense buffer & concepts sense representation
            check results constness
            ex : entity view_sense representation = 00 XX 00 xor 00 32 00 \ 00 10 00 21 00 54 00

    search atomic concepts

class sense
{
    buffer;
};

class view_sense : sense
{
    lookat(x, range)
};


class interaction;
{
    entityA
    entityB
};



class neia
{
    environment; // 1D

    entity_sense sense; // entity_sense : view_sense, sound_sense // neya.lookat() // inherit from view_sense
    ability[];

    // abstract
    concept[];

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}



class environment;
00 00 00 11 00 00 00 00 11 11 00 11

UNIT 00 XX 00 xor 00 32 00 / 100% constness on 1,3 : mistake not 1,3 is unit, 2 is UNIT is entity
MANY 00 18 00 29 45 00 14 00 UNIT OBJECT UNIT > entity entity entity > constness on result : abstract_concept
     00 10 00 21 00 54 00 UNIT UNIT > entity entity
     constness on each sample > increase understanding level


MAKE many unit
