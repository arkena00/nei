#ifndef NEI_BITSET_HPP
#define NEI_BITSET_HPP

//! from https://github.com/DigitalPulseSoftware/NazaraEngine/blob/master/include/Nazara/Core/Bitset.hpp

#include <limits>
#include <memory>
#include <type_traits>
#include <vector>
#include <string>

namespace nei
{
    template<typename T> constexpr std::size_t BitCount()
    {
        return 8 * sizeof(T);
    }

    class AbstractHash;

    template<typename Block = uint32_t, class Allocator = std::allocator<Block>>
    class bitset
    {
        static_assert(std::is_integral<Block>::value && std::is_unsigned<Block>::value, "Block must be a unsigned integral type");

    public:
        class Bit;
        using PointerSequence = std::pair<const void*, std::size_t>; //< Start pointer, bit offset

        bitset();
        explicit bitset(std::size_t bitCount, bool val);
        explicit bitset(const char* bits);
        bitset(const char* bits, std::size_t bitCount);
        bitset(const bitset& bitset) = default;
        explicit bitset(const std::string& bits);
        template<typename T> bitset(T value);
        bitset(bitset&& bitset) noexcept = default;
        ~bitset() noexcept = default;

        template<typename T> void AppendBits(T bits, std::size_t bitCount);

        void Clear() noexcept;
        std::size_t Count() const;
        void Flip();

        std::size_t FindFirst() const;
        std::size_t FindNext(std::size_t bit) const;

        Block GetBlock(std::size_t i) const;
        std::size_t GetBlockCount() const;
        std::size_t GetCapacity() const;
        std::size_t GetSize() const;

        void PerformsAND(const bitset& a, const bitset& b);
        void PerformsNOT(const bitset& a);
        void PerformsOR(const bitset& a, const bitset& b);
        void PerformsXOR(const bitset& a, const bitset& b);

        bool Intersects(const bitset& bitset) const;

        void Reserve(std::size_t bitCount);
        void Resize(std::size_t bitCount, bool defaultVal = false);

        void reset();
        void reset(std::size_t bit);

        void Reverse();

        void set(bool val = true);
        void set(std::size_t bit, bool val = true);
        void setBlock(std::size_t i, Block block);

        void ShiftLeft(std::size_t pos);
        void ShiftRight(std::size_t pos);

        void Swap(bitset& bitset) noexcept;

        bool Test(std::size_t bit) const;
        bool TestAll() const;
        bool TestAny() const;
        bool TestNone() const;

        template<typename T> T To() const;
        std::string ToString() const;

        void UnboundedReset(std::size_t bit);
        void unbounded_set(std::size_t bit, bool val = true);
        bool UnboundedTest(std::size_t bit) const;

        PointerSequence Write(const void* ptr, std::size_t bitCount);
        PointerSequence Write(const PointerSequence& sequence, std::size_t bitCount);

        Bit operator[](std::size_t index);
        bool operator[](std::size_t index) const;

        bitset operator~() const;

        bitset& operator=(const bitset& bitset) = default;
        bitset& operator=(const std::string& bits);
        template<typename T> bitset& operator=(T value);
        bitset& operator=(bitset&& bitset) noexcept = default;

        bitset operator<<(std::size_t pos) const;
        bitset& operator<<=(std::size_t pos);

        bitset operator>>(std::size_t pos) const;
        bitset& operator>>=(std::size_t pos);

        bitset& operator&=(const bitset& bitset);
        bitset& operator|=(const bitset& bitset);
        bitset& operator^=(const bitset& bitset);

        static constexpr Block fullBitMask = std::numeric_limits<Block>::max();
        static constexpr std::size_t bitsPerBlock = BitCount<Block>();
        static constexpr std::size_t npos = std::numeric_limits<std::size_t>::max();

        static bitset FromPointer(const void* ptr, std::size_t bitCount, PointerSequence* sequence = nullptr);

    private:
        std::size_t FindFirstFrom(std::size_t blockIndex) const;
        Block GetLastBlockMask() const;
        void ResetExtraBits();

        static std::size_t ComputeBlockCount(std::size_t bitCount);
        static std::size_t GetBitIndex(std::size_t bit);
        static std::size_t GetBlockIndex(std::size_t bit);

        std::vector<Block, Allocator> m_blocks;
        std::size_t m_bitCount;
    };

    template<typename Block, class Allocator>
    class nei::bitset<Block, Allocator>::Bit
    {
        friend nei::bitset<Block, Allocator>;

    public:
        Bit(const Bit& bit) = default;

        Bit& Flip();
        Bit& reset();
        Bit& set(bool val = true);
        bool Test() const;

        template<bool BadCall = true>
        void* operator&() const;

        explicit operator bool() const;
        Bit& operator=(bool val);
        Bit& operator=(const Bit& bit);

        Bit& operator|=(bool val);
        Bit& operator&=(bool val);
        Bit& operator^=(bool val);
        Bit& operator-=(bool val);

    private:
        Bit(Block& block, Block mask) :
        m_block(block),
        m_mask(mask)
        {
        }

        Block& m_block;
        Block m_mask;
    };

    template<typename Block, class Allocator>
    std::ostream& operator<<(std::ostream& out, const nei::bitset<Block, Allocator>& bitset);

    template<typename Block, class Allocator>
    bool operator==(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    bool operator!=(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    bool operator<(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    bool operator<=(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    bool operator>(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    bool operator>=(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    nei::bitset<Block, Allocator> operator&(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    nei::bitset<Block, Allocator> operator|(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);

    template<typename Block, class Allocator>
    nei::bitset<Block, Allocator> operator^(const nei::bitset<Block, Allocator>& lhs, const nei::bitset<Block, Allocator>& rhs);
}

namespace std
{
    template<typename Block, class Allocator>
    void swap(nei::bitset<Block, Allocator>& lhs, nei::bitset<Block, Allocator>& rhs) noexcept;
}

#include "bitset.tpp"


#endif // NEI_BITSET_HPP
