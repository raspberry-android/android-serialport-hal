package vendor.raspdroid.serialport;

interface ISerialPort {
    void tx(byte data);
    byte rx();
}