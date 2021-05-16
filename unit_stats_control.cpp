#include "config_new.h"
#include "syslib.h"

void __stdcall human_stats_update(int32_t unit)
{
	bool fighter = (*(uint8_t*)(unit + 76) & 4) == 0;
	bool female = *(uint16_t*)(unit + 14) == 34 || *(uint16_t*)(unit + 14) == 36;

	bool is_warrior = !female && fighter;
	bool is_amazon = female && fighter;
	bool is_mage = !female && !fighter;
	bool is_witch = female && !fighter;

	CharacterMagicResists* resist_limits = nullptr;
	if (is_warrior) resist_limits = &Config::warrior_max_resists;
	if (is_amazon) resist_limits = &Config::amazon_max_resists;
	if (is_mage) resist_limits = &Config::mage_max_resists;
	if (is_witch) resist_limits = &Config::witch_max_resists;

	for (int32_t sphere = 1; sphere <= 5; ++sphere) {
		int16_t& resist = *(int16_t*)(unit + 194 + 2 * sphere);
		int16_t max_resist = resist_limits ? resist_limits->Sphere[sphere-1] : 100;
		if (resist > max_resist) resist = max_resist;
		if (resist > 100) resist = 100;
		if (resist < 0) resist = 0;
	}
}

int __declspec(naked) imp_human_stats_update()
{ // 53206C
	__asm {
		push    dword ptr [ebp-0x28]
		call	human_stats_update

		mov edx, 0x532250
		jmp edx
	}
}