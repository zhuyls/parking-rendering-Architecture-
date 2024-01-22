#ifndef _UUID_H_
#define _UUID_H_

#include "Omniviewpch.h"
#include <random>
#include <unordered_map>

// UUID，即通用惟一识别码，
// 产生的随机数据重复几率几乎为零，平时写程序的时候仍是会用到，

namespace OmniviewXEngine
{
    class UUID
    {
    public:
        UUID();
        UUID(uint64_t uuid);
		UUID(const UUID&) = default;
		operator uint64_t() const { return m_UUID; }
	private:
		uint64_t m_UUID;

    };
}

namespace std
{
    template<typename T> struct hash;

    template<>
    struct hash<OmniviewXEngine::UUID>
    {
        std::size_t operator()(const OmniviewXEngine::UUID& uuid) const
		{
			return (uint64_t)uuid;
		}
    };
}

#endif