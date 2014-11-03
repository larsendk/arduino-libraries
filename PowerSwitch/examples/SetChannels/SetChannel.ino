#include "Arduino.h"
#include "SPI.h"
#include "Streaming.h"
#include "PowerSwitch.h"

#define LOOP_DELAY 1000
#define CS_PIN  49
#define IN_PIN  48
#define DEVICE_COUNT  2

// If the IN_PIN is permanently tied to ground instead of an arduino
// pin you can instantiate it like this instead:
// PowerSwitch power_switch = PowerSwitch(CS_PIN);
PowerSwitch power_switch = PowerSwitch(CS_PIN, IN_PIN);

// Setting spi_reset to true causes the SPI parameters to be reset
// every time before a command is issued over SPI. It could cause
// slight delays and should only be used when you are also
// communicating with other SPI devices with different SPI parameters
bool spi_reset = false;
int channel_count;
uint32_t channels;
uint32_t bit;

void setup()
{
  // Setup serial communications
  Serial.begin(115200);

  power_switch.init(DEVICE_COUNT,spi_reset);
  channel_count = power_switch.getChannelCount();
}

void loop()
{
  for (int channel = -1; channel < channel_count; channel++)
  {
    if (0 <= channel)
    {
      bit = 1;
      bit = bit << channel;
      channels = channels | bit;
    }
    else
    {
      channels = 0;
    }
    power_switch.setChannels(channels);
    Serial << "channels = " << _BIN(channels) << endl;
    delay(LOOP_DELAY);
  }
}