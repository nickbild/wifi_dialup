import serial
import time
from scapy.all import sniff


SERIAL_PORT = '/dev/ttyS0'
BAUD_RATE = 9600
TARGET_MAC = "d8:3a:dd:94:20:b1" 


# Open the serial port.
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)


def packet_callback(packet):
    print(packet.summary())

    raw_bytes = bytes(packet)
    for b in raw_bytes:
        print(b)
        # Send the byte to the sound generator.
        ser.write(bytes([b]))
        time.sleep(0.0001)


def main():    
    # Sniff Wi-Fi traffic.
    sniff(iface=["mon1"], filter=f"ether src {TARGET_MAC}", prn=packet_callback, store=0) 


if __name__ == "__main__":
    main()

