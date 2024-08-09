#ifndef INFRARED_SERVICE_H
#define INFRARED_SERVICE_H

#include <vector>
#include <FastLED.h>
#include <Models/RemoteCommand.h>
#include <Contexts/GlobalContext.h>
#include <Utils/MakeHexUtils.h>

#define IR_TX_PIN  44 // Builtin
#define LED_PIN    21 // Builtin
#define NUM_LEDS   1

using namespace models;
using namespace contexts;
using namespace utils;

namespace services {

    class InfraredService {
    public:
        InfraredService();
        void begin();
        void sendRemoteCommand(RemoteCommand command, const char* protocolString);
    private:
        GlobalContext& context = GlobalContext::getInstance();
        CRGB leds[NUM_LEDS]; // Déclaration LED pour la builtin
    };

}
#endif