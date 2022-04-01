#include "Damage.h"
namespace Core {
	Damage::Damage(Role* fromCur, Role* toCur) {
		from = fromCur;
		to = toCur;
	};
}