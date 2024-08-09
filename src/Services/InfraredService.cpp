#include <IRremote.hpp> // defined here to avoid conflicts
#include "InfraredService.h"


namespace services {

InfraredService::InfraredService() {}

void InfraredService::begin() {
    IrSender.begin(context.getIrTxPin());
}

void InfraredService::sendRemoteCommand(RemoteCommand command, const char* protocolString) {
    int frequency = 38; // Default frequency, passed by reference to encodeRemoteCommand
    std::vector<float> sequence = encodeRemoteCommand(command, protocolString, frequency);
    
    // Convert the sequence to uint16_t format as required by sendRaw
    uint16_t raw[sequence.size()];
    for (size_t i = 0; i < sequence.size(); ++i) {
        raw[i] = static_cast<uint16_t>(sequence[i]);
    }

    // Send the raw generated sequence with the correct frequency
    IrSender.sendRaw(raw, sequence.size(), frequency);
}

}