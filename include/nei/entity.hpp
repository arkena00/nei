#ifndef NEI_ENTITY_HPP
#define NEI_ENTITY_HPP

#include <nei/environment.hpp>

namespace nei
{
    class entity
    {
        nei::environment& environment_; // 1D

        //entity_sense sense; // entity_sense : view_sense, sound_sense // neya.lookat() // inherit from view_sense
        //ability[];

        // abstract
        //concept[];
    };
} // nei

/*class atomic_ability
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




concept_compute_node
{
    vector<bool> result;
    vector<compute_node>
}
A f B, A f C
  D  f  E
     G

class environment;
00 00 00 11 00 00 00 00 11 11 00 11

UNIT 00 XX 00 xor 00 32 00 / 100% constness on 1,3 : mistake not 1,3 is unit, 2 is UNIT is entity
MANY 00 18 00 29 45 00 14 00 UNIT OBJECT UNIT > entity entity entity > constness on result : abstract_concept
     00 10 00 21 00 54 00 UNIT UNIT > entity entity
     constness on each sample > increase understanding level


MAKE many unit




look_at (x, range = 1)
constness on sense param, range = 1

store algo to find UNIT, reproduce algo to find other UNIT
store results in cumputation buffers (operation on buffers)
> algo is : item && item NOT EQUAL

look_at(y, range);
explain : item && item[x] NOT EQUAL > item[x] is unit



A B A
A B B A

C1 : A & B = false
C2 : A & A = true
C3 : C1 & C2 = false

true
false true > false
false false true > false false


A A A
C1 : A & A2 = true
C2 : A & A3 = true
C3 : C1 & C2 = true

*/

#endif // NEI_ENTITY_HPP
