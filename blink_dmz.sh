#!/bin/sh
source /lib/functions/leds.sh

led_on bcm47xx:green:dmz
led_off bcm47xx:green:dmz

# for testing if the morse kernel module is working
# led_morse bcm47xx:green:dmz SOS
