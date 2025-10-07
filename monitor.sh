sudo ip link set mon1 down 2>/dev/null || true
sudo iw dev mon1 del 2>/dev/null || true

sudo iw phy phy1 interface add mon1 type monitor
sudo iw dev mon1 set monitor fcsfail otherbss
sudo ip link set mon1 up
sudo ip link set mon1 promisc on
sudo ip link set wlan1 down

# 5GHz - 149
sudo iw dev mon1 set channel 3

# sudo tcpdump -i mon1 -s 0
# sudo tcpdump -i mon1 -s 0 ether host d8:3a:dd:94:20:b1
