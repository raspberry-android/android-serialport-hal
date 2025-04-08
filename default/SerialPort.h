#pragma once

#include <aidl/vendor/raspdroid/serialport/BnSerialPort.h>

namespace aidl {
namespace vendor {
namespace raspdroid {
namespace serialport {

class SerialPort : public BnSerialPort {
    ndk::ScopedAStatus tx(int8_t  data) override;
    ndk::ScopedAStatus rx(int8_t* data) override;
};

} // namespace serialport
} // namespace raspdroid
} // namespace vendor
} // namespace aidl