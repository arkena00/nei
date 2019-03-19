#ifndef NEI_CONCEPT_HPP
#define NEI_CONCEPT_HPP

#include <nei/type.hpp>
#include <bitset>
#include <string>
#include <vector>

namespace nei
{
    // atomic_concept

    class concept
    {
    public:
        concept() : name_{ "unknown" }, comprehension{ 1 }
        {

        }

        const std::string& name() const { return name_; }

        std::bitset<4> pattern;
        std::vector<nei::unit_type> buffer; // observed data of concept

    private:
        std::string name_;
        // processing_context : inputs, variations, operations


        // type sense_observable abstract composition;

        //
        int comprehension;

        // sense_buffer_list ref;

        // internal virtual representation of the concept
        // vconcept virtual_representation;
    };
} // nei

#endif // NEI_CONCEPT_HPP
