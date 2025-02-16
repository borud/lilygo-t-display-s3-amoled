#include <stdio.h>
#include <stdint.h>
#include "rm67162.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "pins_config.h"
#include "esp_timer.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "lvgl.h"

extern "C" void app_main(void)
{
	gpio_config_t io_conf = {
		.pin_bit_mask = (1ULL << PIN_LED), // Bit mask for the pin
		.mode = GPIO_MODE_OUTPUT,
		.pull_up_en = GPIO_PULLUP_DISABLE,
		.pull_down_en = GPIO_PULLDOWN_DISABLE,
		.intr_type = GPIO_INTR_DISABLE};
	gpio_config(&io_conf);

	gpio_set_level(PIN_LED, 1);

	rm67162_init(); // amoled lcd initialization
	lcd_setRotation(3);

	lv_init();

	lcd_fill(0, 0, 536, 240, 0x1111);
}
