// Ура!!!
#ifndef LIB_FIELD_H
#define LIB_FIELD_H

#include <cstddef>
#include <climits>
#include <Rule>
namespace Crypto
{
	class Field
	{
		const Rule rule;
		std::vector < bool > current;
		std::vector < bool > next;
		const size_t lenght = sizeof(unsigned short) * CHAR_BIT;
		public:
			Field(const Rule & rule, const unsigned short field):rule(rule)
			{
				current.resize(lenght);
				next.resize(lenght);
				for (size_t i = 0, j = lenght - 1; i < lenght; ++i, --j)
					current[j] = field & (1 << i);
			}
			unsigned short operator () ()
			{
				for (size_t i = 1; i < lenght - 1; ++i)
					next[i] = rule[current[i - 1] * 4 + current[i] * 2 + current[i + 1]];
				next[0] = rule[current[lenght - 1] * 4 + current[0] * 2 + current[1]];
				next[lenght - 1] = rule[current[lenght - 2] * 4 + current[lenght - 1] * 2 + current[0]];
				for (size_t i = 0; i < lenght; ++i)
					current[i] = next[i];
				unsigned short field = 0;
				for (size_t i = 0, j = lenght - 1; i < lenght; ++i, --j)
					field += current[j] * (1 << i);
				return field;
			}
	};
}
#endif