#ifndef NEI_ANALYSER_HPP
#define NEI_ANALYSER_HPP

#include <nei/type.hpp>

#include <vector>

namespace nei
{
    template<int D> class entity;

    template<int Dimension>
    class analyser
    {
    public:
        analyser(nei::entity<Dimension>& entity);

        void linear_add(int value);
        void variable_add(int value);

        void process(std::vector<nei::unit_type>);

    private:
        nei::entity<Dimension>& entity_;

        std::vector<nei::unit_type> data_;
        std::vector<int> linears_;
        std::vector<int> variables_;
        std::vector<int> datas_;
        // variables;

    };
} // nei

#include "analyser.tpp"

#endif // NEI_ANALYSER_HPP
