#ifndef CORE_INC_FLASH
#define CORE_INC_FLASH

#include "algorithm"
#include "array"
#include "iterator"
#include "main.h"
#include "queue"

class Flash {
   public:
    Flash();
    virtual ~Flash();

    void Save();
    void Load();

   private:
    // Update This Size According to The Size Of Total Configs
	// ------------------- MUST EDIT -------------------
	static const uint8_t config_arr_size{2};
    union Config_Arr {
        struct Config {
            uint32_t led_level;
            uint32_t led_scale;
        } config;

        uint64_t config_arr[config_arr_size];
    };

	// Begin write on last page last row.
    // 0x08020000 is the next page of last page.
    // Same as (0x0803FFFF + 1 - 0x8); if using datasheet provided value
	// ------------------- MUST EDIT -------------------
    const uint32_t m_address_end{0x08040000 - 0x8};
    const uint8_t m_page_total{127};


	int32_t Write(const uint64_t*, uint8_t);
    void Read(Flash::Config_Arr*, uint8_t);
};

#endif /* CORE_INC_FLASH */
