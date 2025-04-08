#include <aidl/vendor/raspdroid/serialport/ISerialPort.h>
#include <android/binder_manager.h>
#include <iostream>

using aidl::vendor::raspdroid::serialport::ISerialPort;

int main(int argc, char *argv[])
{
    const std::string instance = std::string() + ISerialPort::descriptor + "/default";
    std::shared_ptr<ISerialPort> serialport;

    serialport = ISerialPort::fromBinder(ndk::SpAIBinder(AServiceManager_checkService(instance.c_str())));
    if (!serialport) {
        std::cout << "Error requesting serialport service handler!" << std::endl;
        return 1;
    }

    /* TX */
    if (argc >= 2) {
        for (int i = 0; argv[1][i]; i++) {
            serialport->tx(argv[1][i]);
        }
    }

    /* RX */
    else {
       while(1) {
            int8_t data = 0;
            serialport->rx(&data);
            std::cout << data << std::flush;
        }
    }

    return 0;
}