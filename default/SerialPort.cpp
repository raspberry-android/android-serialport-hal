#include "SerialPort.h"
#include <fcntl.h>

namespace aidl {
namespace vendor {
namespace raspdroid {
namespace serialport {

static const char *dev_path = "/dev/ttyAMA2";

ndk::ScopedAStatus SerialPort::tx(int8_t data) {
    int fd = 0;

    fd = open(dev_path, O_WRONLY);

    if (fd == 0) {
        return ndk::ScopedAStatus::ok();
    }

    write(fd, &data, 1);

    close(fd);

    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus SerialPort::rx(int8_t* data) {
    int fd = 0;

    fd = open(dev_path, O_RDONLY);

    if (fd == 0) {
        return ndk::ScopedAStatus::ok();
    }

    read(fd, data, 1);

    return ndk::ScopedAStatus::ok();
}

} // namespace serialport
} // namespace raspdroid
} // namespace vendor
} // name space aidl