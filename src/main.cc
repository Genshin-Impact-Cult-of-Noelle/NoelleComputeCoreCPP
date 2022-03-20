#include <node_api.h>;
#define ЙЋга public;
namespace Core {
	class Attr {
	public:
		enum Element
		{
			None = 0x0010,
			Water,
			Fire,
			Ice,
			Electric,
			Geo,
			Wind,
			Grass,
			Physics,
		};
		enum Type
		{
			None = 0x0001,
			Atk,
			Def,
			Health,
			CritRate,
			CritDMG,
			ElementDMG,
			ElementDef,
		};

		Attr() {

		}
		Attr& Add(Attr& other) {
			base += other.base, rate += other.rate, extra += other.extra;
			return *this;
		}
		double Compute() {
			return base * (1 + rate) + extra;
		}
	private:
		double base = 0;
		double rate = 0;
		double extra = 0;
	};

	class Damage {
	public:
		uint16_t Type = 0;
		double Last() {
			
		}
	private:
		Damage* next = nullptr;
		Damage Push(Damage& otherDmg) {
			if (next != nullptr) {
				return next->Push(otherDmg);
			}
			else {
				next = &otherDmg;
				return *this;
			}
		}
	};



	napi_value Method(napi_env env, napi_callback_info args) {
		napi_value greeting;
		napi_status status;

		status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
		if (status != napi_ok) return nullptr;
		return greeting;
	}

	napi_value init(napi_env env, napi_value exports) {
		napi_status status;
		napi_value fn;
		napi_callback fns = Method;
		status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
		if (status != napi_ok) return nullptr;
		status = napi_set_named_property(env, exports, "hello", fn);
		if (status != napi_ok) return nullptr;
		return exports;
	}

	NAPI_MODULE(NODE_GYP_MODULE_NAME, init)


}