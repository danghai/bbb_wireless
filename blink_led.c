#include "type.h"

#define LED_MASK (0xF <<21)
#define LED_PATTERN (0xA << 21)

static void init_led (void)
{
	// Enable the GPIO module - CM_PER_GPI01_CLKCTRL
	*(volatile uint32_t *)(0x44e00000 + 0xAC) = (0x1 << 18) | (0x2 <<0);

	// Enable output - GPIO1_OE
	*(volatile uint32_t *)(0x4804C000 + 0x134) &= ~LED_MASK;
}
void __attribute__((optimize("O0"))) delay(uint32_t number)
{
	uint32_t counter = 0;
	for(;counter < number; ++counter)
	{
		;
	}
}
int main(void)
{
	init_led();
	for(;;)
	{
		*(volatile uint32_t *)(0x4804C000 + 0x13C) |= LED_PATTERN;
		delay(500000);

		*(volatile uint32_t *)(0x4804C000 + 0x13C) &= ~LED_PATTERN;
		delay(500000);
	}
}
